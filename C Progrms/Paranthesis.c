/*Application of stack; implementation of paranthesis checked*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stackADT{
    int size;
    int top;
    char *ptr;
};

void create(struct stackADT *st){
    st->size = 0;
    st->top = -1;
}

void PUSH(struct stackADT *st,char ch){
    st->size++;
    st->ptr = (char *)realloc(st->ptr,st->size * sizeof(char));
    st->top++;
    st->ptr[st->top] = ch;
}

void POP(struct stackADT *st){
    st->size--;
    st->ptr = (char *)realloc(st->ptr,st->size * sizeof(char));
    st->top--;
}

void main(){
    struct stackADT st;
    create(&st);

    int i;
    int flag = 0;

    char str[100];
    printf("Enter your expression: ");
    scanf("%s",str);

    for(i=0;i != strlen(str)+1;i++){
        if(str[i] == (char)40){
            PUSH(&st,str[i]);
        }
        if(str[i] == (char)41){
            if(st.size == 0){
                flag = 1;
                printf("The Expression has EXTRA CLOSING PARANTHESIS");
                break;
            }
            POP(&st);   
        }
    }

    if(flag == 0){
        if(st.size == 0) printf("The Expression is perfect");
        else printf("The Expression has EXTRA OPENING PARANTHESIS");
    }
}

