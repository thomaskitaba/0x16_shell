#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 1024
#define WORD_SIZE 1024
#define WORD_COUNT 100
#define BUFFER_SIZE 1024
/**
 * struct builtin - Struct op
 *
 * @string: The string
 * @builtin_f: The function associated
 */

int _putchar(char c);
int _execve(char **av, char **env);
int shell_loop_hsh(int argc, char **argv);
int _strtok(char *str, char *delim, char **token);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _free_2D(char **token, int rows);
char *create_buffer(void);
char **create_2D_buffer(char **av);
int _get_word_count(char *str, char *delim);
int (*get_builtin_cmd(char *s))(char **);
int _strcspn(char *buf, char c);
int hsh(int argc, char **argv);
char **tokenize_string(char *str, char **token, int *len);
int token(char **av, char *string);
int _exit_shell(char **string);
int _tokenize(char **av, char **argv, int argc);
int _strcspn(char *buf, char c);
char * add_path(char *path_arg, char *path_buffer);
void _print_2D(char **av, int argc);
int _printenv(char **env);

#endif
