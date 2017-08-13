#include "binTree.h"
void main(){
	int a[] = {5, 3, 7, 1, 4, 6, 8};
	BinTree BT = InitBinTree(a, 7);
	int val = Find(BT, 1);
	printf("\nfind result is :%d", val);
	int max = FindMax(BT);
	printf("\nmax is :%d", max);
}
