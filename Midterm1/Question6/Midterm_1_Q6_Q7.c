#include <stdio.h>

void print_divisors(int a){
	int count = 0;
	for(int i = 2; i < a; i++){
		if(a % i == 0){
			printf("%d\n", i);
			count++;
		}
	}
	if(count == 0) printf("Prime number!");
}

int main(){
	int num;
	printf("Enter a positive integer: ");
	scanf("%d", &num);
	print_divisors(num);
}
