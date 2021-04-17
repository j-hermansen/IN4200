
#include <stdio.h>
#include <stdlib.h>

int getLargestNumber(int arr[], int size) {
    int max = arr[0];
    int i;

    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int getSmallestNumber(int arr[], int size) {
    int min = arr[0];
    int i;

    for (i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int main() {
    int size = 10;
    int arr[size];

    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 101; // random number from 0 to 100
        printf("%d, ", arr[i]);
    }

    printf("\nLargest number in array: %d\n", getLargestNumber(arr, size));

    printf("\nSmallest number in array: %d\n", getSmallestNumber(arr, size));


}

