In Level09, you are provided with an executable named `level09` and a `token` file. When you attempt to run the `level09` executable with a long string as input, you receive output that appears to be a shifted version of the alphabet:

./level09 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa



abcdefghijklmnopqrstuvwxyz{|}~�����������������


This suggests that the executable is performing a progressive cipher, commonly known as a rolling cipher. In this type of cipher, each character in the input is shifted by an increasing number of positions.
So we could rpovide a deciphered version of the token that could give us the flag
For this we use the reverse script :
ifconfig
get the token from vm : ```scp -P 4242 level09@[IP_HERE]:token .```
mv token level09/ressources/
gcc reverse.c 
chmod 777 token
./a.out token

```su leve10``` doesn't work with this token => ```su flag09``` -> ```getflag``` gives the flag for this level
