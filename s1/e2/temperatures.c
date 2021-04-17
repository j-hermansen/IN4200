
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // 1. create variables for max, min, avg temperatures, and one for counter
    double max, min, avg, counter = 0;
    char time[1000];
    char temp[1000];
    (double*) malloc(20 * sizeof(double));

    char line[255];

    // 2. Read from file
    FILE *fptr;

    if ((fptr = fopen("temp-data.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    max = 0.0, min = 0.0;

    while (fgets(line, 255, fptr) != NULL) {

        strtok(line, " ");
        char * token = strtok(NULL, " ");
        double nr = atof(token);

        if (nr > max) {
            max = nr;
        } else if (nr < min) {
            min = nr;
        }

        printf("%f\n", nr);

    }

    printf("\nMax: %.1f\n", max);
    printf("Min: %.1f\n", min);

    fclose(fptr);

    return 0;

}

