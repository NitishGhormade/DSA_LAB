#include<stdio.h>
#include<stdlib.h>

struct CQueueADT{
    int *ptr;
    int size;
    int front;
    int rear;
};

void create(struct CQueueADT *cq){
    printf("Creating Circular Queue\n");
    printf("Enter the Size: ");
    scanf("%d",&(cq->size));

    cq->ptr = (int *)malloc(cq->size * sizeof(int));

    cq->front = -1;
    cq->rear = -1;
}

void traverse(struct CQueueADT *cq){
    printf("Traversing\n");
    int i;
    if(cq->front <= cq->rear){
        for(i = cq->front;i <= cq->rear;i++){
            printf("%d\n",cq->ptr[i]);
        }
    }
    else if(cq->rear < cq->front){
        for(i = cq->front;i <= cq->size-1;i++){
            printf("%d\n",cq->ptr[i]);
        }
        for(i = 0;i <= cq->rear;i++){
            printf("%d\n",cq->ptr[i]);
        }
    }
}

void enqueue(struct CQueueADT *cq,int num){
    if((cq->front==0 && cq->rear==cq->size-1) || (cq->rear+1==cq->front)){
        printf("\nCircular Queue is FULL\n");
    }
    else{
        if(cq->rear==-1 && cq->front==-1){
            cq->front=0;
        }
    
        cq->rear = (cq->rear + 1)%cq->size;
        cq->ptr[cq->rear] = num;
    }
}

void dequeue(struct CQueueADT *cq){
    if(cq->front==-1 && cq->rear==-1){
        printf("\nCircular Queue is EMPTY\n");
    }
    else{
        if(cq->rear == cq->front){
            cq->front = -1;
            cq->rear = -1;
        }
        else{
            cq->front = (cq->front + 1)%cq->size;
        }
    }
}

void main(){
    struct CQueueADT cq;

    create(&cq);

    enqueue(&cq,1);
    enqueue(&cq,2);
    enqueue(&cq,3);
    enqueue(&cq,4);
    enqueue(&cq,5);
    traverse(&cq);

    dequeue(&cq);
    dequeue(&cq);
    traverse(&cq);

    enqueue(&cq,100);
    enqueue(&cq,200);
    enqueue(&cq,300);
    traverse(&cq);
}