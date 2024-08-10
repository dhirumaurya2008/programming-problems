Node *merge(Node *l1, Node* l2)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            temp->child = l1;
            temp = temp->child;
            l1 = l1->child;
        }
        else {
            temp->child = l2;
            temp = temp->child;
            l2 = l2->child;
        }
    }

    if (l1) {
        temp->child = l1;
    }
    else
    {
        temp->child = l2;
    }
    #if 0
    temp = dummy;
    dummy = dummy->next;
    delete temp;
    #endif
    return dummy->next;
}

Node* mergeTwoLists(Node* a, Node* b) {

    Node *temp = new Node(0);
    Node *res = temp;

    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }

    if(a) temp->child = a;
    else temp->child = b;

    return res -> child;

}

Node *mergeList(Node *l1, Node* l2)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;

    while ((l1 != NULL) && (l2 != NULL)) {
        if (l1->data < l2->data) {
            temp->child = l1;
            temp = temp->child;
            l1 = l1->child;
        }
        else {
            temp->child = l2;
            temp = temp->child;
            l2 = l2->child;
        }
    }

    if (l1) {
        temp->child = l1;
    }
    else
    {
        temp->child = l2;
    }
    return dummy->child;
}

Node* flattenLinkedList(Node* head)
{
	// Write your code here
    if (!head || !head->next)
        return head;
    head->next = flattenLinkedList(head->next);
    head = merge(head, head->next);
    return head;
}
