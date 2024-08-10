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

void inorder(Node *root)
{
    if(root){
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    }
}

void recursivePostOrder(Node *root)
{
    if(root){
    recursivePostOrder(root->left);
    recursivePostOrder(root->right);
    cout << root->data << " ";
    }
}

void itertivePostOrderTraversal(Node *root)
{
    cout << "\n Iterative Post Order Binary Tree traversal using one stack " << endl;
    stack<Node*> s1;
    /*We will iterterate into the while loop either current root is not NULL or Stack is not empty */
    while ((root != NULL) || (!s1.empty() ))
           {
            /*We are visiting the Node for first time*/
            if (root)
            {
                s1.push(root);
                root = root->left;
            }
            else { /*We reached here when we reached to the leaf node and root == NULL*/

                    Node *temp = s1.top()->right;
                    /*We visited left subtree and we are now checking for right subtree*/
                    /*Case 1: right subtree of stack top is NULL*/
                    if(temp == NULL)
                    {
                        temp = s1.top();
                        cout << temp->data << " ";
                        s1.pop();
                        /*Now check if temp is right subtree of stack top*/
                        while (!s1.empty() && (temp == s1.top()->right))
                        {
                            temp = s1.top();
                            cout << temp->data << " ";
                            s1.pop();
                        }
                    }
                    else /*Case 2: Right subtree is still needs to be visited*/
                    {
                        root = temp;
                    }
            }
           }
}

int main()
{
  Node* root = NULL;
    root = new Node(1);
    root->left = new  Node(2);
    root->right = new Node(3);
    root->left->left = new  Node(4);
    root->left->right = new  Node(5);
    root->right->left =new  Node(6);
    root->right->right =new  Node(7);
    cout << "\n Recursive Post Order Binary Tree traversal " << endl;
    recursivePostOrder(root);
    itertivePostOrderTraversal(root);

     return 0;
}
