#include <stdio.h>
#include <stdlib.h>

typedef struct Node { //typedef renames struct Node to only Node, to simplify the declarations
	int val;
	struct Node *next;
} Node;

Node *head = NULL, *tail = NULL;

void add_tail(int val){
	Node *p = malloc(sizeof(Node));
	p->val = val;
	p->next = NULL;
	if (tail){
		tail->next = p;
		tail = p;
	}
	else{
		head = tail = p;
	}
}

void print_list(){
	printf("The list is: ");
	for(Node *p = head; p; p = p->next){
		printf("%d ", p->val);
	}
	printf("\n");
}

int get_list_element(int i){
	for(Node *p = head; p; p = p->next, i--){
		if(i == 0) return p->val;
	}
	return 0;
}

unsigned list_len(){
	unsigned len = 0;
	for(Node *p = head; p; p = p->next, len++);
	return len;
}

int list_total(){
	int sum = 0;
	for(Node *p = head; p; p = p->next){
		sum += p->val;
	}
	return sum;
}

int main(void){
	int m;
	printf("Enter integers, 0 to exit:\n");
	scanf("%d", &m);
	while (m != 0){
		add_tail(m);
		scanf("%d", &m);
	}
	print_list();

	printf("Sum: %d\n", list_total());
}
