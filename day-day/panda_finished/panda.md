# writeups


first I discover some user like *shifu* : this user I found it in the source 
code of the website on 80 port, and the other one is *po* and *tigress* : I got 
them when I accessed to the machine.
 
===recon===  
`WordPress 4.7.16`

this was the 1st flag that I got
```
Hex : 5a4449794d4745314e475a694d6d59775a6a41344f4755335a5749324d7a526d5957526a5a4751354e32593d 

to

base64 : ZDIyMGE1NGZiMmYwZjA4OGU3ZWI2MzRmYWRjZGQ5N2Y= 

to the flag : d220a54fb2f0f088e7eb634fadcdd97f

```
just a little decoding

===wpscan====
```
[+] WordPress theme in use: twentyseventeen
 | Location: http://panda.thm/wordpress/wp-content/themes/twentyseventeen/
 | [!] The version is out of date, the latest version is 2.8
 | Found By: Css Style In Homepage (Passive Detection)

[+] The external WP-Cron seems to be enabled: http://panda.thm/wordpress/wp-cron.php
 | Found By: Direct Access (Aggressive Detection)
 
 
[+] Performing password attack on Xmlrpc against 1 user/s
^Cying shifu / starfish Time: 00:10:07 <> (1708 / 14344392)  0.01%  ETA: ??:??:??
[i] No Valid Passwords Found.
```


===dir listing===
```
/index.html (Status: 200)
/wordpress (Status: 301)
/flag 
```

===hydra cracking===
`[22][ssh] host: 10.10.119.232   login: shifu   password: batman`


===GTFobins====
(root) /usr/bin/ftp


===wp-config===
```
/** MySQL database username */
define('DB_USER', 'root');

/** MySQL database password */
define('DB_PASSWORD', 'password123');
```


smb:users 
Anonymous
