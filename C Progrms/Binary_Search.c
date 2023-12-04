#include<stdio.h>
#include<stdlib.h>

struct arrayADT{
    int size;
    int *ptr;
};

void create(struct arrayADT *a){
    a->ptr = NULL;
    a->size = 0;
}

void insert(struct arrayADT *a,int data){
    a->size++;
    a->ptr = (int*)realloc(a->ptr,a->size * sizeof(int));
    a->ptr[a->size - 1] = data;
}

void BinarySearch(struct arrayADT *a,int data){
    printf("\nFinding for %d element\n",data);
    int start = 0;
    int end = a->size - 1;
    int mid;

    while(start <= end){
        mid = (start + end)/2;

        if(data == a->ptr[mid]){
            printf("Element found at: %d Index",mid);
            break;
        }
        else if(data < a->ptr[mid]){
            end = mid - 1;
        }
        else if(data > a->ptr[mid]){
            start = mid + 1;
        }
    }
    if(start > end){
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
    BinarySearch(&arr,300);
}