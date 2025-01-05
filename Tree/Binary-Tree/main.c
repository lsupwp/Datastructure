#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

typedef int bool;
#define True 1;
#define False 0;

Node *create(int data)
{
    Node *tree = (Node *)malloc(sizeof(Node));
    if (!tree)
    {
        printf("Error: Allocation failed!\n");
        exit(1);
    }
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

void preOrderTraversal(Node *tree)
{
    if (!tree)
    {
        return;
    }
    printf("%d ", tree->data);
    preOrderTraversal(tree->left);
    preOrderTraversal(tree->right);
}

void inOrderTraversal(Node *tree)
{
    if (!tree)
    {
        return;
    }
    inOrderTraversal(tree->left);
    printf("%d ", tree->data);
    inOrderTraversal(tree->right);
}

void postOrderTraversal(Node *tree)
{
    if (!tree)
    {
        return;
    }
    postOrderTraversal(tree->left);
    postOrderTraversal(tree->right);
    printf("%d ", tree->data);
}

void freeNode(Node *tree)
{
    if (!tree)
    {
        return;
    }
    freeNode(tree->left);
    freeNode(tree->right);
    free(tree);
}

void insert(Node **tree, int data)
{
    if (!*tree)
    {
        *tree = create(data);
        return;
    }
    else if ((*tree)->data == data)
    {
        printf("Error: can't insert same data\n");
        return;
    }
    else if (data < (*tree)->data)
    {
        insert(&(*tree)->left, data);
    }
    else if (data > (*tree)->data)
    {
        insert(&(*tree)->right, data);
    }
    else
    {
        printf("Errro: some thing wrong!\n");
    }
}

bool search(Node *tree, int key)
{
    if (!tree)
    {
        return False;
    }
    if (tree->data == key)
    {
        return True
    }
    else if (key < tree->data)
    {
        search(tree->left, key);
    }
    else
    {
        search(tree->right, key);
    }
}

int sizeTree(Node *tree)
{
    if (!tree)
    {
        return 0;
    }
    return 1 + sizeTree(tree->left) + sizeTree(tree->right);
}

Node* findMin(Node* root){
    while(root && root->left){
        root = root->left;
    }
    return root;
}

void delete(Node** tree,int key){
    if(!(*tree)){
        return ;
    }
    Node* temp = *tree;
    if(key < temp->data){
        delete(&temp->left, key);
    }else if(key > temp->data){
        delete(&temp->right, key);
    }else{
        if(!temp->left && !temp->right){
            free(temp);
            *tree = NULL;
        }
        else if(!temp->left){
            Node* child = temp->right;
            free(temp);
            *tree = child;
        }
        else if(!temp->right){
            Node* child = temp->left;
            free(temp);
            *tree = child;
        }else{
            Node* successor = findMin(temp->right);
            temp->data = successor->data;
            delete(&(temp->right), successor->data);
        }
    }
}

void main()
{
    Node *tree = NULL;

    while(1){
        int choice;
        printf("Enter a menu: ");
        scanf("%d", &choice);
        if(choice == 0){
            break;
        }

        switch (choice)
        {
        case 1:
            int data_i;
            printf("Enter a daat you want to insert: ");
            scanf("%d", &data_i);
            insert(&tree, data_i);
            break;
        
        case 2:
            int data_d;
            printf("Enter a daat you want to delete: ");
            scanf("%d", &data_d);
            delete(&tree, data_d);
            break;
        
        case 3:
            inOrderTraversal(tree);
            printf("\n");
            break;
        
        default:
            break;
        }
    }

    freeNode(tree);
}
