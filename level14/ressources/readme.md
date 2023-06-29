no real clue to start this level

```strings getflag``` shows a list of 15 strings that could be flags when ran through a modifier function

when decompiling getflag with ghidra (https://github.com/NationalSecurityAgency/ghidra), we come across a function called ft_des that transforms a strings and output it
=> extract the raw flag strings, extract ft_des and make a main that transforms all strings into flags

the 14 first outputed flags all correspond to flags found earlier => the 15th should be the flag we are looking for althought it is longer than previous flags