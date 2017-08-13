#include "binTree.h"
void main(){
        int a[] = {5, 3, 7, 1, 4, 6, 8};
        BinTree BT = InitBinTree(a, 7);
        PrePrint(BT);
        printf("\n");
        PrePrintWithStack(BT);
        printf("\n");
        InPrint(BT);
        printf("\n");
        InPrintWithStack(BT);
        printf("\n");
        PostPrint(BT);
        printf("\n");
        PostPrintWithStack(BT);
}
