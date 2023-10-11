# Level02

## Objective
Analyze the `level02.pcap` file to extract the password for the next level.

## Steps

### Step 1: Download and Setup
1. Download the `level02.pcap` file to your local machine:

   ```bash
   scp -P 4242 level02@192.168.56.2:level02.pcap .
   ```

2. Set up a virtual environment and install the required dependencies:

   ```bash
   python -m venv .venv
   source .venv/bin/activate
   pip install -r requirements.txt
   ```

3. Ensure the `level02.pcap` file has the necessary permissions:

   ```bash
   chmod +r level02.pcap
   ```

### Step 2: Run the Script
Run the provided Python script (`pcap_script.py`):

```bash
python pcap_script.py pc
```

We get a packet containing the string `'\x00\r\nPassword: '`, followed by these packets :  

- f
- t
- _
- w
- a
- n
- d
- r
- '\x7f' 
- '\x7f' 
- '\x7f' 
- N
- D
- R
- e
- l
- '\x7f' 
- L
- 0
- L


In this context, '\x7f' corresponds to a keypress of the delete key. By deleting each character that precedes '\x7f,' the password is revealed:

```plaintext
ft_waNDReL0L
```

This is the password for the next level (`flag02`). Use this password to proceed:

```bash
su flag02
password: ft_waNDReL0L
getflag
kooda2puivaav1idi4f57q8iq
```


You should now have access to the `level03` account.