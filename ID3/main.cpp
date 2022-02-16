#include <iostream>
#include <fstream>
#include "tree.h"
#include "trainList.h"
#include <vector>

// 参考 ： https://github.com/jiafanxue/Coding/tree/master/MachineLearning/decision_tree/ID3
using namespace std;

// 递归构建树
node *generateTree(node *root)
{
    if (root->checkDecision()){ // 如果决策结果唯一
        return root;
    }else{// 如果决策结果不唯一

    }
}

int main(int, char **)
{
    trainList trainlist("D:\\c-\\ID3\\in.txt");
    node *rootTree = new node(trainlist.data);
    generateTree(rootTree);

    // tree tr;
    // while(!tr.checkLeftNode()){

    // }
}
