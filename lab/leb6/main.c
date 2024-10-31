#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* #25 An array of unsigned one-byte numbers of size 10 is filled
   randomly with digits from 0 to 7, using random number generation
   functions. The values of the array elements form the octal code
   of a certain unsigned integer - we need to calculate the decimal
   value of this number. Print the generated octal code, the decimal
   value of the found number, and its octal format (specification %#o). */

// Function to fill the array with random numbers from 0 to 7
void fill_array(unsigned char *arr, int size) {
    for (int i = 0; i < size; i++) {
        *arr = rand() % 8;
        arr++;
    }
}

// Function to output the array as octal code
void print_octal(unsigned char *arr, int size) {
    printf("Octal code: ");
    for (int i = 0; i < size; i++) {
        printf("%u", *arr++);
    }
    printf("\n");
}

// Function to calculate the decimal value from the octal code
unsigned long calculate_decimal(unsigned char *arr, int size) {
    unsigned long decimal_value = 0;
    for (int i = 0; i < size; i++) {
        decimal_value = decimal_value * 8 + *arr++;
    }
    return decimal_value;
}

int main() {
    unsigned char arr[10];
    int size = 10;

    srand(time(0));

    // Fill the array with random numbers
    fill_array(arr, size);

    // Output the array as octal code
    print_octal(arr, size);
    getchar();

    // Calculate the decimal value
    unsigned long decimal_value = calculate_decimal(arr, size);

    // Print the decimal value and its octal format
    printf("Decimal value: %lu\n", decimal_value);
    printf("Octal format: %#lo\n", decimal_value);
    getchar(); 

    return 0;
}
