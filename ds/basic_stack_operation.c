#include<stdio.h>

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

int main()
{

 Stack* stack = createStack();

 push(stack, 10);
 push(stack, 20);
 push(stack, 30);
 push(stack, 40);

 while(stack->top)
 {
     printf("%d ",pop(stack));
 }

  free(stack);
 return 0;
}
