#include<iostream>
#include<map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
Node(int data)
{
    this->data = data;
    this->next = NULL;
    this->random = NULL;
}
};

class LinkedList
{
public:
    Node *head;
    LinkedList(Node* head)
    {
        this->head = head;
    }

    void push(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *random = temp->random;
            int randomData = (random != NULL)?
                         random->data: -1;
            cout << "temp = " << temp << " , " ;
            cout << "Data = " << temp->data
                 << ", ";
            cout << "Random = " << random << " , " ;
            cout << "Random Data = " <<
                 randomData << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    LinkedList* clone()
    {
        map<Node*, Node*> myMap;
        Node* cur = head;
        Node* headClone = NULL;
        if (head == NULL)
            return NULL;
        while (cur)
        {
            Node *temp = new Node(cur->data);
            myMap[cur] = temp;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
           Node *temp  = myMap[cur];
           temp->next =  myMap[cur->next];
            temp->random = myMap[cur->random];
            cur = cur->next;
        }

        headClone = myMap[head];
        return new LinkedList(headClone);
    }
};

int main()
{
    LinkedList *mylist = new LinkedList(new Node(5));
    mylist->push(4);
    mylist->push(3);
    mylist->push(2);
    mylist->push(1);

    mylist->head->random = mylist->head->next->next;

    mylist->head->next->random =
        mylist->head->next->next->next;

    mylist->head->next->next->random =
        mylist->head->next->next->next->next;

    mylist->head->next->next->next->random =
        mylist->head->next->next->next->next->next;

    mylist->head->next->next->next->next->random =
        mylist->head->next;

    LinkedList *mylistClone = mylist->clone();
    cout << "Original linked list\n";
    mylist->print();
    cout << "\nCloned linked list\n";
    mylistClone->print();
    return 0;
}
