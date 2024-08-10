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

void leftViewHelper(Node* root, int level, vector <int> &vec)
{
    if (NULL == root)
        return;

    if (level == vec.size())
        vec.push_back(root->data);

    leftViewHelper(root->left, level+1, vec);
    leftViewHelper(root->right, level+1, vec);
}

vector<int> leftView(Node *root)
{
    vector<int> vec;

    if (NULL == root)
        return vec;
    int level = 0;

   leftViewHelper(root, level, vec);
   return vec;
}

void rightViewHelper(Node* root, int level, vector <int> &vec)
{
    if (NULL == root)
        return;

    if (level == vec.size())
        vec.push_back(root->data);

    rightViewHelper(root->right, level+1, vec);
    rightViewHelper(root->left, level+1, vec);
}

vector<int> rightView(Node *root)
{
    vector<int> vec;

    if (NULL == root)
        return vec;
    int level = 0;

   rightViewHelper(root, level, vec);
   return vec;
}

int main()
{
  Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right->left = new Node(14);

    {
        cout << "\n Left view of binary tree" << endl;
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }

   {
        cout << "\n Right view of binary tree" << endl;
        vector<int> vec = rightView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
   }

    return 0;
}
