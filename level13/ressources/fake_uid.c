#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int getuid() {
    printf("fake getuid() called\n");
    return 4242;
}

void _init() {
printf("preload lib\n");
}