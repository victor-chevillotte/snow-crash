# Level02

In Level02, you are given access to the home directory of the `level02` user, which is not empty. Inside this directory, you find a file named `level02.pcap`, which is a packet capture file. To analyze this file, you should first retrieve it from the remote host using the `scp` (secure copy) command. Assuming you are on your local machine, you can use the following command to copy it securely:


sudo scp -P 4242 level02@<SNOWCRASH_IP>:level02.pcap .


Replace `<SNOWCRASH_IP>` with the actual IP address of the Snow Crash server.

Once you have the `level02.pcap` file on your local machine, you can proceed to analyze it using Wireshark, a popular network protocol analyzer. Simply open the `level02.pcap` file in Wireshark to view its contents.

Inside Wireshark, you'll see a list of packet transmissions. To uncover the information you need, you can focus on the first packet by right-clicking it and selecting `Follow > TCP Stream`. This action will allow you to view the full exchange of data in that packet.

In the TCP stream, you'll notice that the server prompts the user with "Password:," and the client responds with "ft_wandr...NDRel.L0L."

Upon closer examination, you'll find that the non-printable characters (represented as `.`) in the response have a hex value of `7F`, which corresponds to the `DEL` (delete) key in ASCII.

This information suggests that the user made some mistakes while typing and corrected them using the `DEL` key. To determine the correct password, you can remove the letters typed before and after each `DEL` sequence:

- Remove "ndr" before the first `DEL` sequence.
- Remove "l" after the second `DEL` sequence.

After making these corrections, the password becomes:


ft_waNDReL0L


Now that you have the corrected password, you can switch to the `flag02` user using the `su` command:


su flag02


You will be prompted to enter the password, which is "ft_waNDReL0L." After successfully switching to the `flag02` user, you can run the `getflag` command to retrieve the Level02 flag:


getflag


This will display the Level02 flag:


kooda2puivaav1idi4f57q8iq
