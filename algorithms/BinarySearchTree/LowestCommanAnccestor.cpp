/*Given values of two values n1 and n2 in a Binary Search Tree, find the Lowest Common Ancestor (LCA). You may assume that both the values exist in the tree.
*/
#include<iostream>
#include<map>
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

Node* lca(Node* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data > max (n1,n2))
    {
        return lca(root->left, n1, n2);
    }
    if (root->data < min (n1,n2))
        return lca(root->right, n1, n2);
    return root;
}
/* Driver code*/
int main()
{
    // Let us construct the BST
    // shown in the above figure
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int n1 = 10, n2 = 14;
    Node *t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data<<endl;

    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    cout<<"LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
    return 0;
}
