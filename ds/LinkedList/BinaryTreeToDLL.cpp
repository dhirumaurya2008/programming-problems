#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* newNode(int data)
{
    node* new_node = new node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
 void printList(node *node)
{
    while (node!=NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}

node* convertBinaryTreeToDLL(node* root)
{
    if (root == NULL)
        return NULL;
        queue<node*> bfsQueue;

        node* last = NULL, *prev = NULL;
        bfsQueue.push(root);
        while (!bfsQueue.empty())
        {
            prev = last;
            last = bfsQueue.front();
            if (last->left)
                bfsQueue.push(last->left);
            if (last->right)
                bfsQueue.push(last->right);
            last->left = prev;
            bfsQueue.pop();
            last->right = bfsQueue.front();
        }
        cout << "last data " << last->data << endl;
        if(last)
         last->right = NULL;

        return root;
}

int main()
{

 // Let us create the tree shown in above diagram
    node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Convert to DLL
    node *head = convertBinaryTreeToDLL(root);

    cout << " \n Doubly Linked List Data " << endl;
    printList(head);
    return 0;

}
