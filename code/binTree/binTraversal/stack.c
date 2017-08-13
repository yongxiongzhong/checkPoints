#include "binTree.h"
#include "stack.h"

//初始化栈
Stack initStack(){
	Stack a = malloc(sizeof(struct List));
	a->point = -1;//初始化指向-1，因为数组是0下标开始
	return a;
}

//压栈
int push(Stack stack, struct Node *val){
	if(stack->point < MAX_LEN){
		stack->list[++stack->point] = val;
		return 1;
	}
	return -1;
}

//出栈
struct Node * pop(Stack stack){
	if(!isEmpty(stack)){
		struct Node *val =  stack->list[stack->point];
		stack->point--;
		return val;
	}
}

struct Node * top(Stack stack){
	if(!isEmpty(stack)){
		return stack->list[stack->point];
	}
}

//判断栈是否为空
int isEmpty(Stack stack){
	return stack->point >= 0 ? 0 : 1;
}
