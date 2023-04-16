#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100 // Maximum number of words
#define MAX_WORD_LEN 100 // Maximum length of each word

void tokenizeString(char *str, char *delim, char **words, int *wordCount) {
    /*copy str not to lose z original*/
    char *str_cpy = strdup(str);
    char *word = strtok(str_cpy, delim);
    while (word != NULL && *wordCount < MAX_WORDS) {
        strcpy(words[*wordCount], word);
        (*wordCount)++;
        word = strtok(NULL, delim);
    }
}
int main(void) {
    char inputStr[] = "This is a sample string";
    char delim[] = " ";
    char **words;
    int wordCount = 0;
    // Allocate memory for two-dimensional array
    words = (char **)malloc(MAX_WORDS * sizeof(char *));
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = (char *)malloc(MAX_WORD_LEN * sizeof(char));
    }

    // Tokenize input string and store words in array
    tokenizeString(inputStr, delim, words, &wordCount);

    // Print the words
    printf("Words found: %d\n", wordCount);
    for (int i = 0; i < wordCount; i++) {
        printf("Word %d: %s\n", i+1, words[i]);
    }

    // Free allocated memory
    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}
