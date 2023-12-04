#include<stdio.h>
#include<stdlib.h>

struct PQueue{
    int priority;
    int data;
    int front;
    int rear;
    int size;
};



void create(struct PQueue *pq,int size){
    pq->front = -1;
    pq->rear = -1;
    pq->size = size;
}

void min(){
    int size;
    printf("Enter the size of Queue: ");
    scnaf("%d",size);
    struct PQueue *pq[size];
    create(pq,size);
    
}