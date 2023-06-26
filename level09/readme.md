```./level09 token``` -> tpmhr

The command ```strings level09``` shows that getenv is used and the env variable LD_PRELOAD is read somewhere
It is also mentionned that we should not reverse this binary :)

LD_PRELOAD is a known linux exploit the escalate privilege => apply this exploit for this level ?

exploit file compilation needs a writable directory for gcc temp files :
```export TMPDIR=/run/shm```

```gcc -fPIC -shared -o /tmp/shell.so /tmp/shell.c -nostartfiles```

```/tmp/level09 /tmp/token``` -> /uos3yurmw

```/run/shm/level09 /run/shm/token``` -> /swq3xnt7}yvq{


```/level09 aaaaaaaaaaaaa``` -> abcdefghijklm


=> do a program that reverse the process to decode the token ?
