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

void recursiveInOrderTraversal(Node *root)
{
    if(root){
    recursiveInOrderTraversal(root->left);
    cout << root->data << " ";
    recursiveInOrderTraversal(root->right);
    }
}


void itertiveInOrderTraversal(Node *root)
{
    if (NULL == root)
        return;
    stack<Node*> s1;

    while (true)
    {
        if (root)
        {
            s1.push(root);
            root = root->left;
        }
        else {
            if(s1.empty())
                break;

                root = s1.top();
                cout << root->data << " " ;
                /*Left Subtree is traversed hence poping*/
                s1.pop();
                /*Perform the same thing for right subtree*/
               root = root->right;
        }
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
    cout << "\n Iterative In Order Binary Tree traversal " << endl;
    itertiveInOrderTraversal(root);

     return 0;
}
