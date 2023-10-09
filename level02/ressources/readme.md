the file level02.pcap is found in the home directory, 
Pcap is a data file generated when analysing network pakctes (sniff)
We can extract it for analysis using a custom script. 
The script uses scapy which is a famous network library
We download the .pcap file on our computer
ifconfig to get the ip
scp -P 4242 level02@192.168.56.2:level02.pcap .

python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt 
chmod 777 level02.pcap 
python pcap_script.py
And then launch the script : ft_wandr '\x7f' '\x7f' '\x7f' NDRel '\x7f' L0L
'\x7f' corresponds a key press of the delete key, when we delete each char that precedes '\x7f' we get the password :
=> ft_waNDReL0L 