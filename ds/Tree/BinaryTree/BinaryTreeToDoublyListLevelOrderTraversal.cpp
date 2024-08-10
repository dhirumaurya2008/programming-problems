/*Get the Left/Right View of Binary Tree
Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes visible
when tree is visited from left side.
*/
#include<iostream>
#include<queue>
using namespace std;

typedef struct _Node
{
  int data;
  struct _Node * left;
  struct _Node * right;
  _Node(int val){
  data = val;
  left = NULL;
  right = NULL;
  }

}Node;

void binaryTreeToDoublyLinkedListLevelOrder(Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> q1;
    q1.push(root);
    Node *prev = NULL;
    while (!q1.empty())
    {
        root = q1.front();
        q1.pop();
        if (root->left)
            q1.push(root->left);
        if (root->right)
            q1.push(root->right);
        root->left = prev;
        root->right = q1.front();
        prev = root;
    }
}

void print(Node* parent)
{
    Node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}

// Driver code
int main()
{
    Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(2);
    root->left->left = new Node(6);
    root->left->right = new Node(4);
    root->right->left = new Node(9);
    root->right->right = new Node(3);

    // Calling required functions
    binaryTreeToDoublyLinkedListLevelOrder(root);

    cout << " Doubly Linked List traversal " << endl;
    print(root);

    return 0;
}
