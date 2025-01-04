#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
} Node;

typedef int bool;
#define True 1;
#define False 0;

Node* create(int data){
    Node *tree = (Node *)malloc(sizeof(Node));
    if(!tree){
        printf("Error: Allocation failed!\n");
        exit(1);
    }
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

void preOrderTraversal(Node* tree){
    if(!tree){
        return;
    }
    printf("%d ", tree->data);
    preOrderTraversal(tree->left);
    preOrderTraversal(tree->right);
}

void inOrderTraversal(Node* tree){
    if(!tree){
        return;
    }
    inOrderTraversal(tree->left);
    printf("%d ", tree->data);
    inOrderTraversal(tree->right);
}

void postOrderTraversal(Node* tree){
    if(!tree){
        return;
    }
    postOrderTraversal(tree->left);
    postOrderTraversal(tree->right);
    printf("%d ", tree->data);
}

void freeNode(Node* tree){
    if(!tree){
        return;
    }
    freeNode(tree->left);
    freeNode(tree->right);
    free(tree);
}

void insert(Node** tree, int data){
    if(!*tree){
        *tree = create(data);
        return;
    }
    else if((*tree)->data == data){
        printf("Error: can't insert same data\n");
        return;
    }
    else if(data < (*tree)->data){
        insert(&(*tree)->left, data);
    }
    else if(data > (*tree)->data){
        insert(&(*tree)->right, data);
    }
    else{
        printf("Errro: some thing wrong!\n");
    }
}

bool search(Node* tree, int key){
    if(!tree){
        return False;
    }
    if(tree->data == key){
        return True
    }
    else if(key < tree->data){
        search(tree->left, key);
    }
    else {
        search(tree->right, key);
    }
}

int sizeTree(Node* tree){
    if(!tree){
        return 0;
    }
    return 1 + sizeTree(tree->left) + sizeTree(tree->right);
}

void delete(Node** tree, int key){
    if(!search(*tree, key)){
        return;
    }
    int i = -1;
    const int size = sizeTree(*tree);
    Node* haveLeft[size];
    Node* temp = *tree;
    Node* leaf;
    if((*tree)->data == key){
        while(temp){
            if(temp->right){
                temp = temp->right;
                if(temp->left){
                    haveLeft[++i] = temp;
                }
            }
        }
    }
}

void main(){
    Node* tree = NULL;

    insert(&tree, 48);
    insert(&tree, 15);
    insert(&tree, 69);
    insert(&tree, 89);

    inOrderTraversal(tree);
    printf("\n");

    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    if(search(tree, key)){
        printf("Can find %d in Tree\n", key);
    }else{
        printf("Can't find %d in Tree\n", key);
    }

    printf("%d\n", sizeTree(tree));

    freeNode(tree);
}