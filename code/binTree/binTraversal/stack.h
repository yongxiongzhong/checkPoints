#define MAX_LEN 100
//定义栈结构体
struct List{
        struct Node  *list[MAX_LEN];//二叉树节点组成的数组
        int point;//指向当前元素
};
typedef struct List *Stack;

Stack initStack();
int push(Stack stack, struct Node *val);
struct Node * pop(Stack stack);
struct Node * top(Stack stack);
int isEmpty(Stack stack);
