# Level10

In Level10, you are provided with an executable named `level10` and a `token` file that you cannot read initially. When you run the `level10` executable, it displays a usage message indicating that you should provide a file and a host:


./level10 file host
        sends file to host if you have access to it


You attempt to use the executable by creating a file `/tmp/myfile` and running the command:


./level10 /tmp/myfile 127.0.0.1


This command is an attempt to send your file to your own IP address, but you receive the following error message:


Connecting to 127.0.0.1:6969 .. Unable to connect to host 127.0.0.1


The executable appears to be sending the contents of the specified file to port `6969`.

To exploit the program, you set up a `netcat` listener to capture incoming connections and data. In a separate terminal, you run:


nc -lk localhost 6969


With the listener in place, running `./level10 /tmp/myfile 127.0.0.1` allows you to send the contents of `/tmp/myfile` to the listener.

## The exploit

Further examination of the `level10` executable using `ltrace` reveals important information: it first checks if you have the rights to open the file and then proceeds to open it. This behavior can be exploited using a TOCTOU (Time Of Check, Time Of Use) attack.

The idea behind the TOCTOU attack is to gain permission for file access and then quickly change the file to something else before it's opened. To achieve this, you can use a symbolic link named `/tmp/link` that alternates between pointing to `/tmp/myfile` and `./token`.

You create two Python scripts for this exploit:

1. A script to continuously run the `level10` executable, sending the contents of `/tmp/link` to the listener:


import os

while True:
    os.system('./level10 /tmp/link 127.0.0.1')


2. A script to change the target of `/tmp/link` alternately between `/tmp/myfile` and `./token`:


import os

while True:
    os.system('ln -sf /tmp/myfile /tmp/link')
    os.system('ln -sf /home/user/level10/token /tmp/link')


With both scripts running in separate terminals, you exploit the executable. The continuous switching of the `/tmp/link` symbolic link's target fools the program into sending the contents of `./token` to the listener before it can be switched back to `/tmp/myfile`.

Within milliseconds, the `nc` listener displays the desired content:


woupa2yuojeeaaed06riuj63c


## The flag

You use this content as the password to switch to the `flag10` user:


su flag10


After successfully switching to the `flag10` user, you run the `getflag` command to retrieve the Level10 flag:


getflag


This displays the Level10 flag:


feulo4b72j7edeahuete3no7c
