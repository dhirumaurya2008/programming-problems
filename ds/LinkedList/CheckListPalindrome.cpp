#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    char data;
    struct Node* next;
}Node_t;

void push(struct Node** head_ref, char new_data)
{

    // Allocate node
    struct Node* new_node = (struct Node*)malloc(
        sizeof(struct Node));

    // Put in the data
    new_node->data = new_data;

    // Link the old list off the new node
    new_node->next = (*head_ref);

    // Move the head to pochar to the new node
    (*head_ref) = new_node;
}

void printList(struct Node* ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << "\n";
}

void reverseList(Node_t** head)
{
    if (NULL == (*head))
        return;
    Node_t* tmp = NULL, *prev = NULL, *cur = (*head);

    while (cur) {
        tmp = prev ;
        prev = cur;
        cur = cur->next;
        prev->next = tmp;
    }

    if (prev)
    {
        (*head) = prev;
    }
}

bool compareList(Node* list1, Node *list2)
{
    if (list1 == NULL || list2 == NULL)
        return false;
    while (list1 && list2)
    {
        if (list1->data != list2->data)
            return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    return true;
}

bool isListPalindrome(Node_t *head)
{
    bool result = true;
    if (head == NULL)
        return NULL;
    Node_t* slowPtr = head, *slowPtrPrev = head, *fastPtr = head, *midNodePtr = NULL, *second_half_ptr = NULL;

    while (fastPtr && fastPtr->next)
    {
        slowPtrPrev = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    if (fastPtr) {
        midNodePtr = slowPtr;
        slowPtr = slowPtr->next;
    }

    slowPtrPrev->next = NULL;

    second_half_ptr = slowPtr;
    reverseList(&second_half_ptr);
    result = compareList(head, second_half_ptr);
    reverseList(&second_half_ptr);
    if (midNodePtr) {
        slowPtrPrev->next = midNodePtr;
        midNodePtr->next = second_half_ptr;
    }
    else
    {
      slowPtrPrev->next =   second_half_ptr;
    }
    return result;

}
// Driver code
int main()
{

    // Start with the empty list
    struct Node* head = NULL;
    char str[] = "abacaba";
    int i;

    for(i = 0; str[i] != '\0'; i++)
    {
        push(&head, str[i]);
        printList(head);
        isListPalindrome(head) ? cout << "Is Palindrome"
                 << "\n\n" : cout << "Not Palindrome"
                 << "\n\n";

    }

    return 0;
}
