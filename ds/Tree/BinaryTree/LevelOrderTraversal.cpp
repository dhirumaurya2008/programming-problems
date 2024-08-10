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

void recursiveInOrderTraversal(Node *root)
{
    if(root){
    recursiveInOrderTraversal(root->left);
    cout << root->data << " ";
    recursiveInOrderTraversal(root->right);
    }
}


void levelOrderTraversal(Node *root)
{
    if (NULL == root)
        return;
    queue<Node*> q1;
    q1.push(root);
    while (!q1.empty())
    {
        root = q1.front();
        cout << root->data << " ";
        if (root->left)
            q1.push(root->left);
        if (root->right)
            q1.push(root->right);
        q1.pop();
    }
}

int main()
{
  Node* root = NULL;
    root = new Node(1);
    root->left = new  Node(2);
    root->right = new Node(3);
    root->left->left = new  Node(4);
    root->left->right = new  Node(5);
    root->right->left =new  Node(6);
    root->right->right =new  Node(7);
    cout << "\n Recursive In Order Binary Tree traversal " << endl;
    recursiveInOrderTraversal(root);
    cout << "\n Level Order Binary Tree traversal " << endl;
    levelOrderTraversal(root);

     return 0;
}
