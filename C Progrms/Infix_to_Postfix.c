#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct stackADT{
    char *ptr;
    int TOP;
};

void create(struct stackADT *st,int size){
    st->TOP = -1;
    st->ptr = (char *)malloc(size * sizeof(char));
}

char POP(struct stackADT *st){
    char temp = st->ptr[st->TOP];
    st->TOP--;
    return temp;
}

void PUSH(struct stackADT *st,char ch){
    st->TOP++;
    st->ptr[st->TOP] = ch;
}

bool cheackAlph(char ch){
    if(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')){
        return true;
    }
    return false;
}

bool checkOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' || ch == '^'){
        return true;
    }
    return false;
}

int Priority(char ch){
    int p;
    switch (ch){
        case '^':
            p = 0;
            break;    
        case '-':
            p = 1;
            break;
        case '+':
            p = 1;
            break;        
        case '%':
            p = 2;
            break;
        case '/':
            p = 2;
            break;
        case '*':
            p = 2;
            break;
        default:
            break;
    }
    return p;
}

int checkPriority(struct stackADT *st,char ch){ // Return (1) if ch > st->ptr[st->TOP]
    if(Priority(st->ptr[st->TOP]) < Priority(ch)) return 1;
    else return 0;
}


void main(){
    struct stackADT st;
    create(&st,100);

    char infix[100];
    char postfix[100];

    printf("Enter the Infix Expression: ");
    scanf("%s",infix);
    
    PUSH(&st,'(');
    strcat(infix,")");
    strcpy(postfix,"");

    int i = 0;
    int j = 0; // Postfix Exp Counter
    while(infix[i] != '\0'){
        if(cheackAlph(infix[i])){
            postfix[j] = infix[i];
            j++;
        } 
        else if(checkOperator(infix[i])){
            if(checkPriority(&st,infix[i]) == 1) PUSH(&st,infix[i]);
            else{
                char temp;
                while(Priority(st.ptr[st.TOP]) >= Priority(infix[i])){
                    if(st.ptr[st.TOP] == '(') break;
                    temp = POP(&st);
                    postfix[j] = temp;
                    j++;
                }
                PUSH(&st,infix[i]);
            }
        }
        else if(infix[i] == '('){
            PUSH(&st,infix[i]);
        }
        else if(infix[i] == ')'){
            char ch;
            while((ch = POP(&st)) != '('){
                postfix[j] = ch;
                j++;
            }
        }
        i++;
    }

    postfix[j] = '\0';

    printf("Postfix Exp: %s",postfix);

    free(st.ptr);
}