//Minimalistic implementation of a binary tree (BT).
//Each node is storing an integer key.
//Insertion of new nodes into the BT is done manually -
//there is no guarantee for a binary search tree (BST)!
#include <stdio.h>
#include <stdlib.h>

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

void insertTree(Node *p, int value){
	if (p == NULL){
		printf("ERROR - empty root!");
		return;
	}

	if(p->key < value){ // go right
		if(p->pRight != NULL){ // navigate child to the right
			insertTree(p->pRight, value);
		}
		else{ // no child to the right, create node and store it there
			p->pRight = createNode(value);
		}
	}
	else{ // go left
		if(p->pLeft != NULL){ // navigate child to the left
			insertTree(p->pLeft, value);
		}
		else{ // no child to the left, create node and store it there
			p->pLeft = createNode(value);
		}
	}
}

int main(void){
	//creating a tree w/root 9 and nodes 5, 12, 1, 7, 10, 4
	int keys[] = {9, 5, 12, 1, 7, 10, 4};
	//creating the root
	pRoot = createNode(keys[0]);
	for(int i = 1; i < sizeof(keys)/sizeof(keys[0]); i++){
		insertTree(pRoot, keys[i]);
	}
	printTree(pRoot);
	printf("\n");
}
