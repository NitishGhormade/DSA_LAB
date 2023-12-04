// Deletion from BOTH Sides but Intersion from LEFT Side

#include<stdio.h>
#include<stdlib.h>

struct DEQueueADT{
    int *ptr;
    int size;
    int front;
    int rear;
};

void create(struct DEQueueADT *deq){
    printf("Creating\n");
    printf("Enter the size of the DEQueue: ");
    scanf("%d",&deq->size);

    deq->ptr = (int *)malloc(deq->size * sizeof(int));

    deq->front = -1;
    deq->rear = -1;
}

void traverse(struct DEQueueADT *deq){
    printf("Traversing\n");
    if(deq->rear != -1){
        int i;
        for(i = deq->front;i <= deq->rear;i++){
            printf("%d\n",deq->ptr[i]);
        }
    }
}

void enqueue(struct DEQueueADT *deq,int num){
    if(deq->rear == deq->size-1){
        printf("Queue is FULL\n");
    }
    else{
        if(deq->rear == -1){
            deq->front = 0;
        }
        deq->rear++;
        deq->ptr[deq->rear] = num;
    }
}

void dequeue_left(struct DEQueueADT *deq){
    if(deq->rear == -1){
        printf("Queue is EMPTY(LEFT)\n");
    }
    else{
        if(deq->front == deq->rear){
            deq->front = -1;
            deq->rear = -1;
        }
        else{
            deq->front++;
        }
    }
}

void dequeue_right(struct DEQueueADT *deq){
    if(deq->rear == -1){
        printf("Queue is EMPTY(RIGHT)\n");
    }
    else{
        if(deq->front == deq->rear){
            deq->front = -1;
            deq->rear = -1;
        }
        else{
            deq->rear--;
        }
    }
}

void main(){
    struct DEQueueADT deq;
    create(&deq);

    enqueue(&deq,1);
    enqueue(&deq,2);
    enqueue(&deq,3);
    enqueue(&deq,4);
    enqueue(&deq,5);
    traverse(&deq);

    dequeue_left(&deq);
    dequeue_left(&deq);
    traverse(&deq);

    dequeue_right(&deq);
    dequeue_right(&deq);
    traverse(&deq);

    enqueue(&deq,100);
    enqueue(&deq,200);
    traverse(&deq);
}