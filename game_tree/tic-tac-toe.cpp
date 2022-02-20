#include "tic-tac-toe.h"
#include "string.h"

vector<vector<cell>> over_status_array = {
    // 行
    {make_pair(0, 0), make_pair(0, 1), make_pair(0, 2)},
    {make_pair(1, 0), make_pair(1, 1), make_pair(1, 2)},
    {make_pair(2, 0), make_pair(2, 1), make_pair(2, 2)},
    // 列
    {make_pair(0, 0), make_pair(1, 0), make_pair(2, 0)},
    {make_pair(0, 1), make_pair(1, 1), make_pair(2, 1)},
    {make_pair(0, 2), make_pair(1, 2), make_pair(2, 2)},
    // 斜
    {make_pair(0, 0), make_pair(1, 1), make_pair(2, 2)},
    {make_pair(0, 2), make_pair(1, 1), make_pair(2, 0)},
};

bool cell_is_full(char scope[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (scope[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

vector<cell> get_occupied_cell(char scope[3][3], char player)
{
    vector<cell> occupied_cell;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (scope[i][j] == player)
            {
                occupied_cell.push_back(make_pair(i, j));
            }
        }
    }
    return occupied_cell;
}

bool check_over(char scope[3][3], char player)
{
    // 检查有没有人赢了
    vector<cell> occupied_cell = get_occupied_cell(scope, player);

    for (vector<cell> over_status : over_status_array)
    {
        bool flag = true;
        for (int i = 0; i < over_status.size(); i++)
        {
            if (over_status[i] != occupied_cell[i])
            {
                flag = false;
            }
        }
        if (flag == true)
        {
            return true;
        }
    }
    // 检查是否所有位置都满了
    if (cell_is_full(scope))
    {
        return true;
    }

    return false;
}

bool is_token(char scope[3][3], int row, int col)
{
    if (scope[row][col] == PLAYER || scope[row][col] == AI_PLAYER)
    {
        return true;
    }
    return false;
}

int get_score(char scope[3][3])
{
    vector<cell> AI_occupied_cell = get_occupied_cell(scope, AI_PLAYER);
    vector<cell> player_occupied_cell = get_occupied_cell(scope, PLAYER);

    for (vector<cell> over_status : over_status_array)
    {
        bool flag = true;
        for (int i = 0; i < over_status.size(); i++)
        {
            if (over_status[i] != AI_occupied_cell[i])
            {
                flag = false;
            }
        }
        if (flag == true)
        {
            return WIN;
        }
    }

    for (vector<cell> over_status : over_status_array)
    {
        bool flag = true;
        for (int i = 0; i < over_status.size(); i++)
        {
            if (over_status[i] != player_occupied_cell[i])
            {
                flag = false;
            }
        }
        if (flag == true)
        {
            return LOSS;
        }
    }

    if (cell_is_full(scope))
    {
        return DRAW;
    }
    return DRAW;
}

vector<cell> get_available_cell(char scope[3][3])
{
    vector<cell> occupied_cell;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (scope[i][j] != '-')
            {
                occupied_cell.push_back(make_pair(i, j));
            }
        }
    }
    return occupied_cell;
}

board::board()
{
    memset(scope, EMPTY_SPACE, 9);
}

pair<int, pair<int, int>> board::AI_Play(AI_Node current, char player, AI_Node father, int depth)
{
    if (check_over(current.dynamic_scope, player))
    {
        return make_pair(get_score(current.dynamic_scope), make_pair(-1, -1));
    }
    if (player == PLAYER) // min层
    {

        vector<cell> available_cell = get_available_cell(current.dynamic_scope);

        for (cell c : available_cell)
        {
            char new_scope[3][3];
            memcpy(new_scope, current.dynamic_scope, sizeof(current.dynamic_scope));
            int next_row = c.first;
            int next_col = c.second;
            new_scope[next_row][next_col] = PLAYER;
            AI_Node next_status(new_scope);
            int score = AI_Play(next_status, AI_PLAYER, current, depth + 1).first;
            int preScore = score + depth * 10;

            if (preScore > current.beta)
            {
                current.beta = preScore;
                current.next = make_pair(next_row, next_col);
            }
            // 剪枝
            if (current.beta < father.alpha)
            {
                break;
            }
        }
        return make_pair(current.beta, current.next);
    }
    else // max层
    {
        vector<cell> available_cell = get_available_cell(current.dynamic_scope);

        for (cell c : available_cell)
        {
            char new_scope[3][3];
            memcpy(new_scope, current.dynamic_scope, sizeof(current.dynamic_scope));
            int next_row = c.first;
            int next_col = c.second;
            new_scope[next_row][next_col] = AI_PLAYER;
            AI_Node next_status(new_scope);
            int score = AI_Play(next_status, PLAYER, current, depth + 1).first;
            int preScore = score - depth * 10;

            if (preScore > current.alpha)
            {
                current.alpha = preScore;
                current.next = make_pair(next_row, next_col);
            }
            // 剪枝
            if (current.alpha > father.beta)
            {
                break;
            }
        }
        return make_pair(current.alpha, current.next);
    }
}

void board::begin()
{
    cout << "begin" << endl;
    cout << "Player = X\t AI Computer = O" << endl
         << endl;
    cout << "first:X" << endl;
    char current_player = PLAYER;
    while (!check_over(scope, current_player))
    {
        if (current_player == PLAYER)
        {
            int row, col;
            cout << "Row play: ";
            cin >> row;
            cout << "Col play: ";
            cin >> col;
            if (is_token(scope, row, col))
            {
                cout << "cell haved been token , please select cell again：" << endl;
                continue;
            }
            cout << endl
                 << endl;
            scope[row][col] = PLAYER;

            current_player = AI_PLAYER;
        }
        else
        {
            AI_Node ap(scope);
            AI_Play(ap, AI_PLAYER, ap, 1);

            current_player = PLAYER;
        }
    }
}

AI_Node::AI_Node(char scope[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dynamic_scope[i][j] = scope[i][j];
        }
    }

    // alpha = MIN;
    // beta = MAX;
    score = 0;
}