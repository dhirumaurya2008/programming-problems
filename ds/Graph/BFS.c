// A C Program to demonstrate adjacency list
// representation of graphs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
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

typedef struct _Node
{
    int data;
    struct _Node* next;
}Node;

typedef struct _Queue
{
  Node* front;
  Node* rear;
}Queue;
/*Create Statck and inititalize it*/
/*Push operation */
void enqueue(Queue* queue, int data)
{
   if(!queue)
    return NULL;

   Node* newQueueNode = (Node*)malloc(sizeof(Node));
   if(!newQueueNode)
    return NULL;

    newQueueNode->data = data;
    newQueueNode->next = NULL;

    if(!queue->front)
    {
        queue->rear = newQueueNode;
        queue->front = newQueueNode;
        return;
    }

   queue->rear->next = newQueueNode;
   queue->rear = newQueueNode;
}

int dequeue(Queue* queue)
{
  if(!queue || !queue->front)
    return 0;

  Node* temp = queue->front;
  int data = temp->data;
  queue->front = queue->front->next;
  free(temp);
  return data;
}


Queue* createQueue()
{
     Queue* queue = (Queue*)malloc(sizeof(Queue));
     queue->front = NULL;
     queue->rear = NULL;
}

void BFSGraphTraversal(struct Graph* graph, int srcVertex)
{
    if(!graph)
        return;
    bool *visitedNodes = (bool*)malloc(sizeof(bool)* graph->V);
    for(int i=0; i<graph->V; i++)
        visitedNodes[i] = false;

    Queue* queue = createQueue();
    int temp;

    visitedNodes[srcVertex] = true;
    enqueue(queue, srcVertex);
    while(queue->front)
    {
      temp = dequeue(queue);
      printf("%d \t", temp);

      struct AdjListNode*curr = graph->array[temp].head;

      while(curr)
      {
          //printf("curr[%d] curr->dest %d \t", temp, curr->dest);
        if(visitedNodes[curr->dest] == false){
         enqueue(queue, curr->dest);
         visitedNodes[curr->dest] = true;
        }
         curr = curr->next;
      }
    }
}


// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	int V = 4;
	struct Graph* graph = createGraph(V);
	addEdge(graph,0, 1);
    addEdge(graph,0, 2);
    addEdge(graph,1, 2);
    addEdge(graph,2, 0);
    addEdge(graph,2, 3);
    addEdge(graph,3, 3);
    #if 0
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
#endif
	// print the adjacency list representation of the above graph

	printGraph(graph);
    printf("\n Graph BFS Traversal\n");
	BFSGraphTraversal(graph, 2);

	return 0;
}
