#include "tree.h"
#include "trainList.h"

// 参考 ： https://github.com/jiafanxue/Coding/tree/master/MachineLearning/decision_tree/ID3
using namespace std;

// 递归构建树
node *generateTree(node *root)
{
    if (root->checkDecision()){ // 如果决策结果唯一
        return root;
    }else{  

    }
}

int main(int, char **)
{
    trainList trainlist("D:\\c-\\ID3\\in.txt");
    node *rootTree = new node(&trainlist);
    node *finalTree = generateTree(rootTree);


}
