
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

void printList(Node *node)
{
while (node != NULL)
{
	printf(" %d ", node->data);
	node = node->next;
}
}

Node *reverseListInKGroups(Node *head, unsigned int k)
{
    if(head == NULL)
        return NULL;
    Node *cur = head, *prev = NULL, *temp = NULL;
    unsigned int count = 0;

    while (cur && (count < k)){
        temp = prev;
        prev = cur;
        cur  = cur->next;
        prev->next = temp;
        count++;
    }

    if (cur) {
        head->next = reverseListInKGroups(cur, k);
    }

    return prev;
}
/* Driver program to test above functions*/
int main()
{
    int k = 3;
/* Start with the empty list */
Node* head = NULL;

// Insert 6. So linked list becomes 6->NULL
append(&head, 1);
append(&head, 2);
append(&head, 3);
append(&head, 4);
append(&head, 5);
//append(&head, 6);

printf("\n Created Linked list is: \n");
printList(head);

//head = reverseList(head);

//printf("\n Reverse Linked list is: ");
printf("\n Reverse Linked list in group of k = %d: \n", k);
head = reverseListInKGroups(head, k);
printList(head);

return 0;
}

