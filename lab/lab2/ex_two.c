#include <stdlib.h>
#include <stdio.h>

int main() {
    double sq = 1.428e2;
    int t = (int)(sq + 0.5);
    int u = -t / 10;

    // 2.1
    printf("2.1: ");
    if ((int)sq % 10 > ++t / 10) {
        printf("yes\n");
    } else {
        printf("no\n");
    
    getchar();

    // 2.2
    int result_2_2 = (u ^ t) | (~u << 5 & 0x2d6c);
    printf("2.2: %x\n", result_2_2);  
    getchar();
    }
    return 0;
}