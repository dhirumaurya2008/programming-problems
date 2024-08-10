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


void print(Node* parent)
{
    Node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}

void preorder(Node* root)
{
    if (root)
    {
        cout << root->data << " " ;
        preorder(root->left);
        preorder(root->right);
    }
}

void Util(Node* root, Node** prev)
{
    if (root == NULL)
        return;

    Util(root->left, prev);
    Util(root->right, prev);
    (*prev)->right = root;
    root->left = (*prev);
    (*prev) = root;
    /*For first node of List head is still not populated*/

}

void binaryTreeToDoublyLinkedListPreOrder(Node* root)
{
    Node *prev = NULL;

    Util(root, &prev);

}
// Driver code
int main()
{
   Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);
cout << " Preorder Tree " << endl;
      preorder(root);


    // Calling required functions
    binaryTreeToDoublyLinkedListPreOrder(root);

    cout << " Doubly Linked List traversal Inorder " << endl;
    print(root);

    return 0;
}
