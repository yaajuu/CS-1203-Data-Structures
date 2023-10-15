#include <stdio.h>  
#include <stdlib.h>  

struct Node  
{  
    int key;  
    struct Node *left;  
    struct Node *right;  
    int height;  
};  

int getHeight(struct Node *n)  
{  
    if(n == NULL)  
        return 0;  
    return n->height;  
}  

struct Node *createNode(int key)  
{  
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));  
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  
    return node;  
}  

void displayTree(struct Node* root, int space)
{
    int i;

    if (root == NULL) return;

    space += 10;

    displayTree(root->right, space);

    
    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    displayTree(root->left, space);
}

int max (int a, int b)
{  
    return (a > b) ? a : b;  
}  

int getBalanceFactor(struct Node * n)
{  
    if(n == NULL)
        return 0;  
    return getHeight(n->left) - getHeight(n->right);  
}  

struct Node* rightRotate(struct Node* y)
{  
    struct Node* x = y->left;  
    struct Node* T2 = x->right;  

    x->right = y;  
    y->left = T2;  

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  

    return x;  
}  

struct Node* leftRotate(struct Node* x)
{  
    struct Node* y = x->right;  
    struct Node* T2 = y->left;  

    y->left = x;  
    x->right = T2;  

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  

    return y;  
}  

struct Node *insert(struct Node* node, int key)
{  
    if (node == NULL)
        return createNode(key);  

    if (key < node->key)  
        node->left  = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));  
    int bf = getBalanceFactor(node);  

    if(bf > 1 && key < node->left->key)
    {  
        return rightRotate(node);  
    }  

    if(bf < -1 && key > node->right->key)
    {  
        return leftRotate(node);  
    }  

    if(bf > 1 && key > node->left->key)
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  

    if(bf < -1 && key < node->right->key)
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  

    return node;  
}  

void preOrder(struct Node *root)
{  
    if(root != NULL)
    {  
        printf("%d ", root->key);  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

void inOrder(struct Node *root)
{  
    if(root != NULL)
    {  
        inOrder(root->left);  
        printf("%d ", root->key);  
        inOrder(root->right);  
    }  
}

struct Node *delete(struct Node *node, int key) //removes a node and restores the tree so that its balanced again
{
    if (node == NULL) //if its empty means nothing can be deleted
        return NULL;

    if (key < node->key)
        node->left = delete(node->left, key); //if its less that the current key, we search left subtree
    else if (key > node->key)
        node->right = delete(node->right, key); //if its > that the current key, we search right subtree
    else  //when the node to be deleted is found:
    {
        if ((node->left == NULL) || (node->right == NULL)) //if its a leaf node or has one child(on the left), we update node with its child if it has one
        {
            struct Node *temp = node->left ? node->left : node->right;

            if (temp == NULL) //if it has both children, we find min of the one in the right subtree and replaces current key with the min key. delete one with min key
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;

            free(temp);
        }
        else //if it has both children, we find min of the one in the right subtree and replaces current key with the min key. delete one with min key
        {
            struct Node *temp = node->right;

            while (temp->left != NULL)
                temp = temp->left;

            node->key = temp->key;

            node->right = delete(node->right, temp->key);
        }
    }

    if (node == NULL)
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right)); //recalcuate height of current node after deletions
    int bf = getBalanceFactor(node);

    if (bf > 1 && getBalanceFactor(node->left) >= 0) //check if there are rotations to make 
        return rightRotate(node);

    if (bf > 1 && getBalanceFactor(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node); //if left side is taller we rotate to the right
    }

    if (bf < -1 && getBalanceFactor(node->right) <= 0) //if right side is taller we rotate to the left
        return leftRotate(node);

    if (bf < -1 && getBalanceFactor(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; //all changes have been made and node is returned and tree is maintained
}

int main() {  
    struct Node * root = NULL;  
   
    root = insert(root, 2);  
    root = insert(root, 4);  
    root = insert(root, 6);  
    root = insert(root, 8);  
    root = insert(root, 10);  
    root = insert(root, 12);  
    root = insert(root, 14);  
    root = insert(root, 16);  
    root = insert(root, 18);  
    
    printf("the AVl tree without deleting an element:");
    displayTree(root, 10);
    
    printf("\n");


    printf("the AVl tree AFTER deleting an element:");
    root = delete(root, 12);
    

    displayTree(root, 10);

    return 0;  
}  
