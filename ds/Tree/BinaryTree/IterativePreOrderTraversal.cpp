#include<iostream>
#include<stack>
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

void recursivePreOrderTraversal(Node *root)
{
    if(root){
    cout << root->data << " ";
    recursivePreOrderTraversal(root->left);
    recursivePreOrderTraversal(root->right);
    }
}


void itertivePreOrderTraversal(Node *root)
{
    if (NULL == root)
        return;
    stack<Node*> s1;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        cout << root->data << " ";
        s1.pop();
        if (root->right)
            s1.push(root->right);
        if (root->left)
            s1.push(root->left);
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
    cout << "\n Recursive Pre Order Binary Tree traversal " << endl;
    recursivePreOrderTraversal(root);
    cout << "\n Iterative Pre Order Binary Tree traversal " << endl;
    itertivePreOrderTraversal(root);

     return 0;
}
