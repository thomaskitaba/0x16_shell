#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 1024
#define WORD_SIZE 1024
#define WORD_COUNT 100
#define BUFFER_SIZE 1024

int _putchar(char c);
int _execve(char **av, char **env);
int _strtok(char *str, char *delim, char **token);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
void _free_2D(char **token, int rows);
char *create_buffer(void);
int _get_word_count(char *str, char *delim);
int _strcspn(char *buf, char c);
int hsh(int argc, char **argv);
char **tokenize_string(char *str, char **token, int *len);
int _tokenize(char **av, char **argv, int argc);
int _strcspn(char *buf, char c);
char * add_path(char *path_arg, char *path_buffer);
void _print_2d(char **av, int argc);
#endif
