/*https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
*/
#include<iostream>
#include<queue>
#include<map>
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

int heightOfBinaryTree(Node* root)
{
    if (root == NULL)
        return 0;

    return (1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right)));
}

int main()
{
    Node *root  = new Node(1);
    root->left  = new Node(12);
    root->right = new Node(13);

    root->right->left   = new Node(14);
    root->right->right  = new Node(15);

    root->right->left->left   = new Node(21);
    root->right->left->right  = new Node(22);
    root->right->right->left  = new Node(23);
    root->right->right->right = new Node(24);
    cout << "Height of binary tree or maximum depth " << heightOfBinaryTree(root);
    return 0;
}

