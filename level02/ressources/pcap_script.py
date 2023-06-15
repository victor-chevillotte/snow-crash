from scapy.all import *

packets = rdpcap("level02.pcap")
print(packets)
# print(packets.summary())
for i, packet in enumerate(packets):
    # res = hexdump(packet)
    print(i, packet.sprintf("{Raw:%Raw.load%\n}"))
