#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node* create(struct Node *head,int data){
    printf("\n-----------------Starting Node Created-----------------\n");
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;
    head = ptr;
    return head;
}

struct Node* addAtFirst(struct Node *head,int data){
    printf("\n-----------------Insertion At First-----------------\n");
    printf("\nAdded at the First: %d\n",data);
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head->prev = temp;
    temp->prev = NULL;
    return temp;
}

struct Node* addAtLast(struct Node *head,int data){
    printf("\n-----------------Insertion At Last-----------------\n");
    printf("\nAdded at the Last: %d\n",data);
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    struct Node *ptr = head;

    while(ptr->next = NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    temp->next = NULL;
    return head;
}

struct Node* addAfterNode(struct Node *head,int dataOfNode,int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    struct Node *ptr = head;

    while(ptr->data != dataOfNode){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
    (temp->next)->prev = temp;
    return head; 
}

struct Node* addBeforeNode(struct Node *head,int dataOfNode,int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    struct Node *ptr = head;

    while(ptr->data != dataOfNode){
        ptr = ptr->next;
    }
    temp->prev = ptr->prev;
    temp->next = ptr;
    (temp->prev)->next = temp;
    ptr->prev = temp;
    return head;
}

struct Node* deleteFirst(struct Node *head){
    printf("\n-----------------Deletion At First-----------------\n");
    struct Node *temp = head;
    printf("\nDeleted at the First: %d\n",temp->data);
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

struct Node* deleteLast(struct Node *head){
    printf("\n-----------------Deletion At Last-----------------\n");
    struct Node *prePtr = head;
    struct Node *Ptr = head->next;
    
    while(Ptr->next != NULL){
        prePtr = prePtr->next;
        Ptr = Ptr->next;
    }
    prePtr->next = NULL;
    printf("\nDeleted at the Last: %d\n",Ptr->data);
    free(Ptr);
    return head;
}

struct Node* deleteBeforeNode(struct Node *head,int dataOfNode){
    struct Node *prePtr = head;
    struct Node *Ptr = head->next;

    while(Ptr->data != dataOfNode){
        Ptr = Ptr->next;
        prePtr = prePtr->next;
    }
    (prePtr->prev)->next = Ptr;
    Ptr->prev = prePtr->prev;
    free(prePtr);
    return head;
}

struct Node* deleteAfterNode(struct Node *head,int dataOfNode){
    struct Node *prePtr = head;
    struct Node *Ptr = head->next;

    while(prePtr->data != dataOfNode){
        prePtr = prePtr->next;
        Ptr = Ptr->next;
    }
    prePtr->next = Ptr->next;
    (Ptr->next)->prev = prePtr;
    free(Ptr);
    return head;
}

void traverse(struct Node *head){
    printf("\n-----------------Treversing the List-----------------\n");
    struct Node *ptr = head;
    while(ptr != NULL){
        printf("%d  ",ptr->data);
        ptr = ptr->next;
    }
}

void main(){
    struct Node *head = NULL;
    head = create(head,0);
    head = addAtFirst(head,1);
    head = addAtFirst(head,2);
    head = addAtLast(head,3);
    head = addAtLast(head,4);
    head = deleteFirst(head);
    head = deleteLast(head);
    traverse(head);
}