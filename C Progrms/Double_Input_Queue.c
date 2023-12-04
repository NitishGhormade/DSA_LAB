// Insertion from BOTH Sides but Deletion from LEFT Side

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

void enqueue_left(struct DEQueueADT *deq,int num){
    if(deq->front == -1 || deq->front == 0){
        printf("Queue is FULL(LEFT)\n");
    }
    else{
        deq->front--;
        deq->ptr[deq->front] = num;
    }
}
void enqueue_right(struct DEQueueADT *deq,int num){
    if(deq->rear == deq->size-1){
        printf("Queue is FULL(RIGHT)\n");
    }
    else{
        if(deq->rear == -1){
            deq->front = 0;
        }
        deq->rear++;
        deq->ptr[deq->rear] = num;
    }
}

void delete(struct DEQueueADT *deq){
    if(deq->rear == -1 || deq->front > deq->rear){
        printf("Queue is EMPTY");
    }
    else{
        deq->front++;
    }
}

void main(){
    struct DEQueueADT deq;
    create(&deq);

    enqueue_right(&deq,1);
    enqueue_right(&deq,2);
    enqueue_right(&deq,3);
    enqueue_right(&deq,4);
    enqueue_right(&deq,5);
    traverse(&deq);

    delete(&deq);
    delete(&deq);
    delete(&deq);
    traverse(&deq);

    enqueue_left(&deq,100);
    enqueue_left(&deq,200);
    enqueue_left(&deq,300);
    enqueue_left(&deq,400);
    traverse(&deq);

}