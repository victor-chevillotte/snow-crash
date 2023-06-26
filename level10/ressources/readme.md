The binary is using the access command to check if it is allowed to send the file to the specified host => exploit access 

The binary is a server sending the file in arg to specified host on port 6969

When testing the program with a dummy file and ```nc -l 6969```, we realize that it writes a header ".*( )*.\n" before sending the file
=> write a program that reads line by line to change file with a symbolic link just after the header is received


