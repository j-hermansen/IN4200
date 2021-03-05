
#include <stdio.h>
#include <stdlib.h>


int main() {

    int size = 3;
    int arr[size][size];

    int i;

    for(i = 0; i < size; i++) {
        arr[i][0] = rand() % 101;
        arr[i][1] = rand() % 101;
        arr[i][2] = rand() % 101;

        printf("%d %d %d ", arr[i][0], arr[i][1], arr[i][2]);
    }
    printf("\n-------------------------\n");

    int row, col;

    printf("Outerloop rows, inneloop columns:\n----------------------------\n");
    for (row = 0; row < size; row++) {
        for (col = 0; col < size; col++) {
            printf("%d ", arr[row][col]);
        }
    }

    printf("\nOuterloop columns, inneloop rows:\n----------------------------\n");
    for (col = 0; col < size; col++) {
        for (row = 0; row < size; row++) {
            printf("%d ", arr[row][col]);
        }
    }
    printf("\n");




}