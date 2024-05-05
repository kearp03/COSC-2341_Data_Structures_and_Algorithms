/*Adjacency list representation of graphs. Notes:
--New nodes are added at the end of the A-list.
--The program represents a *directed* graph. If an undirected edge, e.g. (1, 2),
is desired, the function addEdge() needs to be called *twice* like this:
addEdge(pGraph, 1, 2);
addEdge(pGraph, 2, 1);*/

#include <stdio.h>
#include <stdlib.h>

// A structure to represent each node of an adjacency list
typedef struct Node {
	int vertNum;
	struct Node* next;
} Node;

//A structure to represent the vertex of the array. To
//be used in the array of vertices, *not* in the a-list!
typedef struct Vertex{
	int mark;
	Node* next;  //The first vertex/node connected to this one.
} Vertex;

// A structure to represent a graph. A graph has an array of pointers
// to nodes. Each such pointer represents the nodes adjacent to that node.
// Size of array is V (number of vertices/nodes in graph)
typedef struct Graph {
	int V;
	Vertex* pArray;
} Graph;

// A utility function to create a new node *for the a-list*
Node* createNewNode(int vertNum) {
	Node* pNewNode = (Node*) malloc(sizeof(Node));
	pNewNode->vertNum = vertNum;
	pNewNode->next = NULL;      //initially unconnected
	return pNewNode;
}

/*  Utility function that creates a graph with V nodes
    Note: The edges are not yet represented, i.e. the A-lists are all empty!
Must then call addEdge() multiple times to populate the A-lists. */
Graph* createGraph(int V) {
	Graph* graph = (Graph*) malloc(sizeof(Graph));
	graph->V = V;   //nr. of vertices (nodes)
	// Create an array of V adjacency lists.
	graph->pArray = (Vertex*) malloc(V * sizeof(Vertex));
	// Initialize each adj. list as empty by making the array element NULL
	for (int i = 0; i < V; ++i){
		(graph->pArray[i]).mark = 0;
		(graph->pArray[i]).next = NULL;
	}
	return graph;
}

/* Adds an edge to a directed graph, from src node to dest node.
The new edge is added at the end of the A-list.*/
void addEdge(Graph* graph, int src, int dest) {
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
}

// Utility function to print all the A-lists in the graph
void printGraph(Graph* graph) {
	for (int v = 0; v < graph->V; v++) {
		Node* pCrawl = graph->pArray[v].next;
		printf("Vertex %d has mark %d; ", v, graph->pArray[v].mark);
		printf("a-list:");
		while (pCrawl) {   //exits when pointer is NULL at end of list
			printf("-> %d", pCrawl->vertNum);
			pCrawl = pCrawl->next;  //advance to the next list element
		}
		printf("\n");
	}
}

void dfs(Graph* graph, int v){
	static int count = 0; //initialize count
	count++; //increment count
	graph->pArray[v].mark = count; //assign count to current vertex's mark

	printf("Vertex %d has mark %d\n", v, count); //print current vertex and it's mark

	for(Node* pCrawl = graph->pArray[v].next; pCrawl; pCrawl = pCrawl->next) //loop through aList of each vertex
		if(graph->pArray[pCrawl->vertNum].mark == 0) //if node is not visited before
			dfs(graph, pCrawl->vertNum); //call function recursively for nodes not visited
}

void dfs_loop(Graph* graph){
	for(int v = 0; v < graph->V; v++){ //loop through each vertex
		if(graph->pArray[v].mark == 0){ //if node has not been visited before
			printf("Root of a new tree is vertex %d:\n", v); //print new root
			dfs(graph, v); //do dfs from the current node, i.e. the root of a tree
		}
	}
}

int main() {
	int V = 7;
	struct Graph* pGraph = createGraph(V);

	addEdge(pGraph, 0, 1);
	addEdge(pGraph, 0, 2);
	//addEdge(pGraph, 0, 3);
	addEdge(pGraph, 1, 5);
	addEdge(pGraph, 1, 6);
	addEdge(pGraph, 2, 4);
	addEdge(pGraph, 3, 2);
	addEdge(pGraph, 3, 4);
	addEdge(pGraph, 3, 5);
	addEdge(pGraph, 3, 6);
	addEdge(pGraph, 4, 1);

	addEdge(pGraph, 6, 4);

	//printGraph(pGraph);

	//dfs(pGraph, 0);

	dfs_loop(pGraph);

	printf("\n");
	printGraph(pGraph);
}
