### 参考
https://blog.csdn.net/u013351484/article/details/50789521
https://github.com/GeorgeSeif/Tic-Tac-Toe-AI
https://blog.csdn.net/qq_45931661/article/details/121531371
https://blog.csdn.net/cccccchao/article/details/89377513

### 井字棋估值函数的两种思路
1.  轮到某人时，将盘上剩余位置全部填满其棋子，看有多少种胜利的结果，胜率概率作为估值
2.  最后一步胜利或失败获得固定的分数，
    胜利情况：分数为0~1000，胜利为1000，估值函数为$preScore = score - depth * 10$；
    失败情况：分数为0~-1000，失败为-1000 ，估值函数为$preScore = score + depth * 10$；
    对估值函数的理解：步数越多，越倾向平局，胜利和失败的概率越低
此处选取思路二