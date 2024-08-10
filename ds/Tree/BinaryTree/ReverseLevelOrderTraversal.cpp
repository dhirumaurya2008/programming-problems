/*Get the Left/Right View of Binary Tree
Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes visible
when tree is visited from left side.
*/
#include<iostream>
#include<queue>
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

void reverseLevelOrder(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q1;
    stack<int> s1;

    q1.push(root);
    while(!q1.empty())
    {
        root = q1.front();
        q1.pop();
        s1.push(root->data);
        if (root->right)
            q1.push(root->right);
        if (root->left)
            q1.push(root->left);
    }

    while (!s1.empty()) {
        cout << s1.top() << " " ;
        s1.pop();
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level Order traversal of binary tree is \n";
    reverseLevelOrder(root);
    return 0;
}
