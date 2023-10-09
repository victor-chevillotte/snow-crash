# Level03

In Level03, you are presented with a binary executable named `./level03`. When you execute this binary, it prints the message "Exploit me" to the standard output.

To understand how to exploit the binary, it's essential to examine its contents. You can assume that the message "Exploit me" is somewhere in the binary's code. One way to inspect the binary is to use the `strings` command to search for specific strings within it. In this case, you can search for the string "Exploit" by running the following command:


strings ./level03 | grep Exploit


This command reveals the string `/usr/bin/env echo Exploit me`. This string suggests that the binary is executing the `echo` command via `/usr/bin/env`, which is dependent on the `PATH` environment variable.

To exploit this situation, you can create a custom `echo` command that performs a different action, such as running `getflag`, and then modify the `PATH` variable to include the directory where your custom `echo` resides. Here are the steps to exploit the binary:

1. Create a custom `echo` script that executes `getflag`:
   

echo -e '#!/bin/bash\ngetflag' > /tmp/echo


2. Make the script executable:


chmod +x /tmp/echo


3. Override the `PATH` environment variable to include the directory where your custom `echo` script is located:


export PATH=/tmp:$PATH


4. Finally, execute the `./level03` binary:


./level03


When you run `./level03` with the modified `PATH`, it will execute your custom `echo` script instead of the standard `echo`. This custom script will then run `getflag`.

## The flag

As a result of this exploit, the binary will be tricked into executing `getflag`. You will receive the following flag:


qi0maab88jeaj46qoumi7maus


It's worth noting that this exploit works because `./level03` changes the current user to `flag03` internally by using functions like `seteuid()`. You can confirm this behavior by disassembling the `main` function using the `gdb` debugger:


gdb ./level03


Inside `gdb`, you can disassemble the `main` function using the `disas main` command.
