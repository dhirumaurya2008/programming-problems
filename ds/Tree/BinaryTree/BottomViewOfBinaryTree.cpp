/*Get the Left/Right View of Binary Tree
Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes visible
when tree is visited from left side.
*/
#include<iostream>
#include<queue>
#include<map>
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


void topViewHelper(Node* root, vector<int> &vec)
{
    if (NULL == root)
        return;

     int line =0;
     map<int, int> mp;

     queue< pair<Node*, int> > q1;

        q1.push({root, line});

        while (!q1.empty()) {
            root = q1.front().first;
            line = q1.front().second;
            q1.pop();
            if (mp.find(line) == mp.end())
            {
                mp[line] = root->data;
            }

            if (root->left)
                q1.push({root->left, line-1});
            if (root->right)
                q1.push({root->right, line+1});
        }

     for (auto it =mp.begin(); it != mp.end(); it++)
    {
        vec.push_back(it->second);
    }
}

vector<int> topView(Node *root)
{
    vector<int> vec;
    if (NULL == root)
        return vec;
    topViewHelper(root, vec);
    return vec;
}

void bottomViewHelper(Node* root, vector<int> &vec)
{
    if (NULL == root)
        return;

     int line =0;
     map<int, int> mp;

     queue< pair<Node*, int> > q1;

        q1.push({root, line});

        while (!q1.empty()) {
            root = q1.front().first;
            line = q1.front().second;
            q1.pop();
            mp[line] = root->data;

            if (root->left)
                q1.push({root->left, line-1});
            if (root->right)
                q1.push({root->right, line+1});
        }

     for (auto it =mp.begin(); it != mp.end(); it++)
    {
        vec.push_back(it->second);
    }
}

vector<int> bottomView(Node *root)
{
    vector<int> vec;
    if (NULL == root)
        return vec;
    bottomViewHelper(root, vec);
    return vec;
}


int main()
{
  Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    #if 1
   {
        cout << "\n Bottom view of binary tree" << endl;
        vector<int> vec = bottomView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
   }
#endif
    return 0;
}
