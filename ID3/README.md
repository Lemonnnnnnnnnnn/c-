### 公式

信息增益：
![信息增益](https://www.zhihu.com/equation?tex=+infoGain%28D%7CA%29%3DEntropy%28D%29-Entropy%28D%7CA%29+%5C%5C)
信息量(熵)：
![熵](https://www.zhihu.com/equation?tex=Entropy+%3D+-%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%7Bp%28x_i%29%2Alog_2p%28x_i%29%7D%5C%5C)
条件熵：
![条件熵](https://www.zhihu.com/equation?tex=Entropy%28Y%7CX%29%3D%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%7Bp%28x_i%29Entropy%28Y%7Cx_i%29%7D+%5C%5C)

选择信息增益最大的分类作为根节点，并向下分类，当某一分支只剩下一种结果时，到达叶子节点，分类结束。

### 伪代码：

    决策树 Tree;
    while(!每个叶子节点的决策结果唯一){
        取决策结果计算信息熵Entropy；
        最小信息增益 = 99999；
        for(遍历其他分类，如天气){
            加权和= 0；
            for(遍历每个分类下的结果，如晴、雨、云){
                条件熵 = 当前的信息熵 * 当前结果占比
                加权和+= 条件熵；
            }
            信息增益 = Entropy - 加权和；
            更新最小信息增益信息；
        }
        Tree.push(最小信息增益分类)；
    }


