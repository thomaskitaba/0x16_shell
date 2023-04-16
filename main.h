#ifndef MAIN_H
#define MAIN_H
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100
#define WORD_SIZE 100
#define WORD_COUNT 100
#define BUFFER_SIZE 1024

int _execve(char **av, char **env);
int _strtok(char *str, char *delim, char **token);
int _strlen(char *str);
void _free_2D(char **token, int rows);
int _get_word_count(char *str, char *delim);
int _strcspn(char *buf, char c);


#endif
