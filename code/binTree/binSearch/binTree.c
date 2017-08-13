#include "binTree.h"
BinTree InitBinTree(int a[], int len){

	//首先创建根节点并存放第一个元素
	BinTree Root = malloc(sizeof(struct Node));
	Root->Data = a[0];

	//其他元素依次插入
	int i;
	for(i=1; i<len; i++){
		Insert(Root, a[i]);
	}

	return Root;
}

BinTree Insert(BinTree Root, int Data){

	//生成换一个二叉树节点
	BinTree BinNode = malloc(sizeof(struct Node));
        BinNode->Data = Data;

	//如果当前元素小于根节点元素，则节点需要放在左边，注意这里需要考虑递归的往左边移动
	if(Data < Root->Data){
		if(Root->Left == NULL){
			Root->Left = BinNode;
		}else{
			//没有插入位置的情况下递归插入
			Insert(Root->Left, Data);
		}
	}else{
		if(Root->Right == NULL){
			Root->Right = BinNode;
		}else{
			Insert(Root->Right, Data);
		}
	}
	
	return Root;
	
}

int Find(BinTree BT, int X){
	if(BT == NULL){
		return -1;	
	}
	
	if(X > BT->Data){
		printf("%d > %d \n", X, BT->Data);
		Find(BT->Right, X);
	}else if(X < BT->Data){
		printf("%d < %d \n", X, BT->Data);
		Find(BT->Left, X);
	}else{
		printf("%d == %d", X, BT->Data);
		return BT->Data;
	}
}

int FindMax(BinTree BT){
	if(BT->Right == NULL){
		return BT->Data;
	}

	return FindMax(BT->Right);
}
