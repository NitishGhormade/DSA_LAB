#include <stdio.h>
#include <stdlib.h>

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

void quicksort(struct arrayADT *a, int start, int end) {
    if (start < end) {
        int pivot = a->ptr[end];
        int i = start - 1;

        for (int j = start; j <= end - 1; j++) {
            if (a->ptr[j] < pivot) {
                i++;
                int temp = a->ptr[i];
                a->ptr[i] = a->ptr[j];
                a->ptr[j] = temp;
            }
        }

        int temp = a->ptr[i + 1];
        a->ptr[i + 1] = a->ptr[end];
        a->ptr[end] = temp;

        quicksort(a, start, i);
        quicksort(a, i + 2, end);
    }
}

void printArray(struct arrayADT *a){
    printf("\nPrinting Array: ");
    int i;
    for(i = 0;i < a->size;i++){
        printf("%d ",a->ptr[i]);
    }
}

void main() {
    struct arrayADT arr;
    create(&arr);
    insert(&arr,6);
    insert(&arr,3);
    insert(&arr,9);
    insert(&arr,7);
    insert(&arr,2);
    insert(&arr,1);
    printArray(&arr);
    quicksort(&arr,0,arr.size-1);
    printArray(&arr);
}