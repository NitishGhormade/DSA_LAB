#include<stdio.h>
#include<stdlib.h>

struct arrayADT
{
    int *ptr;
    int size;
};

void create(struct arrayADT *a){
    printf("Array Created\n");
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);
    a->size = n;
    a->ptr = (int *)malloc((a->size) * sizeof(int));
}

void setVal(struct arrayADT a){
    printf("\nSet Array\n");
    int num;
    for(int i = 0;i < a.size;i++){
        scanf("%d",&num);
        a.ptr[i] = num;
    }
}

void printVal(struct arrayADT a){
    printf("\nPrint Array\n");
    for(int i = 0;i < a.size;i++){
        printf("%d\n",a.ptr[i]);
    }
}

void insert(struct arrayADT *a){
    printf("To Insert Element\n");
    int idx,num;
    printf("Enter Element and the Index: ");
    scanf("%d%d",&num,&idx);

    (a->size)++;

    if(idx < 0 || idx > (a->size)-1){
        printf("Ivalid Index:");
        return;
    }

    a->ptr = (int*)realloc(a->ptr,(a->size) * sizeof(int));
    for(int i = (a->size)-1;i >= idx+1;i--){
        a->ptr[i] = a->ptr[i-1];
    }
    a->ptr[idx] = num;
}

void delete(struct arrayADT *a){
    printf("To Delete Element\n");
    int idx;
    printf("Enter the Index: ");
    scanf("%d",&idx);

    if(idx < 0 || idx > (a->size)-1){
        printf("Ivalid Index:");
        return;
    }

    for(int i = idx+1;i <= (a->size)-1;i++){
        a->ptr[i-1] = a->ptr[i];
    }
    (a->size)--;
    a->ptr = (int*)realloc(a->ptr,(a->size) * sizeof(int));
}

void merge(struct arrayADT *a1,struct arrayADT *a2){
    printf("\nMreging Array\n");
    int tsize = a1->size + a2->size;
    a1->ptr = (int*)realloc(a1->ptr,tsize * sizeof(int));

    for(int i = 0;i <= (a2->size)-1;i++){
        a1->ptr[i+(a1->size)] = a2->ptr[i]; 
    }
    a1->size = tsize;
}

void main(){
    struct arrayADT arr1;
    struct arrayADT arr2;
    create(&arr1);
    setVal(arr1);

    create(&arr2);
    setVal(arr2);

    merge(&arr1,&arr2); // Kisme Kisko Merge Karaycha Aahe
    printVal(arr1);

    // printVal(arr);
    // insert(&arr);
    // printVal(arr);
    // delete(&arr);
    // printVal(arr);
}