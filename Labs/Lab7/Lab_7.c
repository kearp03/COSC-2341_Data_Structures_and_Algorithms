//Minimalistic implementation of a binary tree (BT).
//Each node is storing an integer key.
//Insertion of new nodes into the BT is done manually
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
	int key;
	struct Node *pLeft;
	struct Node *pRight;
} Node;

Node *pRoot = NULL; //access point(er) to the BT

Node *createNode(int val){
	Node *p = malloc(sizeof(Node));
	p->key = val;
	p->pLeft = NULL;
	p->pRight= NULL;
	return p;
}
void printTree(Node *p){
	if (p){  //equivalent to if (p!=NULL)
		//printing the key in between the L and R children
		printTree(p->pLeft);
		printf("%i ", p->key);
		printTree(p->pRight);
	}
}

bool searchTree(Node *p, int k){
	if(p == NULL){
		return false;
	}
	printf("%d ", p->key);
	if(p->key == k){
		return true;
	}
	else if(p->key > k){
		return searchTree(p->pLeft, k);
	}
	else{
		return searchTree(p->pRight, k);
	}
}

int searchTreeDepth(Node *p, int k, int depth){
	if(p == NULL){
		return -1;
	}
	depth++;
	if(p->key == k){
		return depth;
	}
	else if(p->key > k){
		return searchTreeDepth(p->pLeft, k, depth);
	}
	else{
		return searchTreeDepth(p->pRight, k, depth);
	}
}

int main(void){
	int m;
	Node *pNode;
	//creating the root
	m = 9;
	pNode = createNode(m);
	pRoot = pNode;

	//now insert the nodes w/keys 5, 12, 7
	//Your code here!
	m = 5;
	pNode = createNode(m);
	pRoot->pLeft = pNode;

	m = 12;
	pNode = createNode(m);
	pRoot->pRight = pNode;

	m = 7;
	pNode = createNode(m);
	pRoot->pLeft->pRight = pNode;

	m = 10;
	pNode = createNode(m);
	pRoot->pRight->pLeft = pNode;

	m = 1;
	pNode = createNode(m);
	pRoot->pLeft->pLeft = pNode;

	m = 4;
	pNode = createNode(m);
	pRoot->pLeft->pLeft->pRight = pNode;

	printTree(pRoot);

	printf("\n\n");

	int values[] = {9, 5, 12, 7, -10, 0, 20};
	for(int i = 0; i < sizeof(values)/sizeof(int); i++){
		printf("Searching for %d:\n", values[i]);
		bool isThere = searchTree(pRoot, values[i]);
		int depth = searchTreeDepth(pRoot, values[i], -1);
		printf("\n");
		if(isThere)
			printf("Key found at depth %d", depth);
		else
			printf("Key not found");
		printf("\n\n");
	}
}
