# Level05

In Level05, when you log in as the `level05` user, you see a message indicating that you have new mail. To find this mail, you perform a quick investigation and discover that Linux emails are typically located in either `/var/mail` or `/var/spool`.

Upon further examination, you find a file named `/var/mail/level05`. Inside this file, you find a single line:


*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05


This line represents the format of a cron job, which allows you to schedule and run tasks periodically. In this case, the job runs every 2 minutes (`*/2 * * * *`) and executes the command `sh /usr/sbin/openarenaserver`. Importantly, it specifies that the job is executed as the user `flag05`.

To exploit this cron job, you need to understand what the `openarenaserver` script does. You examine the contents of the `/usr/sbin/openarenaserver` script:


#!/bin/sh

for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done


The script appears to iterate through files in the `/opt/openarenaserver` directory and executes them using `bash -x <FILENAME>`. This provides an opportunity to run arbitrary scripts.

To exploit the situation, you create a script that will run the `getflag` command and save the flag to a file. You can achieve this by running the following command:


echo 'getflag > /tmp/flag05.txt' > /opt/openarenaserver/script


This command creates a script named `script` in the `/opt/openarenaserver` directory. When this script is executed by the cron job, it runs the `getflag` command and redirects the output to a file named `/tmp/flag05.txt`.

## The flag

Two minutes after creating the `script`, the cron job executes it. You can then read the Level05 flag from the `/tmp/flag05.txt` file using the following command:


cat /tmp/flag05.txt


This will display the Level05 flag:


viuaaale9huek52boumoomioc
