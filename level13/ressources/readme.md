Executing ./level13 gives this output : "UID 2013 started us but we we expect 4242"
=> set uid to 4242 before executing the program

=> exploit the getuid function with LD_PRELOAD lib that redefines it to return 4242

preload lib 
```export TMPDIR=/run/shm```

```gcc -fPIC -shared -o /tmp/fake_uid.so /tmp/fake_uid.c -nostartfiles```

```export LD_PRELOAD="/tmp/fake_uid.so"```

we can check that the lib is loaded with ```ldd level13```

however it does not work directly because the binary is SUID => find a way  to execute it without suid permissions


when we run in gdb to bypass suid binary preload protection :
```gdb level13``` then ```run```
we get the flag : 2A31L79asukciNyi8uppkEuSx

```su level14```
