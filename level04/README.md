# Level04

In Level04, you are presented with a Perl script that appears to be a CGI (Common Gateway Interface) script. The script has the following contents:


#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));


Let's break down the key observations from this script:

- It's a Perl script likely running as a CGI script.
- The comment `# localhost 4747` suggests that it might be currently running on the VM, specifically on port 4747.
- The script includes a `sub x` function that appears to execute a shell command: `echo $y 2>&1`.
- The `sub x` function is not called directly; it's invoked as `x(param("x"))`.
- The value of `$y` that is `echo`-ed is the result of the `param("x")` function.
- The `param()` function returns query values, and in this context, `param("x")` returns the value of the `x` parameter in a URL with the format `URL?x=value`.

To begin, you can check if the script is running by making a request to it using `curl`:


curl localhost:4747


If the script is running, you will receive a response.

To exploit the script, you want to manipulate the value of `$y` in the `x()` function by changing the value of the `x` parameter in the URL. You can do this by sending a request with a modified `x` parameter:


curl "localhost:4747?x=value"


As expected, `curl` will display the value "value" because the CGI script ran `echo value 2>&1` and returned the result.

Now, to retrieve the flag, you can exploit the script by running a command instead of just a string value for the `x` parameter. In this case, you can use `$(getflag)` to execute the `getflag` command:


curl "localhost:4747?x='$(getflag)'"


This command will execute `getflag` and retrieve the Level04 flag:


ne2searoevaevoem4ov4ar8ap
