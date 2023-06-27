The lua file is a server asking for a password and comparing its sha1sum to : f05d1d066fb246efe0c6f7d095f909a7a0cf34a0
=> find the password with that sha1sum by comparing it to a database with https://www.dcode.fr/hash-sha1
we get => `NotSoEasy`

it doesn't work by imputing the password with ending /n so we can try ```echo -n NotSoEasy | nc localhost 5151``` => doesn't work
command injection in the echo as previous flag with redirect to file because the output is piped to sha1sum : $(getflag > /tmp/flag)
=> gives token : fa6v5ateaw21peobuub8ipe6s