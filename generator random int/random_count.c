#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int random(int start, int stop){
   return start + rand() % (stop - start + 1);
}


int read_int(int value, int attemp, int min, int max) {
    printf("Random number guessing using binary search\n");
    for (int i = 0; i < attemp; i++) {
        int target = (min + max) / 2;
        
        
        if (target < value) {
            printf("The guessed number %d is less than the actual value act min = %d, max = %d.\n", target, min, max);
            min = target + 1;
        }
        else if (target > value) {
            printf("The guessed number %d is greater than the actual value act min = %d, max = %d.\n", target, min, max);
            max = target - 1;
        }
        else {
            printf("Computer guessed the number %d correctly!\n", target);
            return 1;
        }
        printf("Attempt %d: Computer guesses %d\n", i + 1, target);
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
    printf("value is %d", value);
    if (read_int(value, attemp, min, max)) {
        printf("You win");
    }
    else {
        printf("You lose(");
    }
    getchar();
    return 0;
}
