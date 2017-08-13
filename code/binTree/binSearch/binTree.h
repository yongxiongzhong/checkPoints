#include <stdio.h>
#include <stdlib.h>

struct Node{
        int Data;//键值
        struct Node *Left;//指向左子树
        struct Node *Right;//指向右子树
};

typedef struct Node *BinTree;

BinTree InitBinTree(int a[], int len);//将数组初始化成二叉搜索树
BinTree Insert(BinTree Root, int Data);//二叉搜索树的插入单个节点
int Find(BinTree, int X);//查找一个元素是否存在
int FindMax(BinTree);//找出最大值
