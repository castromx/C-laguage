#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int formIntArray(float startArray[], int lenArray, int finishArray[]) {
    int finishArrayLen = 0;

    for (int i = 0; i < lenArray; i++) {
        int roundedValue = (int)round(startArray[i]);
        bool exists = false;

        for (int j = 0; j < finishArrayLen; j++) {
            if (finishArray[j] == roundedValue) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            finishArray[finishArrayLen++] = roundedValue;
        }
    }

    return finishArrayLen;
}


int main() {
    float startArray[45];
    int finishArray[45];
    int lenArray;

    printf("Enter the number of array elements (no more than 45): ");
    scanf("%d", &lenArray);

    if (lenArray > 45 || lenArray <= 0) {
        printf("Incorrect number of elements.\n");
        getchar(); 
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < lenArray; i++) {
        scanf("%f", &startArray[i]);
    }

    int newArray = formIntArray(startArray, lenArray, finishArray);

    printf("Formed array:\n");
    for (int i = 0; i < newArray; i++) {
        printf("%d ", finishArray[i]);
    }
    getchar();
    printf("\n");
    getchar(); 
    return 0;
}
