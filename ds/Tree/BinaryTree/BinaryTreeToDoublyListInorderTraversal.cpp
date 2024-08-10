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

void verticalOrderWrapper(Node *root, int hd,  map<int, vector<int>> &mp)
{
    if (root == NULL)
        return;

    mp[hd].push_back(root->data);
    verticalOrderWrapper(root->left, hd-1, mp);
    verticalOrderWrapper(root->right, hd+1, mp);
}

void verticalOrder(Node *root)
{
    if (root == NULL)
        return;
    int hd = 0;
    map<int, vector<int>> mp;
    verticalOrderWrapper(root, hd, mp);
    map<int, vector<int>>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        for (int i = 0; i< (it->second).size(); i++)
            cout << (it->second)[i] << " ";
        cout << endl;
    }
}

int main()
{
    // Create binary tree shown in above figure
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    cout << "Vertical order traversal is \n";
    verticalOrder(root);

    return 0;
}
