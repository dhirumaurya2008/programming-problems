/*Given a binary tree, print it vertically. The following example illustrates vertical order traversal.
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

//#define isLeafNode(root) ((root->left == NULL) && (root->right == NULL))

bool isLeafNode(Node *root)
{
    if ((root->left == NULL) && (root->right == NULL))
        return true;
    return false;
}

/*addLeftSideNodes find all nodes in left side except the leaf nodes*/
void addLeftSideNodes(Node* root, vector<int> &res)
{
   root = root->left;
   while (root) {
        if (!isLeafNode(root)) {
            res.push_back(root->data);
        }
        if (root->left)
            root = root->left;
        else
            root= root->right;
   }
}

/*find all the leaf nodes*/
void addLeafNodes(Node* root, vector<int> &res)
{
   if (root == NULL)
        return;

   if (isLeafNode(root)) {
        res.push_back(root->data);
        return;
    }
   if (root->left)
      addLeafNodes(root->left, res);
   if(root->right)
   addLeafNodes(root->right, res);
}

/*addRightSideNodes find all nodes in right side except the leaf nodes*/
void addRightSideNodes(Node* root, vector<int> &res)
{
   root = root->right;
   vector<int> temp;
   while (root) {

        if (!isLeafNode(root)) {
           temp.push_back(root->data);
           cout << __func__ << " " << root->data << endl;
        }

        if (root->right)
            root = root->right;
        else
            root= root->left;
   }

   for (int i = temp.size()-1; i >=0; i--)
   {
       res.push_back(temp[i]);
   }
}

void printBoundary(Node* root)
{
    if (root == NULL)
        return;

    vector<int> res;
    res.push_back(root->data);

    /*Print Left Side Node except the Leaf Node*/
    addLeftSideNodes(root, res);

    /*Print Leaf Nodes*/
    addLeafNodes(root, res);
    //addLeafNodes(root->right, res);

    /*Print Right  Nodes*/
    addRightSideNodes(root, res);

    for (int i=0; i<res.size(); i++)
        cout << res[i] << " ";

}
// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    Node* root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    printBoundary(root);

    return 0;
}
