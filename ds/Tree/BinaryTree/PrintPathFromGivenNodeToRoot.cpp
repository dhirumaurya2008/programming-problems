/*Print path from root to a given node in a binary tree
*/

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


bool printPath(Node* root, int data, stack <int> &s1)
{
    if (root == NULL)
        return false;

    if (root->data == data)
    {
        s1.push(data);
        return true;
    }

    if (root->left && printPath(root->left, data, s1))
    {
        s1.push(root->data);
        return true;
    }

    if (root->right && printPath(root->right, data, s1))
    {
        s1.push(root->data);
        return true;
    }
    return false;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int x = 5;
    stack<int> s1;
    printPath(root, x, s1);
    cout << "Path from Root to a node" << endl;

    while (!s1.empty())
    {
        cout << s1.top()<< " " ;
        s1.pop();
    }

    return 0;
}
