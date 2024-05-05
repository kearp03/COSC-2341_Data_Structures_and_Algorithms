//Hash table

#include <stdio.h>
#include <stdlib.h>
#define M 17

int hash[M];

int h1(int k, int m){
	return k%m;
}

int h2(int k){
	return k%17;
}

void print_table(){
	for(int i=0; i<M ;i++)
		printf("%2d ", hash[i]);
	printf("\n");
}

void initialize_table(){
	for(int i=0; i<M ;i++)
		hash[i] = -1;
}

int insert(int k, int *count){
	int i = h2(k);
	if (hash[i] == -1){
		hash[i] = k;
		printf("no collision\n");
		return i;
	}
	else{
		printf("collision for hash value %d\n", i);
		(*count)++;
		i++;
		while(hash[i] != -1){
			i++;
			if (i==M) i=0;
		}
		hash[i] = k;
		return i;
	}
}

int main(){
	int collCount = 0;
	initialize_table();
	printf("This is the initial table:\n");
	print_table();
	printf("\nInsertions start:\n");
	insert(30, &collCount);     print_table();
	insert(20, &collCount);     print_table();
	insert(56, &collCount);     print_table();
	insert(75, &collCount);     print_table();
	insert(31, &collCount);     print_table();
	insert(19, &collCount);     print_table();
	insert(42, &collCount);     print_table();
	printf("Number of total collisions: %d\n", collCount);
}
