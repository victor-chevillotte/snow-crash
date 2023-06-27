when i searched for flag00 I came across :
```cat /etc/passwd```
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash

if we extract what looks like a hash and decrypt it with 'john' :
./john flag01.txt
Warning: detected hash type "descrypt", but the string is also recognized as "descrypt-opencl"
Use the "--format=descrypt-opencl" option to force loading these as that type instead
Using default input encoding: UTF-8
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 128/128 AVX])
Proceeding with single, rules:Single
Press 'q' or Ctrl-C to abort, 'h' for help, almost any other key for status
Almost done: Processing the remaining buffered candidate passwords, if any.
Proceeding with wordlist:./password.lst
Enabling duplicate candidate password suppressor
abcdefg          (?)
1g 0:00:00:00 DONE 2/3 (2023-06-15 14:26) 5.882g/s 4517p/s 4517c/s 4517C/s raquel..bigman
Use the "--show" option to display all of the cracked passwords reliably
Session completed.

=> abcdefg seems to be the password

=>  $su flag01 confirms