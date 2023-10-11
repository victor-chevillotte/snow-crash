# Level07

## Objective
Exploit the `level07` binary to execute the `getflag` command by injecting it into the `LOGNAME` environment variable.

## Steps

### Step 1: Examine `level07` Binary
Review the contents of the `level07` binary:

```bash
strings level07
```

Look for clues regarding how environment variables are used.

### Step 2: Identify `getenv` Function
Note that the `getenv` function is called, and it executes `/bin/echo %s`. This indicates that the value of an environment variable is printed.

### Step 3: Check Current Environment
Use the `env` command to check the current environment:

```bash
env
```

Find the `LOGNAME` variable and its value.

### Step 4: Exploit by Injecting `getflag`
Inject the `getflag` command into the `LOGNAME` environment variable:

```bash
export LOGNAME="\`getflag\`"
```

### Step 5: Execute `level07`
Run the `level07` binary:

```bash
./level07
```

### Step 6: Obtain Flag
The binary should now execute the `getflag` command, and you should see the flag.

Congratulations! You've successfully exploited the `level07` binary by injecting the `getflag` command into the `LOGNAME` environment variable.