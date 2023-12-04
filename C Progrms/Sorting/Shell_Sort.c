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

void shellsort(struct arrayADT *a, int n, int gap) {
    if (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = a->ptr[i];
            int j = i;
            
            while (j >= gap && a->ptr[j - gap] > temp) {
                a->ptr[j] = a->ptr[j - gap];
                j = j - gap;
            }

            a->ptr[j] = temp;
        }

        shellsort(a, n, gap / 2);
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
    shellsort(&arr,arr.size,arr.size/2);
    printArray(&arr);
}
