#include "binTree.h"
#include "stack.h"

//初始化一棵二叉树
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

//插入一棵节点，使得二叉树为搜索树
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

//递归前序遍历二叉树
void PrePrint(BinTree Root){
	if(Root){
		printf("%d", Root->Data);
		PrePrint(Root->Left);
		PrePrint(Root->Right);
	}
}

//非递归前序遍历二叉树
void PrePrintWithStack(BinTree Root){
    BinTree T = Root;
    Stack S = initStack();
    while(T || !isEmpty(S)){
        while(T){
            push(S, T); 
            printf("%d", T->Data);
            T = T->Left;
        }       
        if(!isEmpty(S)){
            T = pop(S); 
            T = T->Right; 
        }       
    }   
}

//递归中序遍历二叉树
void InPrint(BinTree Root){
	if(Root){
		InPrint(Root->Left);
		printf("%d", Root->Data);
		InPrint(Root->Right);
	}
}

//非递归中序遍历二叉树
void InPrintWithStack(BinTree Root){
	BinTree T = Root;
	Stack S = initStack();
	while(T || !isEmpty(S)){
		while(T){
			push(S, T);
			T = T->Left;
		}
		if(!isEmpty(S)){
			T = pop(S);
			printf("%d", T->Data);
			T = T->Right;
		}
	}
}

//递归后序遍历二叉树
void PostPrint(BinTree Root){
	if(Root){
		PostPrint(Root->Left);
		PostPrint(Root->Right);
		printf("%d", Root->Data);
	}

}

//非递归后序遍历二叉树
void PostPrintWithStack(BinTree root){
    Stack s = initStack();
    BinTree cur;		//当前结点 
    BinTree pre;                //前一次访问的结点 
    push(s, root);		//先把根节点入栈
    while(!isEmpty(s))
    {
        cur=top(s);

	//可以访问的条件，左右子树都为空了，这时候可以访问
	//如果上一次访问的结果是当前节点的左子树或者右子树，说明就没有跨过根节点，证明可以访问
	//否则的话不能访问，要先访问根节点的右子树
        if((cur->Left==NULL&&cur->Right==NULL)||
           (pre!=NULL&&(pre==cur->Left||pre==cur->Right)))
        {
            	printf("%d", cur->Data);
		pop(s);
		pre=cur; 
        }
        else
        {
            //按照左孩子先入栈，右孩子后入栈，这样就能保证先访问左子树，后访问右子树。
            if(cur->Right!=NULL)
                push(s, cur->Right);
            if(cur->Left!=NULL)    
                push(s, cur->Left);
        }
    }    
}
