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


Node* reverseList(Node*head)
{
    if(!head)
        return NULL;
    Node* temp=NULL, *curr = head, *prev = NULL;

    while(curr)
    {
        temp = prev;
        prev = curr;
        curr = curr->next;
        prev->next = temp;
    }
    return prev;
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

Node *detectCycleInList(Node *head)
{

    if ((head == NULL) && (head->next == NULL))
        return NULL;
    Node *fast = head, *slow = head;
    slow = slow->next;
    fast = fast->next->next;

    while (fast && fast->next)
    {
        if (slow == fast) {
                printf("Loop found node[%d]\n", slow->data);
            return slow;

        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return NULL;
}

Node *detectCycleAndRemoveLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node* intersectionNode = detectCycleInList(head);
    Node* temp = head;
    if (intersectionNode != NULL) {
        while (1)
        {
            printf("\n temp->data[%d] intersectionNode->data[%d]\n", temp->data, intersectionNode->data);
            if (temp->next == intersectionNode->next)
                break;
            temp = temp->next;
            intersectionNode = intersectionNode->next;
        }
        intersectionNode->next = NULL;
    }

    return head;
}

/* Driver program to test above functions*/
int main()
{

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

head->next->next->next->next->next = head->next->next;
//printList(head);


printf("\n detectCycleAndRemoveLoop: \n");
head = detectCycleAndRemoveLoop(head);

printList(head);

return 0;
}
