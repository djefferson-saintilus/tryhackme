# writeups

`OS : Linux/Unix`


```
21/tcp    open  ftp     syn-ack
22/tcp    open  ssh     syn-ack
80/tcp    open  http    syn-ack
443/tcp   open  https   syn-ack
31337/tcp open  Elite   syn-ack

--targeted--
PORT      STATE SERVICE  REASON  VERSION
21/tcp    open  ftp      syn-ack vsftpd 3.0.3
22/tcp    open  ssh      syn-ack OpenSSH 7.6p1 Ubuntu 4 (Ubuntu Linux; protocol 2.0)
80/tcp    open  http     syn-ack Apache httpd 2.4.29
443/tcp   open  ssl/http syn-ack Apache httpd 2.4.29 ((Ubuntu))
31337/tcp open  Elite?   syn-ack

```
31337, seems to have a program, `The magic word is not "test"`, i entered test

jake,finn : `nothing in bruteforcing`


I finally got smething on the 443 port, so I connected to the ftp wit anon user,
and I got a lot images, and into these images I found a parameter called "XP comment"
in the metadata and the content was in binary

```
01111001 01101111 01110101 00100000  : you

01110010 01100101 01100001 01101100 01101100 01111001 00100000 : really

01101100 01101001 01101011 01100101 00100000 : like

01110100 01101111 00100000 : to

01110000 01110101 01111010 01111010 01101100 01100101 00100000 : puzzle

01100100 01101111 01101110 00100111 01110100 00100000 01111001 01100001 : don't ya

binary:decodedBinary
```

here I try to solve these one like I can, i make a gobuster with the famous wordlist, 
dir-list-medium, it seems work fine but it tooks a long to find the right directory,
```
grep "candybar" /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt -n  

46116:candybar
```
now a new thing `https://10.10.176.63/candybar/`, an image with a base32, but if you look
the source code you gonna find the same base32 so let's decode it, btw how i know it's base32
ofc go in the cyberChef and use magic filter,

```
KBQWY4DONAQHE53UOJ5CA2LXOQQEQSCBEBZHIZ3JPB2XQ4TQNF2CA5LEM4QHEYLKORUC4===

Palpnh rwtrz iwt HHA rtgixuxrpit udg rajth

```
but after that I go in dcode.fr to decode `ROT cipher` this new, and I got the result

```
[A-Z]+15	Always check the SSL certificate for clues
```
so let's go check what wrong with ssl certificate in our browser, this
`bubblegum@land-of-ooo.com` maybe we can use domain in like a host, so I did
it with the /etc/hosts after I back to the `https://<hostname>.com`, yh i was
fine until here, but another thing we have to found a new thing.

now try a dirListing of this new domain it seems but, it takes too long again, because
the ssl certif are bad,
```
grep "yellowdog" /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt -n       
44711:yellowdog
```
i just didn't have this patience to wait,
```
https://land-of-ooo.com/yellowdog/
```
remember to always sure you have https://, so now a new hind, and remember also
in the hind they said recursively dirListing, means for each dir we found, try to find
the other

```
grep "bananastock" /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt -n 
109256:bananastock
```
idk maybe this wordlist are a little crowded because it take too much time to find each 
one but you can use others, to go a little faster, but now we found a new image
that said he changed the password and give the password, but in morse code, so let's 
go on cyberchef to decode it, you'll find the morse in the source code

```
_/..../.\_.../._/_./._/_./._/...\._/._./.\_/..../.\_..././.../_/_._.__/_._.__/_._.__

THE BANANAS ARE THE BEST!!!
```
i did it with `from morse`(l : backslash, w : forward slash)(remove space), but now we have a password
but for what? maybe finn the ssh service or ftp, or but it just a thought so let's try to dirListing
again

```
186824:princess

https://land-of-ooo.com/yellowdog/bananastock/princess/
```
we got this one, and a new image that give us another hint, look the source code 
smthing interesting are there

```
    Secrettext = 0008f1a92d287b48dccb5079eac18ad2a0c59c22fbc7827295842f670cdb3cb645de3de794320af132ab341fe0d667a85368d0df5a3b731122ef97299acc3849cc9d8aac8c3acb647483103b5ee44166
    Key = my cool password
    IV = abcdefghijklmanopqrstuvwxyz
    Mode = CBC
    Input = hex
    Output = raw
```
so use cyberchef `aes decrypt` and everything will fine,
```
the magic safe is accessibel at port 31337. the magic word is: ricardio
```
so let's jump rith in, i connected with netcat `nc <ip> <port>`

```
Hello Princess Bubblegum. What is the magic word?
ricardio
The new username is: apple-guards

```

so now we know it's 100% ssh, just connect and here the 1st flag

1. `tryhackme{Th1s1sJustTh3St4rt}`

I found a file
```
cat mbox
From marceline@at  Fri Sep 20 16:39:54 2019
Return-Path: <marceline@at>
X-Original-To: apple-guards@at
Delivered-To: apple-guards@at
Received: by at.localdomain (Postfix, from userid 1004)
        id 6737B24261C; Fri, 20 Sep 2019 16:39:54 +0200 (CEST)
Subject: Need help???
To: <apple-guards@at>
X-Mailer: mail (GNU Mailutils 3.4)
Message-Id: <20190920143954.6737B24261C@at.localdomain>
Date: Fri, 20 Sep 2019 16:39:54 +0200 (CEST)
From: marceline@at

Hi there bananaheads!!!
I heard Princess B revoked your access to the system. Bummer!
But I'll help you guys out.....doesn't cost you a thing.....well almost nothing.

I hid a file for you guys. If you get the answer right, you'll get better access.
Good luck!!!!

```
