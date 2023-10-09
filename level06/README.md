# Level06

In Level06, you have two files in the home directory: a compiled PHP script named `level06` and its corresponding source code in `level06.php`. By inspecting the permissions using `ls -la`, you discover that the `level06` binary belongs to the user `flag06` and has the setuid (suid) bit set, meaning it can run with the permissions of its owner:


-rwsr-x---+ 1 flag06  level06 7503 Aug 30  2015 level06


To understand how to exploit this binary, you examine the source code in `level06.php`. The code can be summarized as follows:

1. The PHP script reads a file specified as its first argument (`$argv[1]`).
2. It performs several regular expression replacements on the content of the file.
3. The crucial vulnerability is on line 12, where it uses the `/e` modifier in the `preg_replace` function, allowing for the execution of code within the replacement.

With this knowledge, you can craft an input file that, when processed by the script, executes arbitrary code. Here's the plan:

1. Create a file named `/tmp/file.txt` with the following content:


[x ${${system($z)}}]


This content will match the regex pattern, and `${${system($z)}}` will execute the `system($z)` command, where `$z` is the second argument.

2. Execute the `level06` binary with the following command:


./level06 /tmp/file.txt getflag


In this command:
- `/tmp/file.txt` is the file you created.
- `getflag` is passed as the second argument (`$z`) to the script.

## The flag

When you run the script with the provided arguments, it executes the `system("getflag")` command. This command retrieves the Level06 flag:


wiok45aaoguiboiki2tuin6ub
