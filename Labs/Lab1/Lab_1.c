#include <stdio.h>

struct fancyArray{
	int len;
	float ave;
	short arr[50];
};

void printFA(struct fancyArray aa){
	printf("Print with function\n");
	printf(" len: %3d\n", aa.len);
	printf(" ave: %5.2f\n", aa.ave);
	printf(" arr: ");
	for(int i=0; i<aa.len; i++)
		printf("%3d", aa.arr[i]);
	printf("\n");
}

void calcAveFA(struct fancyArray *aPtr){
	aPtr->ave = 0.0f;
	for(int i=0; i<aPtr->len; i++)
		aPtr->ave += aPtr->arr[i];
	aPtr->ave /= aPtr->len;
}

void incrFA(struct fancyArray *aPtr){
	for(int i=0; i<aPtr->len; i++)
		(aPtr->arr[i])++;
	calcAveFA(aPtr);
}

void add42(struct fancyArray *aPtr){
	aPtr->arr[aPtr->len++] = 42;
	calcAveFA(aPtr);
}

int main(){
	struct fancyArray a;

	//initialize
	a.len = 10;
	a.ave = 0.0f;
	for(int i=0; i<a.len; i++)
		a.arr[i] = i*i + 1;
	//calculate the average
	calcAveFA(&a);

	printFA(a);
	add42(&a);
	printFA(a);
}
