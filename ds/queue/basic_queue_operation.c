#include<stdio.h>

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

    if(!queue->rear)
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

int main()
{

 Queue* queue = createQueue();

 enqueue(queue, 10);
 enqueue(queue, 20);
 enqueue(queue, 30);
 enqueue(queue, 40);

 while(queue->front)
 {
     printf("%d ",dequeue(queue));
 }

  free(queue);
 return 0;
}
