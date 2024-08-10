#include<stdio.h>
#include<cstdlib>
struct Node
{
  int data;
  Node* left;
  Node* right;

};

void append(Node **root, int data)
{
    if( NULL == (*root))
    {
        (*root) = (Node*)malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else
    {
        if((*root)->data > data)
         append(&((*root)->left), data);
        else
            append(&((*root)->right), data);
    }
}

Node* findMin(Node* root)
{
   if (root == NULL)
        return NULL;
   while(root->left)
    root = root->left;
   return root;
}

/*Node delete*/
Node* bstNodeDelete(Node* root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data > data) {
        root->left = bstNodeDelete(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = bstNodeDelete(root->right, data);
    }
    else {
        if ((root->left == NULL) && (root->right == NULL))
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL) {
            Node* tmp = root;
            root = root->right;
            free(tmp);
        }
        else if (root->right == NULL) {
            Node* tmp = root;
            root = root->left;
            free(tmp);
        }
        else
        {
            Node* tmp = findMin(root->right);
            root->data = tmp->data;
            root->right = bstNodeDelete(root->right, tmp->data);
        }
    }
    return root;

}
void preorder(Node* root)
{
    if(!root)
    return;

    printf("%d\t", root->data);
    if(root->left);
        preorder(root->left);
    if(root->right);
        preorder(root->right);
}

void inorder(Node* root)
{
    if(!root)
    return;

    if(root->left);
        inorder(root->left);
    printf("%d\t", root->data);
    if(root->right);
        inorder(root->right);
}

void postorder(Node* root)
{
    if(!root)
    return;

    if(root->left);
        postorder(root->left);
    if(root->right);
        postorder(root->right);
    printf("%d\t", root->data);
}

int main()
{
    Node* root = NULL;
    append(&root, 50);
    append(&root, 30);
    append(&root, 20);
    append(&root, 40);
    append(&root, 70);
    append(&root, 60);
    append(&root, 80);


    #if 0
    /*Preorder traversal*/
    printf("\n PreOrder traversal\n");
    preorder(root);

    /*Inorder traversal*/
    printf("\n In Order traversal\n");
    inorder(root);
    /*Postorder traversal*/
    printf("\n Post Order traversal\n");
    postorder(root);
    #endif

        /*Inorder traversal*/
    printf("\n In Order traversal\n");
    inorder(root);

    printf("\n\n Delete 20 \n");
    root = bstNodeDelete(root, 20);
    printf("\n In Order traversal\n");
    inorder(root);
    printf("\n\n Delete 30 \n");
    root = bstNodeDelete(root, 30);
    printf("\n In Order traversal\n");
    inorder(root);

    printf("\n\n Delete 50 \n");
    root = bstNodeDelete(root, 50);
    printf("\n In Order traversal\n");
    inorder(root);

    return 0;
}
