/*https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
*/
#include<iostream>
#include<queue>
#include<unordered_map>
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

void make_parrent(Node *root, unordered_map<Node*, Node*> &mp)
{
   if (root == NULL)
        return;
   queue<Node*> q1;
   q1.push(root);

   while (!q1.empty())
   {
       root = q1.front();
       q1.pop();
       if (root->left) {
        q1.push(root->left);
        mp[root->left] = root;
       }
       if(root->right) {
        q1.push(root->right);
        mp[root->right] = root;
       }
   }
}

void printkdistanceNode(Node *root, Node* target, int k)
{
    unordered_map<Node*, Node*> mp;
    make_parrent(root, mp);

    queue<Node*> q1;
    unordered_map<Node*, bool> visited;
    int distance = 0;
    q1.push(target);
    visited[target] = true;

    while (!q1.empty())
    {
        int sizeOfNode = q1.size();

        if (distance == k)
            break;
        distance++;
        for (int i=0; i<sizeOfNode; i++) {
            root = q1.front();
            q1.pop();
            if (root->left && !visited[root->left])
            {
                q1.push(root->left);
                visited[root->left] = true;
            }
            if (root->right && !visited[root->right])
            {
                q1.push(root->right);
                visited[root->right] = true;
            }
            if ((mp.find(root) != mp.end()) && !visited[mp[root]])
            {
               q1.push(mp[root]);
               visited[mp[root]] = true;
            }
        }
    }//End of while loop

    while (!q1.empty()) {

        cout << q1.front()->data << " " ;
        q1.pop();
    }

}


// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    Node * root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    Node * target = root->left->right;
    printkdistanceNode(root, target, 2);
    return 0;
}

