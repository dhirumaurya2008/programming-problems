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

void   printKDistant(Node* root, int k)
{
    if (root == NULL)
        return;
    if (k == 0) {
        cout << root->data << " ";
        return;
    }

    printKDistant(root->left, k-1);
    printKDistant(root->right, k-1);
}

int main()
{
     Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);

    cout << "printKDistant \n" << endl;
    printKDistant(root, 2);


    return 0;
}
