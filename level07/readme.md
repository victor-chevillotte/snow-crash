# binary

only level07 binary is present in the home
it prints 'level07' when executed

```strings level07``` shows that the function getenv is called

the binary is owned by flag07 so we can try to inject the getflag call in the env variable
there is a variable in the env that prints level07 => $LOGNAME

if we inject `getflag` in this variable with the command : ```export LOGNAME="\`getflag\`"``` we get the flag !

