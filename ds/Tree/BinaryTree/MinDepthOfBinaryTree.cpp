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

int minDepthOfBinaryTree(Node* root)
{
    if (root == NULL)
        return 0;

    return (1 + min(minDepthOfBinaryTree(root->left), minDepthOfBinaryTree(root->right)));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Minimum depth " << minDepthOfBinaryTree(root);
    return 0;
}

