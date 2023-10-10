#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int ac, char **av)
{

    FILE*   ptr;
    char    chr;

    if (ac != 2)
    {
        printf("[usage] reverse [filepath]\n");
        exit(1);
    }
    
    char *filepath = av[1];
    ptr = fopen(filepath, "r");
    if (!ptr) {
        printf("unable to open file.\n");
        exit(1);
    }

    char *s;
    chr = 'a';
    int i = 0;
    while (!feof(ptr)) {
        chr = fgetc(ptr);
        chr = chr - i;
        write(1, &chr, 1);
        i++;
    }
    fclose(ptr);
    write(1, "\n", 1);
    return 0;
}