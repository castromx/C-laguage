#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int k, z, result;

    printf("Input z: ");
    scanf("%d", &z);
    getchar();

    printf("Input k: ");
    scanf("%d", &k);
    getchar();

    result = pow(z, 2*k - 1) + log(z - ((2*z - 3) / 5)) - sqrt(z);

    printf("result: %d\n", result);

    getchar();
    return 0;
}
