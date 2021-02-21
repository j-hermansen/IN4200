
#include <stdio.h>
#include <stdlib.h>

int main() {

    int x, y, z;
    int ***A;

    x = z = y = 3;

    A = (int ***)malloc(z * sizeof(int **));
    A[0] = (int **) malloc(z * y * sizeof(int *));
    A[0][0] = (int *)malloc(z * y * x * sizeof(int));

    for (int i = 1; i < z; ++i) {
        A[i] = &A[0][y * i];
    }

    for (int j = 1; j < z * y; ++j) {
        A[0][j] = &A[0][0][j * x];
    }

    for (int i = 0; i < z; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; z++) {
                A[i][j][k] = x * y * i + y * j + k;
                printf("(%d %d %d): %d ", i, j, k, A[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    free(A[0][0]);
    free(A[0]);
    free(A);




}
