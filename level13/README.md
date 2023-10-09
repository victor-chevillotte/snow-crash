# Level13

In Level13, you are provided with a binary executable named `./level13`. When you execute it, you receive the following message:


UID 2013 started us but we expect 4242


This message suggests that the program expects to be run with a specific user ID (UID 4242), but it is currently executed with a different user ID (UID 2013).

To analyze the binary and exploit it, you open it with `gdb`:


gdb level13


Within the GDB prompt, you examine the program using the `disas main` command. This allows you to inspect the assembly code of the `main` function.

From the disassembled code, you observe that the program calls `getuid` at `<+9>`, compares the returned value against `0x1092` (4242) at `<+14>`, and performs a conditional jump at `<+19>` based on the comparison.

To exploit the program, you can directly manipulate the value of the `%eax` register, where the `getuid` function stores the user ID. You set a breakpoint at `<+14>` using the following commands:


break *main+14
run
p $eax


This sequence sets a breakpoint after the `getuid` function returns, runs the program, and displays the current value of the `%eax` register. It should show the user ID, which is 2013 by default.

To change the user ID to the expected value of 4242 and continue running the program, you use the following commands:


set $eax = 4242
next


## The flag

After making the change, you allow the program to continue executing. It prints your token:


2A31L79asukciNyi8uppkEuSx

