# Level01

## Objective
The goal is to log in to the `level01` account using the provided password: `flag00`.

## Steps

### Step 1: Examine `/etc/passwd`
Log in as `level01` using the provided password:

```bash
su level01
password: flag00
```

Explore the contents of the `/etc/passwd` file:

```bash
cat /etc/passwd
```

Most passwords are encrypted, and their corresponding hashes are stored in the shadow files. However, the `flag01` user's entry in the `/etc/passwd` file appears as follows:

```plaintext
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

### Step 2: Extract Hash and Decrypt with John the Ripper
Create a file named `key.txt` with the contents of the `flag01` entry:

```bash
echo "flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash" >> key.txt
```

Use John the Ripper to analyze the password hash and attempt to find the original password:

```bash
./john --show key.txt
```

Result:
```plaintext
Using default input encoding: UTF-8
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 256/256 AVX2])
Will run 4 OpenMP threads
Proceeding with single, rules:Single
Press 'q' or Ctrl-C to abort, 'h' for help, almost any other key for status
Almost done: Processing the remaining buffered candidate passwords, if any.
Warning: Only 663 candidates buffered for the current salt, minimum 1024 needed for performance.
0g 0:00:00:00 DONE 1/3 (2023-10-09 11:12) 0g/s 132600p/s 132600c/s 132600C/s flag01..Flag0159
Proceeding with wordlist:./password.lst
Enabling duplicate candidate password suppressor
abcdefg (flag01)
1g 0:00:00:00 DONE 2/3 (2023-10-09 11:12) 7.692g/s 199246p/s 199246c/s 199246C/s 123456..121082
Use the "--show" option to display all of the cracked passwords reliably
Session completed.
```

The password 'abcdefg' seems to be the correct one for `flag01`. Confirm it using:

```bash
su flag01
password: abcdefg
```

This should successfully log you in as `flag01`.