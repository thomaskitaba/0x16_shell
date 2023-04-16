#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ; // Declare the environ global variable

int main(int argc, char **argv) {
    // Accessing and printing environment variables using environ
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    // Accessing the value of the "COMPUTERNAME" environment variable
    char *computer_name = getenv("COMPUTERNAME");
    if (computer_name != NULL) {
        printf("COMPUTERNAME: %s\n", computer_name);
    } else {
        printf("COMPUTERNAME environment variable not found\n");
    }

    return 0;
}
