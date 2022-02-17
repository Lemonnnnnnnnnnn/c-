#include "trainList.h"
#include "node.h"

// 参考 ： https://github.com/jiafanxue/Coding/tree/master/MachineLearning/decision_tree/ID3
using namespace std;

// 递归构建树
node *generateTree(node *root)
{
    if (root->checkDecision())
    { // 如果决策结果唯一
        return root;
    }
    else
    {
        // 获取最大信息增益的属性
        root->find_max_info();
        // 用最大信息增益的属性进行分类，生成不同的分支
        LIST_MAP listMap = root->classify(root->attribute); // 子属性分类map
        LIST_MAP::iterator it = listMap.begin();
        LIST_MAP::iterator it_end = listMap.end();

        while (it != it_end)
        {
            DATA_LIST sonList = it->second;

            // 去除当前的属性列
            vector<string> current_attribute = root->datas->attributes;
            vector<string> new_attribute;
            for (string attribute : current_attribute)
            {
                if (attribute != root->attribute)
                {
                    new_attribute.push_back(attribute);
                }
            }
            trainList newTrainList(sonList, new_attribute);
            node *newNode = new node(&newTrainList);
            root->childs.push_back(newNode);
            generateTree(newNode);
            it++;
        }
    }
}

void print(node *p)
{

    if (p->decision != "not_over")
    {
        cout << p->decision << endl;
    }
    else
    {
        cout << p->attribute << endl;
        for (node *child : p->childs)
        {
            print(child);
        }
    }
}

int main(int, char **)
{
    trainList trainlist("D:\\c-\\ID3\\in.txt");
    node *rootTree = new node(&trainlist);
    generateTree(rootTree);

    print(rootTree);
}
