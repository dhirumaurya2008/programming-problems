/*
Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.
*/
#include<bits/stdc++.h>
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

int findMaxSumWrapper(Node* root, int &res)
{
    if (root == NULL)
        return 0;
    int l = findMaxSumWrapper(root->left, res);
    int r = findMaxSumWrapper(root->right, res);

    int temp = max( (max(l,r)+root->data), root->data);
    int ans = max(temp, l+r+root->data);
    res = max(res, ans);
    return temp;
}

int findMaxSum(Node *root)
{
    int res = INT_MIN;
    findMaxSumWrapper(root, res);
    return res;
}

int main(void)
{
    Node *root = new Node(10);
    root->left        = new Node(2);
    root->right       = new Node(10);
    root->left->left  = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left   = new Node(3);
    root->right->right->right  = new Node(4);
    cout << "Max path sum is " << findMaxSum(root);
    return 0;
}
