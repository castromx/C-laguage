#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* Develop a function that takes a character string (a sentence) as a parameter.
The function should print all the words from this sentence in which the first and
last letters match (case-insensitive) and return the number of found words. 
Enter several different sentences from the keyboard. Using the developed 
function, print all words from these sentences with matching first and last letters. */

int print_matching_words(char *sentence, int index, int count, int depth) {
    
    while (sentence[index] && !isalpha(sentence[index])) {
        index++;
    }

    if (sentence[index] == '\0') {
        return count;
    }

    // Determine the start and end of the word
    int start = index;
    while (sentence[index] && isalpha(sentence[index])) {
        index++;
    }
    int end = index - 1;

    // Check the word length (to ensure it has at least 3 characters)
    if (end - start + 1 < 3) {
        return print_matching_words(sentence, index + 1, count, depth + 1);  // Skip the word
    }

    // Check if the first and last letters match (case-insensitive)
    if (tolower(sentence[start]) == tolower(sentence[end])) {
        for (int i = start; i <= end; i++) {
            putchar(sentence[i]);
        }
        printf("\n");
        count++;
    }
    
    printf("recursion depth: %d \n", depth);
    return print_matching_words(sentence, index + 1, count, depth + 1);
}

int main() {
    char sentence[256];
    int recursion_count = 0;
    
    printf("(recursion) Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }

    clock_t start_time = clock();

    int result = print_matching_words(sentence, 0, 0, recursion_count);
    printf("Number of words with the same first and last letter: %d\n", result);
    
    clock_t end_time = clock();
    
    double time_taken = ((double)end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to execute: %.6f seconds\n", time_taken);
    
    getchar();
    return 0;
}
