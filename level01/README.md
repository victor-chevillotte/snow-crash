# Level01

In Level01, the goal is to find the password for the user `flag01` by examining the `/etc/passwd` file on the host machine. This file typically contains user account information, including encrypted password hashes. You can access the `/etc/passwd` file by running the following command:


cat /etc/passwd


When you inspect the contents of the `/etc/passwd` file, you'll notice that most passwords are encrypted, and their corresponding hashes are stored in the shadow files. However, the `flag01` user's entry in the `/etc/passwd` file looks like this:


flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash


This entry indicates that the password for the user `flag01` is stored in the `/etc/passwd` file itself, rather than in the shadow files. The password hash `42hDRfypTqqnw` is readily available.

To crack this password hash, you can use a password cracking tool like John the Ripper. Assuming you have John the Ripper installed on your machine, you can create a file called `passwd.txt` and store the `flag01` entry in it:


echo "flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash" > passwd.txt


Next, you can use John the Ripper to crack the password:


john passwd.txt


John the Ripper will analyze the password hash and attempt to find the original password. After a successful crack, you'll see the password for `flag01`, which, in this case, is revealed as:


abcdefg


Now that you have the password, you can switch to the `flag01` user using the `su` command:


su flag01


You will be prompted to enter the password, which is "abcdefg." After successfully switching to the `flag01` user, you can run the `getflag` command to retrieve the Level01 flag:


getflag


This will display the Level01 flag:


f2av5il02puano7naaf6adaaf
