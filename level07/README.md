# Level07

In Level07, you are provided with an executable file. To understand how to exploit it, you start by examining it using the `gdb` debugger. While analyzing the executable, you notice that it calls several functions, including `getegid`, `geteuid`, `setresgid`, `setresuid`, `getenv`, `asprintf`, and `system`.

To gather more information about the executable, you use the `strings` command to extract printable strings from it:


strings ./level07


Among the strings, you discover the following:


/bin/echo %s


This appears to be a `printf` formatting string. Based on your observations in `gdb`, it seems like the program constructs a command using `asprintf` and `system`. The constructed command might look like this:


char *buf;
asprintf(&buf, "/bin/echo %s", getenv(SOME_ENV_VALUE));
system(buf);


Additionally, in the `strings` output, you see the string `LOGNAME` located right above `/bin/echo %s`. When you execute the program without modification, it prints "level07," and a quick check with `env | grep level07` confirms the presence of the `LOGNAME` environment variable:


LOGNAME=level07


To exploit this situation, you can manipulate the `LOGNAME` environment variable to execute the `getflag` command. You set the `LOGNAME` variable to `'$(getflag)'` as follows:


export LOGNAME='$(getflag)'


Then, you run the `level07` executable:


./level07


## The flag

As a result of this manipulation, the program is successfully exploited. It executes the `system("/bin/echo $(getflag)")` command. You receive the Level07 flag:


fiumuikeil55xe9cu4dood66h
