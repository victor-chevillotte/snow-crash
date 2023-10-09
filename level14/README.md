# Level14

In Level14, you initially find nothing but an empty environment. You need to figure out how to exploit `getflag` itself to obtain the Level14 flag.

To start, you decide to perform a similar manipulation as in Level13 by changing the UID to trick `getflag` into thinking you are `flag14`.

Here are the steps to exploit `getflag`:

1. Open `getflag` with Cutter or any other reverse engineering tool to analyze its behavior.
2. Observe that there's a protection against reverse engineering done by calling `ptrace`. You'll need to find a way to bypass this.
3. Notice that a conditional jump occurs at `<+74>`. Set a breakpoint at this location.
4. The main program logic starts at `<+98>`. You should jump to this point to skip any reverse-engineering safeguards.
5. Identify that the check for `flag10` is right above the check for `flag14`. By running as `flag10`, you can minimize the number of changes required.
6. Locate the check for `UID == 3010` at `<+546>`. Set a breakpoint there, as this is where you will change the value of `eax` (the register where the UID is stored).

To perform these actions, follow these steps:

- Change your user to `flag10` using the `level10` token:


su flag10


- Open `getflag` in GDB:


gdb getflag


- Set your breakpoints and run the program:


disas main
break *main+74
break *main+546
run


- Jump to `<+98>` to bypass the reverse-engineering safeguard. The program will run until the next breakpoint, just before the UID check.

- Change the value of `eax` to 3014 (the UID for `flag14`) and continue executing the program:


jump *main+98
set $eax = 3014
next


## The flag

After executing these commands, `getflag` will finish executing, and you will obtain the `level14` flag:


7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
