#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TNode{
    int data;
    struct TNode *left;
    struct TNode *right;
};

struct TNode* create(int data){
    struct TNode *ptr = (struct TNode*)malloc(sizeof(struct TNode));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void InOrder(struct TNode *root){
    // if(root != NULL){
    //     InOrder(root->left);
    //     printf("%d ",root->data);
    //     InOrder(root->right);
    // }

    if(root == NULL){
        return;
    }
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

int num = 0;
bool isBST(struct TNode *root){
    if(root == NULL){
        return;
    }

    isBST(root->left);
    if(num < root->data){
        num = root->data;
    }
    else{
        return false;
    }
    isBST(root->right);
}

void main(){
    struct TNode *root = create(5);
    struct TNode *p1 = create(3);
    struct TNode *p2 = create(6);
    struct TNode *p3 = create(2);
    struct TNode *p4 = create(4);

    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;

    if(isBST(root)){
        printf("NOT BST");
    }
    else{
        printf("YES BST");
    }
}