# find a clue

The binary file level06 and the php file level06.php are available in the home directory

Contents of the php file :

```#!/usr/bin/php
<?php
function y($m) { 
    $m = preg_replace("/\./", " x ", $m);
    $m = preg_replace("/@/", " y", $m);
    return $m;
}
function x($y, $z) {
    $a = file_get_contents($y);
    $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
    $a = preg_replace("/\[/", "(", $a);
    $a = preg_replace("/\]/", ")", $a);
    return $a;
}
$r = x($argv[1], $argv[2]); print $r;
?>```

-> flag06 is the owner of the file => we should exploit it to execute the getflag command
