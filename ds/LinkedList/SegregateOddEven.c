#include<stdio.h>
#include <stdlib.h>

// A linked list node
typedef struct _Node
{
int data;
struct _Node *next;
}Node;

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data)
{
	/* 1. allocate node */
	Node* new_node = (Node*) malloc(sizeof(Node));

	Node *last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. This new node is going to be the last node, so make next of
		it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new node as head */
	if (*head_ref == NULL)
	{
	*head_ref = new_node;
	return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}



// This function prints contents of linked list starting from head
void printList(Node *node)
{
while (node != NULL)
{
	printf(" %d ", node->data);
	node = node->next;
}
}



Node *segregateOddEven(Node *head)
{
    if (NULL == head)
        return NULL;

    Node* cur = head, *even_start = NULL, *even_end = NULL, *odd_start = NULL, *odd_end = NULL;

    while (head) {
        cur = head;
        head = head->next;
        cur->next = NULL;
        if(cur->data % 2 == 0) {
            if (even_start == NULL) {
                even_start = cur;
                even_end = cur;
            }
            else {
                even_end->next = cur;
                even_end = cur;
            }
        }
        else {
            if (odd_start == NULL) {
                odd_start = cur;
                odd_end = cur;
            }
            else {
                odd_end->next = cur;
                odd_end = cur;
            }
        }
    }

    if (odd_start)
    {
        head = odd_start;
        odd_end->next = even_start;
    }
    else
    {
        head = even_start;
    }

    return head;
}
/* Driver program to test above functions*/
int main()
{

/* Start with the empty list */
Node* head = NULL;

// Insert 6. So linked list becomes 6->NULL
#if 0
append(&head, 1);
append(&head, 2);
append(&head, 3);
append(&head, 4);
#endif
#if 1
append(&head, 2);
append(&head, 2);
append(&head, 10);
append(&head, 40);
#endif
//append(&head, 5);
//append(&head, 6);

printf("\n Created Linked list is: \n");
printList(head);

head = segregateOddEven(head);
printf("\n segregateOddEven Linked list is: \n");
printList(head);

return 0;
}
