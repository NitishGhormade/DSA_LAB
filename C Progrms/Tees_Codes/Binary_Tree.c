#include <stdio.h>
#include <stdlib.h>
 
struct TNode{
    struct TNode *left;
    struct TNode *right;
    int data;
};

int lidx = 1;
int iidx = 0;

struct TNode* root = NULL;

struct TNode* level[50];

struct TNode* insert(int data){
    struct TNode* TNode = (struct TNode *)malloc(sizeof(struct TNode));
        TNode->data = data;
        TNode->left=NULL;
        TNode->right=NULL;

    if(root==NULL){
        printf("\nRoot Node Created with data %d\n",data);
        level[iidx] = TNode;
        root = TNode;
        return root;
    }
    else if(level[iidx]->left==NULL){
        printf("\nInserting in left of %d\n",level[iidx]->data);
        level[iidx]->left=TNode;
        level[lidx++]=TNode;
        return root;
    }
    else if(level[iidx]->right==NULL){
        printf("\nInserting in right of %d\n",level[iidx]->data);
        level[iidx++]->right=TNode;
        level[lidx++]=TNode;
        return root;
    }
    return root;
}

void InorderTraversal(struct TNode *ptr){
    if(ptr == NULL){
        return;
    }
    InorderTraversal(ptr->left);
    printf("%d ",ptr->data);
    InorderTraversal(ptr->right);
}

void main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    printf("\nPrinting Inorder Traversal of the tree: ");
    InorderTraversal(root);
}
