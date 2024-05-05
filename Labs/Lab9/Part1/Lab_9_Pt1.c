#include <stdio.h>
#include <stdlib.h>

typedef struct Node {	//typedef renames struct Node to only Node, to simplify the declarations
	int val;
	struct Node *next;
} Node;

Node *head = NULL, *tail = NULL;

void add_tail(int val){
	Node *p = malloc(sizeof(Node));
	p->val = val;
	p->next = NULL;
	if(tail){
		tail->next = p;
		tail = p;
	}
	else{
		head = tail = p;
	}
}

void print_list(){
	Node *p = head;
	printf("The list is: ");
	while(p){
		printf("%d ", p->val);
		p = p->next;
	}
}

int sum_list(){
	int sum = 0;
	for(Node *crt = head; crt; crt = crt->next){
		sum += crt->val;
	}
	return sum;
}

int main(void){
	for(int i = 1; i < 101; i++){
		add_tail(i);
	}

	int sum = sum_list();

	print_list();
	printf("\nSum = %d\n", sum);
}
