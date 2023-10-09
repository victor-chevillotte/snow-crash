# Level00

In this level, the objective is to find the missing `README` file in the `/home` directory. The hint for this task is provided in a video on the intranet related to Snow Crash.

The `README` file, when viewed, gives a clue: "FIND the file that can be run by flag00." In other words, we need to locate a file that either belongs to or is readable by the user `flag00`.

To achieve this, we can use the `find` command with the following syntax:


find / -user flag00 2> /dev/null


Breaking down the command:
- `find`: This command is used to search for files and directories.
- `/`: Specifies the root directory as the starting point for the search.
- `-user flag00`: Filters the search to files owned by the user `flag00`.
- `2> /dev/null`: Redirects any error messages to `/dev/null`, effectively suppressing them.

When we run this command, we will find two files: `/usr/sbin/john` and `/rofs/usr/sbin/john`.

To decipher the next step, we can `cat` the contents of either of these files:


cat /usr/sbin/john


Or


cat /rofs/usr/sbin/john


This will display the following text:


cdiiddwpgswtgt


The provided text is encoded using a Caesar cipher. To decode it, we can use an online tool such as [dcode.fr](https://www.dcode.fr/caesar-cipher) that can automatically detect the shift. In this case, the shift is determined to be 15.

After decoding, the resulting text will give us the password for `flag00`:


nottoohardhere


Now that we have the password, we can switch to the `flag00` user using the `su` command:


su flag00


You will be prompted to enter the password, which is "nottoohardhere." After successfully switching to the `flag00` user, you can run the `getflag` command to retrieve the Level00 flag:


getflag


This will display the Level00 flag:


x24ti5gi3x0o12eh4esiuxias


