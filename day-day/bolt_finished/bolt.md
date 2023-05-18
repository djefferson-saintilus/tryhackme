# writeups

ip : 10.10.123.149


the port 80 have a service http apache who play on this but there is not any file like index(HOMEPAGE)

after a small nmap I discover this in nmap 

=== Nmap recon ===
```
PORT     STATE SERVICE REASON  VERSION
22/tcp   open  ssh     syn-ack OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
80/tcp   open  http    syn-ack Apache httpd 2.4.29 ((Ubuntu))
8000/tcp open  http    syn-ack (PHP 7.2.32-1)
```
the port 8000 have the CMS bolt, but we continue with the investigation. During my investigation I fall
on this messages

`Please check it out! my password is [boltadmin123] just incase you need it!` 

with this signature `Jake (Admin)` ( it just a false positive because the true username of admin is *bolt*), 
now I have to find the panel admin, I think I can try to find directory or look for google, with google I found 
the directory `/bolt/login`
--------------------
| user | password |
|bolt  |boltadmin123|
----------------------

When I arrived on this panel admin I noted the version of this cms who is *Bolt 3.7.1* and then I looked 
into find any vulnerability that can be exploit, and I found one who I can exploit it on metasploit,after 
that I have succeed to exploit the system and I found th *flag.txt* in the /home

*THM{wh0_d035nt_l0ve5_b0l7_r1gh7?}*

