#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int random(int start, int stop){
   return start + rand() % (stop - start + 1);
}


int read_int(int value, int attemp, int min, int max) {
    printf("Random count generator game \n");
    for (int i = 0; i<attemp; i++) {
        int target;
        target = min + rand() % (min - max + 1);
        if (target < value) {
            printf("Your targed is less than random value \n");
            min++;
        }
        else if (target > value) {
            printf("Your targed is greaten than random value \n");
            max++;
        }
        else {
            return 1;
        }
    }
    return 0;
}
int main(void) {
    srand(time(0));
    const int attemp = 10;
    const int min = 1;
    const int max = 100;
    printf("I generated for you count from %d to %d, you have %d attemps \n", min, max, attemp);
    int value = random(min, max);
    if (read_int(value, attemp)) {
        printf("You win");
    }
    else {
        printf("You lose(");
    }
    getchar();
    return 0;
}
