#include<stdio.h>
#include<stdlib.h>

struct TNode{
    struct TNode *left;
    int data;
    struct TNode *right;
};

struct TNode* createTree(int data){
    struct TNode *ptr = (struct TNode*)malloc(sizeof(struct TNode));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void instertNode(struct TNode *root,int data){
    if(root == NULL){
        return;
    }
    else if(data < root->data){
        if(root->left == NULL){
            printf("\nNode Inserted with data %d in Left\n",data);
            root->left = createTree(data);
        }
        else{
            instertNode(root->left,data);
        }
    }
    else if(data > root->data){
        if(root->right == NULL){
            printf("\nNode Inserted with data %d in Right\n",data);
            root->right = createTree(data);
        }
        else{
            instertNode(root->right,data);
        }
    }
}

void InorderTreaversal(struct TNode *root){
    if(root == NULL){
        return;
    }

    InorderTreaversal(root->left);
    printf("%d ",root->data);
    InorderTreaversal(root->right);
}

void main(){
    int data = 5;
    printf("\nRoot Node Created with data %d\n",data);
    struct TNode *root = createTree(data);

    instertNode(root,3);
    instertNode(root,6);
    instertNode(root,4);
    instertNode(root,2);
    printf("Printing Inorder Traversal; ");
    InorderTreaversal(root);
}