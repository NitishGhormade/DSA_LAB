#include<stdio.h>
#include<stdlib.h>

struct stackADT{
    int size;
    int *ptr;
    int Top;
};

void create(struct stackADT *st){
    printf("\n-----------------Stack Created-----------------");
    printf("\nEnter the SIZE of the stack: ");
    scanf("%d",&(st->size));

    st->ptr = (int *)malloc(st->size * sizeof(int));

    st->Top = -1;
}

void Push(struct stackADT *st,int num){
    if((st->Top) < (st->size - 1)){
        printf("\nElement %d is Pushed",num);
        st->Top++;
        st->ptr[st->Top] = num;
    }
    else{
        printf("\n-----------------Stack Overflow----------------");
    }
}

int Pop(struct stackADT *st){
    printf("\n-----------------Poping-----------------");
    if(st->Top > -1){
        printf("\nElement %d is Poped",st->ptr[st->Top]);
        st->Top--;
        return st->ptr[st->Top+1];
    }
    else{
        printf("\n-----------------Stack Underflow-----------------");
        return -1;
    }
}

int Peek(struct stackADT *st){
    if(st->Top < 0){
        printf("\nStack Is Empty");
        return -1;
    }
    return st->ptr[st->Top];
}

void print(struct stackADT *st){
    printf("\nStack Print: ");
    for(int i=0;i <= st->Top;i++){
        printf("%d\t",st->ptr[i]);
    }
}

void main(){
    struct stackADT st;
    create(&st);
    Push(&st,1);
    Push(&st,2);
    Push(&st,3);
    Push(&st,4);
    int num;
    num = Pop(&st);
    num = Pop(&st);
    num = Pop(&st);
    num = Pop(&st);
    Push(&st,10);
    num = Peek(&st);
    printf("\nThe TOP Element After PEEK: ",num);
    num = Pop(&st);
    num = Peek(&st);
    
}


