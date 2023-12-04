#include<stdio.h>
#include<stdlib.h>

struct stackADT{
    int *ptr;
    int size;
    int Top;
};

void create(struct stackADT *st){
    st->Top = -1;
    st->size = 0;
}

void PUSH(struct stackADT *st,int num){
    st->size++;

    st->ptr = (int *)realloc(st->ptr,st->size * sizeof(int));

    st->Top++;

    st->ptr[st->Top] = num;
}

int POP(struct stackADT *st){
    if(st->Top != -1){
        int temp = st->ptr[st->Top];
        printf("\nElement %d POPED: ",temp);
        st->Top--;
        st->size--;
        st->ptr = (int *)realloc(st->ptr,st->size * sizeof(int));
        return temp;
    }
    else{
        printf("\nStack is EMPTY");
    }
}

int PEEK(struct stackADT *st){
    return st->ptr[st->Top];
}

void print(struct stackADT *st){
    printf("\nPrint STACK");
    for(int i=0;i <= st->Top;i++){
        printf("\n%d",st->ptr[i]);
    }
}

void main(){
    struct stackADT st;

    create(&st);

    PUSH(&st,1);
    PUSH(&st,2);
    PUSH(&st,3);
    PUSH(&st,4);
    PUSH(&st,5);

    print(&st);

    POP(&st);
    POP(&st);
    POP(&st);

    print(&st);
}