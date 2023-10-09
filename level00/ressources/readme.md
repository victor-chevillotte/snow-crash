Login to level00. password is given : level00


find all files executable by user flag00 (hidden intra video)

```find / -group flag00 2>/dev/null```

```bash /usr/sbin/john```
=> /usr/sbin/john: line 1: cdiiddwpgswtgt: command not found

```cat /usr/sbin/john```
cdiiddwpgswtgt

filename 'john' suggests we hack its contents with the 'john' software mentionned in the intra video
https://github.com/openwall/john

=> fail : does not seems to be a hash

decode with dcode website : https://www.dcode.fr/chiffre-cesar
caesar method output this list of possible passwords :
🠞15 (🠜11)	nottoohardhere
🠞14 (🠜12)	opuuppibseifsf
🠞2 (🠜24)	abggbbunequrer
🠞11 (🠜15)	rsxxsslevhlivi
🠞21 (🠜5)	hinniibulxbyly
🠞8 (🠜18)	uvaavvohykolyl
🠞4 (🠜22)	yzeezzslcospcp
🠞3 (🠜23)	zaffaatmdptqdq
🠞18 (🠜8)	klqqllexoaebob
🠞24 (🠜2)	efkkffyriuyviv
🠞5 (🠜21)	xyddyyrkbnrobo
🠞1 (🠜25)	bchhccvofrvsfs
🠞25 (🠜1)	dejjeexqhtxuhu
🠞22 (🠜4)	ghmmhhatkwaxkx
🠞17 (🠜9)	lmrrmmfypbfcpc
🠞9 (🠜17)	tuzzuungxjnkxk
🠞19 (🠜7)	jkppkkdwnzdana
🠞16 (🠜10)	mnssnngzqcgdqd
🠞10 (🠜16)	styyttmfwimjwj
🠞20 (🠜6)	ijoojjcvmyczmz
🠞12 (🠜14)	qrwwrrkdugkhuh
🠞6 (🠜20)	wxccxxqjamqnan
🠞7 (🠜19)	vwbbwwpizlpmzm
🠞13 (🠜13)	pqvvqqjctfjgtg
🠞23 (🠜3)	fgllggzsjvzwjw

the first 'nottoohardhere' seems to be the correct one and authenticate user flag00



