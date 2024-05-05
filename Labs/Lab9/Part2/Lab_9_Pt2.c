/*Adjacency list representation of graphs. Notes:
--New nodes are added at the end of the A-list.
--The program represents a *directed* graph. If an undirected edge, e.g. (1, 2),
is desired, the function addEdge() needs to be called *twice* like this:
addEdge(pGraph, 1, 2);
addEdge(pGraph, 2, 1);*/

#include <stdio.h>
#include <stdlib.h>

// A structure to represent a graph. A graph has an array of pointers
// to nodes. Each such pointer represents the nodes adjacent to that node.
// Size of array is V (number of vertices/nodes in graph)
typedef struct Graph {
	int V;
	struct Vertex* pArray;
} Graph;

//A structure to represent the vertex of the array. To
//be used in the array of vertices, *not* in the a-list!
typedef struct Vertex{
	int mark;
	int outIndex;
	int inIndex;
	struct Node* next;  //The first vertex/node connected to this one.
} Vertex;

// A structure to represent each node of an adjacency list
typedef struct Node {
	int vertNum;
	struct Node* next;
} Node;

// A utility function to create a new node *for the a-list*
Node* createNewNode(int vertNum) {
	Node* pNewNode = (struct Node*) malloc(sizeof(struct Node));
	pNewNode->vertNum = vertNum;
	pNewNode->next = NULL;      //initially unconnected
	return pNewNode;
}

/*  Utility function that creates a graph with V nodes
    Note: The edges are not yet represented, i.e. the A-lists are all empty!
Must then call addEdge() multiple times to populate the A-lists. */
Graph* createGraph(int V) {
	Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;   //nr. of vertices (nodes)
	// Create an array of V adjacency lists.
	graph->pArray = (struct Vertex*) malloc(V * sizeof(struct Vertex));
	// Initialize each adj. list as empty by making the array element NULL
	for (int i = 0; i < V; ++i){
		(graph->pArray[i]).mark = 0;
		(graph->pArray[i]).inIndex = 0;
		(graph->pArray[i]).outIndex = 0;
		(graph->pArray[i]).next = NULL;
	}
	return graph;
}

/* Adds an edge to a directed graph, from src node to dest node.
The new edge is added at the end of the A-list.*/
void addEdge(struct Graph* graph, int src, int dest) {
	Node* pNewNode = createNewNode(dest);
	if (graph->pArray[src].next == NULL)     //A-list is empty
		graph->pArray[src].next = pNewNode;  //new node is first in list
	else{                               //A-list is not empty
		Node* pCrawl = graph->pArray[src].next; //ptr to head of list
		while (pCrawl->next != NULL)     //traverse to tail of list
			pCrawl = pCrawl->next;
		//pNode now points to the tail of the list
		pCrawl->next = pNewNode;     //add new node to tail of list
	}
	graph->pArray[src].outIndex++;
	graph->pArray[dest].inIndex++;
}

void print_list(Node* p){
	while(p){
		printf("->%d", p->vertNum);
		p = p->next;
	}
}

// Utility function to print all the A-lists in the graph
void printGraph(Graph* graph) {
	for (int v = 0; v < graph->V; v++) {
		printf("Vertex %d has mark %d; ", v, graph->pArray[v].mark);
		printf("a-list:");
		print_list(graph->pArray[v].next);
		printf("\n");
	}
}

int out_index(Node* p){
	int len = 0;
	for(; p; p = p->next, len++);
	return len;
}

int in_index(Vertex* pArr, int src, int v){
	int inIndex = 0;
	for(int crt = 0; crt < v; crt++){
		if(crt == src) continue;
		Node *p = pArr[crt].next;
		while(p){
			if(p->vertNum == src) inIndex++;
			p = p->next;
		}
	}
	return inIndex;
}

void printGraphLen(Graph* graph) {
	for (int v = 0; v < graph->V; v++) {
		printf("Vertex %d has mark %d; ", v, graph->pArray[v].mark);
		printf("a-list:");
		print_list(graph->pArray[v].next);
		printf("\n\tout-index: %d\n", graph->pArray[v].outIndex);
		printf("\tin-index: %d", graph->pArray[v].inIndex);
		printf("\n");
	}
}

void printGraphLen2(Graph* graph) {
	for (int v = 0; v < graph->V; v++) {
		printf("Vertex %d has mark %d; ", v, graph->pArray[v].mark);
		printf("a-list:");
		print_list(graph->pArray[v].next);
		printf("\n\tout-index: %d\n", out_index(graph->pArray[v].next));
		printf("\tin-index: %d", in_index(graph->pArray, v, graph->V));
		printf("\n");
	}
}

int main() {
	int V = 6;
	Graph* pGraph = createGraph(V);

	//edges 0 has
	addEdge(pGraph, 0, 1);
	addEdge(pGraph, 0, 2);
	addEdge(pGraph, 0, 3);

	//edges 1 has
	addEdge(pGraph, 1, 2);
	addEdge(pGraph, 1, 5);

	//edges 2 has
	addEdge(pGraph, 2, 4);

	//edges 3 has
	addEdge(pGraph, 3, 0);
	addEdge(pGraph, 3, 4);

	//edges 4 has
	addEdge(pGraph, 4, 5);

	printf("Using member variables in Vertex struct:\n");
	printGraphLen(pGraph);

	printf("\n\nUsing functions:\n");
	printGraphLen2(pGraph);
}
