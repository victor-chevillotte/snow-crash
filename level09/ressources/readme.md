# Level09

## Objective
Exploit the `level09` executable to decipher the contents of the `token` file using a reverse script.

## Steps

### Step 1: Examine `level09` Output
Run the `level09` executable with a long string as input:

```bash
./level09 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
```

Observe the output, which appears to be a shifted version of the alphabet.

### Step 2: Reverse Script
Create a reverse script in C to decipher the contents of the `token` file:

```c
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
    return 0;
}
```

### Step 3: Compile and Run Reverse Script
Compile the reverse script:

```bash
gcc reverse.c -o reverse
```

Run the compiled reverse script with the `token` file:

```bash
./reverse token
```

### Step 4: Obtain Deciphered Token
The output of the reverse script should be the deciphered contents of the `token` file.

### Step 5: Switch to `flag09`
Attempt to switch to `flag09` with the deciphered token and execute `getflag`:

```bash
su flag09
getflag
```

This should give you the flag for this level.

Congratulations! You've successfully exploited the `level09` executable to decipher the contents of the `token` file and obtained the flag for `flag09`.