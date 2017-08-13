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
void PrePrint(BinTree);//前序遍历
void InPrint(BinTree);//中序遍历
void PostPrint(BinTree);//后序遍历
void PrePrintWithStack(BinTree);//非递归前序遍历
void InPrintWithStack(BinTree);//非递归中序遍历
void PostPrintWithStack(BinTree);//非递归后序遍历
