#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


int print_matching_words_iterative(char *sentence) {
    int count = 0;
    int start, end;

    for (int i = 0; sentence[i] != '\0';) {
        while (sentence[i] && !isalpha(sentence[i])) {
            i++;
        }

        if (sentence[i] == '\0') {
            break;
        }

        start = i;
        while (sentence[i] && isalpha(sentence[i])) {
            i++;
        }
        end = i - 1;

        // Check the word length (to ensure it has at least 3 characters)
        if (end - start + 1 < 3) {
            continue;
        }

        // Check if the first and last letters match (case-insensitive)
        if (tolower(sentence[start]) == tolower(sentence[end])) {
            for (int j = start; j <= end; j++) {
                putchar(sentence[j]);
            }
            printf("\n");
            count++;
        }
    }

    return count;
}

int main() {
    char sentence[256];

    printf("(iteration) Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }

    clock_t start_time = clock();

    int result = print_matching_words_iterative(sentence);
    printf("Number of words with the same first and last letter: %d\n", result);

    clock_t end_time = clock();

    double time_taken = ((double)end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to execute: %.6f seconds\n", time_taken);

    getchar();
    return 0;
}
