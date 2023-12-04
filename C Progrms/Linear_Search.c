#include<stdio.h>
#include<stdlib.h>

struct arrayADT{
    int size;
    int *ptr;
};

void create(struct arrayADT *a){
    a->size = 0;
    a->ptr = NULL;
}

void insert(struct arrayADT *a,int data){
    a->size++;
    a->ptr = (int*)realloc(a->ptr,a->size * sizeof(int));
    a->ptr[a->size - 1] = data;
}

void LinearSearch(struct arrayADT *a,int data){
    printf("\nFinding for %d element\n",data);
    int i;
    for(i = 0;i < a->size;i++){
        if(a->ptr[i] == data){
            printf("Element found at: %d Index",i);
            break;
        }
    }
    if(i == a->size){
        printf("Element NOT found");
    }
}

void printArray(struct arrayADT *a){
    int i;
    for(i = 0;i < a->size;i++){
        printf("%d ",a->ptr[i]);
    }
}

void main(){
    struct arrayADT arr;
    create(&arr);
    insert(&arr,1);
    insert(&arr,2);
    insert(&arr,3);
    insert(&arr,4);
    insert(&arr,5);
    printArray(&arr);
    LinearSearch(&arr,100);
}