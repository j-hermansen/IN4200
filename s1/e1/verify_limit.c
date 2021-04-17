#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


void my_limit();
void uio_limit();

int main() {

    clock_t begin = clock();
    my_limit();
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time used on my function: %lf\n", time_spent);

    begin = clock();
    uio_limit();
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time used on uio function %lf\n", time_spent);

}

void my_limit() {
    double sum = 1.0;
    int i;

    for (i = 1; i < 20; i = i + 1) {
        double exp = 2 * i;

        sum = sum - ( (pow(-1, i+1))*(1.0 / pow(2.0, exp)) );
    }
}

void uio_limit() {
    int num_iter, n;

    num_iter = 20;
    n = 1;

    double tolerance, limit, current, add;

    limit = 4./5.;
    tolerance = 1e-12;
    current = add = 1.;

//    printf("Verifying that the series 1 - 2^(-2) + 2^(-4) - 2^(-6) + ... converges to %1.1f,\n" \
//           "summing up to %d terms and checking against a tolerance of %.1e.\n\n", limit, num_iter, tolerance);

    while (n ++ < num_iter && fabs(current - limit) > tolerance) {

        add *= -.25;
        current += add;
    }

    if (fabs(current - limit) > tolerance) {

//        printf("The series failed to converge within tolerance. Expected %f, vs. actual %f. \n", limit, current);
        EXIT_FAILURE;
    } else {
//        printf("The series converged as expected.  Number of terms required before sum within tolerance: %d. \n", n);
    }
}

