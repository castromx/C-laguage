#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// .
int main() {
    float x, term, R = 0, e = 10e-4;
    int i = 1;

    printf("Input positive number less than 1.5: ");
    scanf("%f", &x);
    getchar();
    if (x <= 0 || x > 1.5) {
        printf("Error, number must been: 0 < x <= 1.5.\n");
        getchar();
        return 1;
    }


    term = x;

    while (fabs(term) > e) {
        R += term;
        i++;
        printf("i = %d\n", i);
        printf("R = %f\n", R);
        term = -term * x / i;
    }
    getchar();
    printf("Sum of R = %f\n", R);

    getchar();

    return 0;
}
