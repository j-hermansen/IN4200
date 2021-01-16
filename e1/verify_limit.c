
#include <stdio.h>
#include <math.h>

int main() {

    double sum = 1.0;
    int i;

    for (i = 1; i < 20; i = i + 1) {
        double exp = 2 * i;

        if (i % 2 == 0) {
            sum = sum + (1.0 / pow(2.0, exp));
        } else {
            sum = sum - (1.0 / pow(2.0, exp));
        }

        printf("The sum is %f\n", sum);


}

