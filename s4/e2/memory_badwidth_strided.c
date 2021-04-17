#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char *argv[]) {

    if (argc != 3) {
        puts("Specify a number as argument: ./program <number> <stride>");
        return EXIT_FAILURE;
    }

    int N = atoi(argv[1]);
    int stride = atoi(argv[2]);

    double *B = malloc(N * sizeof(*B));
    double *A = malloc(N * sizeof(*A));
    double s = 2.0;

    for (int i = 0; i < N; ++i) {
        B[i] = i;
    }

    clock_t start = clock();
    for (int i = 0; i < N; i += stride) {
        A[i] = s * B[i];
        printf("A[%d] = %lf * B[%d]\n", i, s, i);
    }
    clock_t end = clock();

    double total = (double)(end - start)/CLOCKS_PER_SEC;

    printf("Time: %lfms\n", 1000*total);
    int n_bytes = 2 * N * sizeof *A;
    printf("Bytes per sec: %3e\n", n_bytes/total);
    printf("Flops (Stride): %3e\n", N/total);

    free(A);
    free(B);

}