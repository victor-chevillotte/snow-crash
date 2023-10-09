# Level08

In Level08, you are provided with an executable named `level08` and a `token` file that you cannot read initially. When you run the `./level08` executable, it prompts you to provide a file to read:


./level08 [file to read]


You attempt to read the `token` file directly by running:


./level08 token


However, you receive the message:


You may not access 'token'


Upon examining the `level08` executable using `strings`, you find a string that reads "token." It appears that the program has hardcoded the word "token" to prevent any file named "token" from being read directly.

To circumvent this restriction, you can use a symbolic link. Here are the steps to exploit the program:

1. Create a symbolic link from a location where you have read access to the `token` file. In this case, you create a symbolic link in the `/tmp` directory:


ln -sf /home/user/level08/token /tmp/link


This command creates a symbolic link named `/tmp/link` that points to the `token` file.

2. Run the `level08` executable with the symbolic link as the argument:


./level08 /tmp/link


By using the symbolic link, you trick the program into reading the contents of the `token` file.

## The flag

The program successfully reads the contents of the `token` file. While it's not the level's flag, the contents of the `token` file reveal the password for user `flag08`:


quif5eloekouj29ke0vouxean


With the password, you can switch to the `flag08` user using the `su` command:


su flag08


After successfully switching to the `flag08` user, you can run the `getflag` command to retrieve the Level08 flag:


getflag


This will display the Level08 flag:


25749xKZ8L7DkSCwJkT9dyv6f
