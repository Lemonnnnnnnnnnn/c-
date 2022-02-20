#include "basic.h"

#define MAX 99999999
#define MIN -99999999

Node::Node(int val)
{
    value = val;
    alpha = MIN;
    beta = MAX;
}

basicAlgorithm::basicAlgorithm()
{
    Node *root = new Node(MIN);
    for (int i = 0; i < 3; i++)
    {
        Node *newNode = new Node(MAX);
        root->childs.push_back(newNode);
    }

    root->childs[0]->childs.push_back(new Node(6));
    root->childs[0]->childs.push_back(new Node(8));
    root->childs[1]->childs.push_back(new Node(4));
    root->childs[1]->childs.push_back(new Node(-1));
    root->childs[1]->childs.push_back(new Node(3));
    root->childs[2]->childs.push_back(new Node(10));
    root->childs[2]->childs.push_back(new Node(-7));

    rootTree = root;
}

int basicAlgorithm::process(Node *tr, Node *father, int high)
{
    if (tr->childs.empty())
    {
        return tr->value;
    }
    if (high % 2 == 1)
    { // MAX层

        for (Node *n : tr->childs)
        {
            int val = process(n, tr, high + 1);
            if (tr->alpha < val)
            {
                tr->alpha = val;
            }
            if(tr->alpha > father->beta){
                break;
            }
        }
        return tr->alpha;
    }
    else
    { // MIN层
        for (Node *n : tr->childs)
        {
            int val = process(n, tr, high + 1);
            // beta为子节点的最小值
            if (tr->beta > val)
            {
                tr->beta = val;
            }
            /*
            当min层（对手）找到一个最小值（deta）时，再找其他子节点只会优先选择更小的值
            这里以第一层第二层来模拟

            第一层是max，站在max的角度看比赛
            如果子节点的deta已经比第一层的alpha要小时（其他子节点只会更小），第一层一定不会选择当前子节点作为下一步（第一层的alpha为已经模拟的最大分数），后续节点可以被剪枝

            */
            if (tr->beta < father->alpha)
            {
                break;
            }
        }
        return tr->beta;
    }
}