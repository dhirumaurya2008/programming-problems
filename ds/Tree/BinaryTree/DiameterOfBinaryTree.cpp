/*Get the Left/Right View of Binary Tree
Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes visible
when tree is visited from left side.
*/
#include<iostream>
#include<queue>
#include<stack>
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

int height(Node* root)
{
    if ( root == NULL )
        return 0;
    return( max(height(root->left), height(root->right)) +1);
}

int diameterOpt(Node* root)
{
    if (root == NULL)
        return 0;
    int opt1 = diameterOpt(root->left);
    int opt2 = diameterOpt(root->right);
    int opt3 =  height(root->left) + height(root->right) +1;

    return ( max(max(opt1, opt2), opt3));

}

int solveDiameterOfTree(Node *root, int &res)
{
    if (NULL == root)
        return 0;

    int l= solveDiameterOfTree(root->left, res);
    int r= solveDiameterOfTree(root->right, res);

    int temp = max(l, r)+1;
    int ans = max(temp, l+r+1);
    cout << "Res " << res << "ans " << ans <<  endl;
    res = max(ans, res);
    //cout << "Res " << res << "ans " << ans <<  endl;
    return temp;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Diameter of binary tree is " << diameterOpt(root) << endl;
    int res = INT_MIN;

    cout << "Diameter of binary tree is using new method temp = " << solveDiameterOfTree(root, res) << endl;
    cout  << " res = " << res<< endl;

    return 0;
}
