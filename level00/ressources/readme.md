# Level00

## Objective
The goal is to log in to the `level00` account with the provided password: `level00`. Additionally, find all files executable by the user `flag00` (hidden intra video).

## Steps

### Step 1: Locate Executable Files
Use the following command to find all files executable by the user `flag00` (hidden intra video):

```bash
find / -group flag00 2>/dev/null
```

### Step 2: Investigate 'john' Software
Execute the following commands to explore the 'john' software:

```bash
bash /usr/sbin/john
```

Result:
```
/usr/sbin/john: line 1: cdiiddwpgswtgt: command not found
```

View the contents of 'john':

```bash
cat /usr/sbin/john
```

Result:
```
cdiiddwpgswtgt
```

### Step 3: Decode with 'dcode' Website
The filename 'john' suggests hacking its contents with the 'john' software mentioned in the intra video. However, the contents do not seem to be a hash.

Decode using the Caesar method on the 'dcode' website: [dcode website](https://www.dcode.fr/chiffre-cesar).

Possible Passwords:
- 🠞15 (🠜11) nottoohardhere
- 🠞14 (🠜12) opuuppibseifsf
- 🠞2 (🠜24) abggbbunequrer
- 🠞11 (🠜15) rsxxsslevhlivi
- 🠞21 (🠜5) hinniibulxbyly
- 🠞8 (🠜18) uvaavvohykolyl
- 🠞4 (🠜22) yzeezzslcospcp
- 🠞3 (🠜23) zaffaatmdptqdq
- 🠞18 (🠜8) klqqllexoaebob
- 🠞24 (🠜2) efkkffyriuyviv
- 🠞5 (🠜21) xyddyyrkbnrobo
- 🠞1 (🠜25) bchhccvofrvsfs
- 🠞25 (🠜1) dejjeexqhtxuhu
- 🠞22 (🠜4) ghmmhhatkwaxkx
- 🠞17 (🠜9) lmrrmmfypbfcpc
- 🠞9 (🠜17) tuzzuungxjnkxk
- 🠞19 (🠜7) jkppkkdwnzdana
- 🠞16 (🠜10) mnssnngzqcgdqd
- 🠞10 (🠜16) styyttmfwimjwj
- 🠞20 (🠜6) ijoojjcvmyczmz
- 🠞12 (🠜14) qrwwrrkdugkhuh
- 🠞6 (🠜20) wxccxxqjamqnan
- 🠞7 (🠜19) vwbbwwpizlpmzm
- 🠞13 (🠜13) pqvvqqjctfjgtg
- 🠞23 (🠜3) fgllggzsjvzwjw

The first password, 'nottoohardhere,' seems to be the correct one to authenticate user `flag00`.