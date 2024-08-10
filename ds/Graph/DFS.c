// A C Program to demonstrate adjacency list
// representation of graphs
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

// A structure to represent an adjacency list node
struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList
{
	struct AdjListNode *head;
};

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
struct Graph
{
	int V;
	struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* newNode =
	(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
	struct Graph* graph =
		(struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;

	// Create an array of adjacency lists. Size of
	// array will be V
	graph->array =
	(struct AdjList*) malloc(V * sizeof(struct AdjList));

	// Initialize each adjacency list as empty by
	// making head as NULL
	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
	// Add an edge from src to dest. A new node is
	// added to the adjacency list of src. The node
	// is added at the beginning
	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	// Since graph is undirected, add an edge from
	// dest to src also
	#if 0
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
	#endif
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->V; ++v)
	{
		struct AdjListNode* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl)
		{
			printf("-> %d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

/********************************************/

#if 0
typedef struct _Node
{
    int data;
    struct _Node* next;
}Node;

typedef struct _Stack
{
  Node* top;
}Stack;
/*Create Statck and inititalize it*/
/*Push operation */
void push(Stack* stack, int data)
{
   if(!stack)
    return NULL;

   Node* newStackNode = (Node*)malloc(sizeof(Node));
   if(!newStackNode)
    return NULL;

    newStackNode->data = data;
   newStackNode->next = stack->top;
   stack->top = newStackNode;

}

int pop(Stack *stack)
{
  if(!stack || !stack->top)
    return 0;


  Node* temp = stack->top;
  int data = temp->data;
  stack->top = temp->next;
  free(temp);
  return data;
}


Stack* createStack()
{
     Stack* stack = (Stack*)malloc(sizeof(Stack));
     stack->top = NULL;
}

#endif
void DFSGraphTraversalUtil(struct Graph* graph, bool visitedNodes[], int srcVertex )
{
  visitedNodes[srcVertex] = true;
  printf("%d ", srcVertex);
  struct AdjListNode* curr = graph->array[srcVertex].head;

  while(curr)
  {
      if(visitedNodes[curr->dest] == false){
         DFSGraphTraversalUtil(graph, visitedNodes, curr->dest);
      }
      curr = curr->next;
  }
}

void DFSGraphTraversal(struct Graph* graph, int srcVertex)
{
  //Stack* stack = createStack();
  bool *visitedNodes = (bool*)malloc(sizeof(bool)* graph->V);
  for(int i=0; i<graph->V; i++)
        visitedNodes[i] = false;
  DFSGraphTraversalUtil(graph, visitedNodes, srcVertex);
}
// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	int V = 4;
	struct Graph* graph = createGraph(V);
	#if 0
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	#endif
	addEdge(graph,0, 1);
    addEdge(graph,0, 2);
    addEdge(graph,1, 2);
    addEdge(graph,2, 0);
    addEdge(graph,2, 3);
    addEdge(graph,3, 3);

	// print the adjacency list representation of the above graph
    printf("\n Graph BFS Traversal\n");
	DFSGraphTraversal(graph, 2);

	//BFS(G);

	return 0;
}
