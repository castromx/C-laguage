#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;

    printf("Input 4-digit number: ");
    scanf("%d", &n);
    getchar();

    if ((n / 1000 == 0) || (n / 100 % 10 == 0) || (n / 10 % 10 == 0) || (n % 10 == 0)) {
        printf("Have 0\n");
    } else {
        printf("Don`t have 0\n");
    }

    getchar();

    return 0;
}
