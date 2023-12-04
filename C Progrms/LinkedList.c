#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* create(struct Node *head,int data){
    printf("\n---------------Creating Strating Node---------------\n");
    printf("\nCreation Node: %d\n",data);
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
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
    return temp;
}

struct Node* addAtLast(struct Node *head,int data){
    printf("\n-----------------Insertion AT Last-----------------\n");
    printf("\nAdded at the Last: %d\n",data);
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    struct Node *p = head;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = temp;
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
    ptr->next = temp;
    return head;
}

struct Node* addBeforeNode(struct Node *head,int dataOfNode,int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    struct Node *prePtr = head;
    struct Node *Ptr = head;

    while(Ptr->data != dataOfNode){
        Ptr = Ptr->next;
        prePtr = prePtr->next;
    }
    prePtr->next = temp;
    temp->next = Ptr;
    return head;
}

struct Node* deleteFirst(struct Node *head){
    printf("\n------------------Deletion At First------------------\n");
    struct Node *p = head;
    printf("\nDeleted at the First: %d\n",p->data);
    head = head->next;
    free(p);
    return head;
}

struct Node* deleteAfterNode(struct Node *head,int noOfNode){
    struct Node *ptr = head;

    while(ptr->data != noOfNode){
        ptr = ptr->next;
    }
    ptr->next = (ptr->next)->next;
    return head;
}

struct Node* deleteBeforeNode(struct Node *head,int noOfNode){
    struct Node *ptr = head;

    while(((ptr->next)->next)->data != noOfNode){
        ptr = ptr->next;
    }
    ptr->next = (ptr->next)->next;
    return head;
}

struct Node* deleteLast(struct Node *head){
    printf("\n------------------Deletion At Last------------------\n");
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    printf("\nDeleting at the Last: %d\n",q->data);
    free(q);
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