/*
Write a function to print ZigZag order traversal of a binary tree.
 For the below binary tree the zigzag order traversal will be 1 3 2 7 6 5 4.
*/
#include<iostream>
#include<stack>
#include<vector>
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

vector<int> zigZagTraversal(Node *root)
{
  vector <int> vec;
  if (root == NULL)
    return vec;

  stack<Node*> s1, s2;

  s1.push(root);
  while (!s1.empty() || !s2.empty())
  {
      while(!s1.empty())
      {
          root = s1.top();
          s1.pop();
          vec.push_back(root->data);
          if (root->left)
            s2.push(root->left);
          if (root->right)
            s2.push(root->right);
      }

      while(!s2.empty())
      {
          root = s2.top();
          s2.pop();
          vec.push_back(root->data);
          if (root->right)
            s1.push(root->right);
          if (root->left)
            s1.push(root->left);
      }
  }
  return vec;
}

// the above function
int main()
{

    // vector to store the traversal order.
    vector<int> v;

    // create tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    cout << "ZigZag Order traversal of binary tree is \n";

    v = zigZagTraversal(root);

    for (int i = 0; i < v.size();
         i++) { // to print the order
        cout << v[i] << " ";
    }

    return 0;
}
