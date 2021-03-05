
#include <stdio.h>
#include <math.h>


// Limit of 1 - (1 / 2^2) + (1 / 2^4) - (1 / 2^6) + ...
int main() {

    double sum = 1.0;
    int i;

    for (i = 1; i < 20; i = i + 1) {
        double exp = 2 * i;

        sum = sum - ( (pow(-1, i+1))*(1.0 / pow(2.0, exp)) );

        printf("The sum is %f\n", sum);

    }
}

