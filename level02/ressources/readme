the file level02.pcap is found in the home directory, we can extract it for analysis
the password for level02 is flag from level01 :
scp -P 4242 level02@192.168.56.2:level02.pcap .

we create a python script to read the pcap file, extraction of  'login : levelX, password' : ft_wandr '\x7f' '\x7f' '\x7f' NDRel '\x7f' L0L
'\x7f' corresponds a key press of the delete key, when we delete each char that precedes '\x7f' we get the password :
=> ft_waNDReL0L 