#include<stdio.h>
#include<stdlib.h>

struct QueueADT{
    int *ptr;
    int size;
    int front;
    int rear;
};

void create(struct QueueADT *q){
    printf("--------------Creation of Queue--------------:\n");
    printf("Enter the size of the Queue: ");
    scanf("%d",&(q->size));

    q->ptr = (int*)malloc(q->size * sizeof(int));

    q->front = -1;
    q->rear = -1;
}

void enqueue(struct QueueADT *q,int num){
    printf("\n--------------Enqueue elements--------------");
    if(q->rear == q->size-1){
        printf("\n--------------Queue is FULL--------------\n");
    }
    else{
        if(q->rear == -1){
            q->front = 0;
        }
        q->rear++;
        q->ptr[q->rear] = num;
    }
}

void dequeue(struct QueueADT *q){
    printf("\n--------------Dequeue elements--------------");
    if(q->rear == -1){
        printf("\n--------------Queue is EMPTY--------------\n");
    }
    else{
        if(q->front == q->rear){
            q->front = -1;
            q->rear = -1;
        }
        else{
            q->front++;
        }
    }
}

int Peek(struct QueueADT *q){
    if(q->rear == -1){
        printf("\n---------------Queue is Empty---------------\n");
        return -1;
    }
    return q->ptr[q->front];
}

void traverse(struct QueueADT *q){
    printf("\nTreaversing: ");
    int i;
    if(q->rear != -1){
        for(i = q->front;i <= q->rear;i++){
            printf("%d  ",q->ptr[i]);
        }
    }
    else{
        printf("\n--------------Queue is Empty----------------");
    }
}

void main(){
    struct QueueADT q;

    create(&q);

    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    traverse(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    traverse(&q);
    int num;
    enqueue(&q,10);
    num = Peek(&q);
    printf("\nThe Elements PEEKD: ",num);
    dequeue(&q);
    num = Peek(&q);
    traverse(&q);
}