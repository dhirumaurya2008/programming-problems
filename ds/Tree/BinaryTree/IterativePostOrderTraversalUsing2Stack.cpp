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

void inorder(Node *root)
{
    if(root){
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    }
}

void recursivePostOrder(Node *root)
{
    if(root){
    recursivePostOrder(root->left);
    recursivePostOrder(root->right);
    cout << root->data << " ";
    }
}

void itertivePostOrderTraversal(Node *root)
{
    cout << "\n Iterative Post Order Binary Tree traversal " << endl;
    stack<Node*> s1, s2;

    s1.push(root);
    while(!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->left)
            s1.push(root->left);
        if (root->right)
            s1.push(root->right);
    }

    while(!s2.empty())
    {
        cout << s2.top()->data << " " ;
        s2.pop();
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
    cout << "\n Recursive Post Order Binary Tree traversal " << endl;
    recursivePostOrder(root);
    itertivePostOrderTraversal(root);

     return 0;
}
