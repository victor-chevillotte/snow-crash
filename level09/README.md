# Level09

In Level09, you are provided with an executable named `level09` and a `token` file. When you attempt to run the `level09` executable with a long string as input, you receive output that appears to be a shifted version of the alphabet:


abcdefghijklmnopqrstuvwxyz{|}~�����������������


This suggests that the executable is performing a progressive cipher, commonly known as a rolling cipher. In this type of cipher, each character in the input is shifted by an increasing number of positions.

To decipher the `token` file, you examine its hexadecimal representation using the `hexdump` command:


hexdump -C token


The output shows the hexadecimal values of the token:


00000000  66 34 6b 6d 6d 36 70 7c  3d 82 7f 70 82 6e 83 82  |f4kmm6p|=..p.n..|
00000010  44 42 83 44 75 7b 7f 8c  89 0a                    |DB.Du{....|
0000001a


Trimming the data to keep the useful bytes, you get:


66 34 6b 6d 6d 36 70 7c 3d 82 7f 70 82 6e 83 82 44 42 83 44 75 7b 7f 8c 89


To reverse the cipher, you can create a Python script that performs the decryption. Here's a Python script to accomplish this:


#!/usr/bin/env python3

hexdump = "66 34 6b 6d 6d 36 70 7c 3d 82 7f 70 82 6e 83 82 44 42 83 44 75 7b 7f 8c 89"

res = ""
for offset, hex in enumerate(hexdump.split()):
    n = int(hex, 16) - offset
    res += chr(n)

print(res)


When you run the script, it deciphers the token:


./decipher.py


You get the following output:


f3iji1ju5yuevaus41q1afiuq


## The flag

Now that you have deciphered the token, you can use it as the password to switch to the `flag09` user:


su flag09


After successfully switching to the `flag09` user, you can run the `getflag` command to retrieve the Level09 flag:


getflag


This will display the Level09 flag:


s5cAJpM8ev6XHw998pRWG728z
