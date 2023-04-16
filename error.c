#include <stdio.h>
#include <errno.h>

int main(void)
{
    FILE *file = fopen("nonexistent_file.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    // ...
    return (0);
}
