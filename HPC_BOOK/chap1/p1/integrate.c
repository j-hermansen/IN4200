
#include <stdio.h>
#include <time.h>

int main() {

    double steps = 1000000.0;         // number of steps to slice area in (horizontally)
    double sum = 0.0;               // keeps the total area calclulated under the curve
    double step = 1.0 / steps;
    double x;

    clock_t start = clock();
    for (int i = 0; i < steps; i++) {
        x = (i+0.5) * step;
        sum += ( 4.0 / (1.0 + x*x)) * step;
    }
    clock_t end = clock();
    double total = (double)(end - start)/CLOCKS_PER_SEC;

    printf("Time used: %lf\n", total);
    printf("sum: %.10lf\n", sum);
    printf("Flops: %3e\n", steps / total);

}

