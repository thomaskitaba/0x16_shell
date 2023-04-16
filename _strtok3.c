#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


void _print_words(char **words, int numWords)
{
printf("Tokenized words:\n");
    for (int i = 0; i < numWords; i++) 
    {
        printf("%s\n", words[i]);
        free(words[i]); // Free the allocated memory for each word
    }
}
int splitStringIntoWords(const char *inputStr, char **words, char *delim) {
    int numWords = 0;

    // Make a copy of the input string to avoid modifying the original string
    char *inputStrCopy = strdup(inputStr);

    // Tokenize the input string
    char *token = strtok(inputStrCopy, delim);
    while (token != NULL && numWords < MAX_WORDS) {
        words[numWords] = strdup(token);
        numWords++;
        token = strtok(NULL, delim);
    }

    // Free the copy of input string
    free(inputStrCopy);

    return numWords;
}
int main() {
    char inputStr[] = "This is a sample string";
    char *words[MAX_WORDS];
    char *delim = " ";
    int numWords = splitStringIntoWords(inputStr, words, delim);
    // Print the words
    _print_words(words, numWords);
    return 0;
}
