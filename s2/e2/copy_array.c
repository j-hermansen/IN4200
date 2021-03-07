
#include <time.h>
#include <stdio.h>
#include <string.h>

const int SIZE = 4;

// Define functions
void handCodedArrayCopy(int arr[]);
void libArrayCopy(int arr[]);

int main() {

    int arr[] = {1, 9, 22, 12};

    clock_t begin = clock();
    handCodedArrayCopy(arr);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time used to copy array by hand: %lf\n", time_spent);

    begin = clock();
    libArrayCopy(arr);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time used to copy array by memcpy(): %lf\n", time_spent);

    return(0);
}

void handCodedArrayCopy(int arr[]) {

    int arr_cpy[SIZE];


    for (int i = 0; i < SIZE; ++i) {
        arr_cpy[i] = arr[i];
        printf("Copied array element nr %d: %d\n", i, arr_cpy[i]);
    }

}

void libArrayCopy(int arr[]) {

    int arr_cpy[SIZE];

    memcpy(arr_cpy, arr, SIZE*sizeof(int));

    for (int i = 0; i < SIZE; ++i) {
        printf("Copied array element nr %d: %d\n", i, arr_cpy[i]);
    }

}