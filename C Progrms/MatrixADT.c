#include <stdio.h>
#include <stdlib.h>

int main() {
    int row1 = 3, col1 = 2;
    int *mat1[row1];
    mat1[0] = (int *)malloc(col1 * sizeof(int));
    mat1[1] = (int *)malloc(col1 * sizeof(int));
    mat1[2] = (int *)malloc(col1 * sizeof(int));

    int row2 = 3, col2 = 2;
    int *mat2[row2];
    mat2[0] = (int *)malloc(col2 * sizeof(int));
    mat2[1] = (int *)malloc(col2 * sizeof(int));
    mat2[2] = (int *)malloc(col2 * sizeof(int));

    printf("Enter matrix 1: ");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Matrix 1:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    // Free memory for mat1
    for (int i = 0; i < row1; i++) {
        free(mat1[i]);
    }

    printf("Enter matrix 2: ");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("Matrix 2:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    // Free memory for mat2
    for (int i = 0; i < row2; i++) {
        free(mat2[i]);
    }

    return 0;
}
