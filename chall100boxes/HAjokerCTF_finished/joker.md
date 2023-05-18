# writeups

```
22/tcp   open  ssh     syn-ack OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 ad201ff4331b0070b385cb8700c4f4f7 (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDL89x6yGLD8uQ9HgFK1nvBGpjT6KJXIwZZ56/pjgdRK/dOSpvl0ckMaa68V9bLHvn0Oerh2oa4Q5yCnwddrQnm7JHJ4gNAM+lg+ML7+cIULAHqXFKPpPAjvEWJ7T6+NRrLc9q8EixBsbEPuNer4tGGyUJXg6GpjWL5jZ79TwZ80ANcYPVGPZbrcCfx5yR/1KBTcpEdUsounHjpnpDS/i+2rJ3ua8IPUrqcY3GzlDcvF7d/+oO9GxQ0wjpy1po6lDJ/LytU6IPFZ1Gn/xpRsOxw0N35S7fDuhn69XlXj8xiDDbTlOhD4sNxckX0veXKpo6ynQh5t3yM5CxAQdqRKgFF
|   256 1bf9a8ecfd35ecfb04d5ee2aa17a4f78 (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBOzF9YUxQxzgUVsmwq9ZtROK9XiPOB0quHBIwbMQPScfnLbF3/Fws+Ffm/l0NV7aIua0W7FLGP3U4cxZEDFIzfQ=
|   256 dcd7dd6ef6711f8c2c2ca1346d299920 (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIPLWfYB8/GSsvhS7b9c6hpXJCO6p1RvLsv4RJMvN4B3r
80/tcp   open  http    syn-ack Apache httpd 2.4.29 ((Ubuntu))
| http-methods: 
|_  Supported Methods: GET POST OPTIONS HEAD
|_http-server-header: Apache/2.4.29 (Ubuntu)
|_http-title: HA: Joker
8080/tcp open  http    syn-ack Apache httpd 2.4.29
|_http-title: 401 Unauthorized
|_http-server-header: Apache/2.4.29 (Ubuntu)
Service Info: Host: localhost; OS: Linux; CPE: cpe:/o:linux:linux_kernel
```
port 80, I use gobuster and dirsearch
```
[19:09:38] 200 -    6KB - /index.html                                       
[19:10:07] 200 -   94KB - /phpinfo.php  
/secret.txt 
```


content of secret.txt
```
Batman hits Joker.
Joker: "Bats you may be a rock but you won't break me." (Laughs!)
Batman: "I will break you with this rock. You made a mistake now."
Joker: "This is one of your 100 poor jokes, when will you get a sense of humor bats! You are dumb as a rock."
Joker: "HA! HA! HA! HA! HA! HA! HA! HA! HA! HA! HA! HA!"
```

users possible: Joker,Batman

after that i tried to hydra on the 8080 port, who have an authentifaction

`[8080][http-get] host: 10.10.218.236   login: joker   password: hannah`


I found this hint
```
To login to your site use the user name and password that were created 
as part of the installation process. Once logged-in you will be able to 
create and edit articles and modify some settings.
```
but nothing works, after reading the hind I found the `/administrator/`,

==dirlisting 8080 port===
```
/images               (Status: 301) [Size: 322] [--> http://10.10.218.236:8080/images/]
/index.php            (Status: 200) [Size: 10949]
/.php                 (Status: 403) [Size: 280]
/media                (Status: 301) [Size: 321] [--> http://10.10.218.236:8080/media/]
/templates            (Status: 301) [Size: 325] [--> http://10.10.218.236:8080/templates/]
/modules              (Status: 301) [Size: 323] [--> http://10.10.218.236:8080/modules/]
/bin                  (Status: 301) [Size: 319] [--> http://10.10.218.236:8080/bin/]
/plugins              (Status: 301) [Size: 323] [--> http://10.10.218.236:8080/plugins/]
/includes             (Status: 301) [Size: 324] [--> http://10.10.218.236:8080/includes/]
/language             (Status: 301) [Size: 324] [--> http://10.10.218.236:8080/language/]
/README               (Status: 200) [Size: 4494]
/README.txt           (Status: 200) [Size: 4494]
/components           (Status: 301) [Size: 326] [--> http://10.10.218.236:8080/components/]
/cache                (Status: 301) [Size: 321] [--> http://10.10.218.236:8080/cache/]
/libraries            (Status: 301) [Size: 325] [--> http://10.10.218.236:8080/libraries/]
/robots               (Status: 200) [Size: 836]
/robots.txt           (Status: 200) [Size: 836]
...
```
I found a lot of dir but the one that i'm interested to not, while using nikto with the new
creds I got
`+ /backup.zip: Potentially interesting backup/cert file found. . ` and I use wget to download
this file into my machine

`└─$ wget http://10.10.218.236:8080/backup.zip --http-user joker --http-password hannah`, 

`[backup.zip] db/joomladb.sql password:`, backpu file has some password required, let's try to
bruteforce like said the hint using zip2john binary, after that the password was
`hannah           (backup.zip)` so after I use grep look for any users and I found one
`grep "user" ./<Filedb.sql>"`, here the result
```
cc1gr_users,Super Duper User','admin','admin@example.com','$2y$10$b43UqoH5UpXokj2y9e/8U.LD8T3jEQCuxG2oHzALoJaj9M5unOcbG'
```
now let's try to crack the password, and I got an amazing result `abcd1234`, that's the password,
then now we can connect to the joomla administation panel with creds "admin:abcd1234", and here
the panel admin so now we can plan/upload a revshell, Templates>Site>beez3 so after going through
this path I copy/paste the revshell code into the index.php and after TEMPLATE PREVIEW, to execute
the shell.


`uid=33(www-data) gid=33(www-data) groups=33(www-data),115(lxd)`
the group maybe a little bizarre, so after that I only read an article abt how to 
get the root priv and I got the flag, here the article

`https://www.hackingarticles.in/lxd-privilege-escalation/`

and one of writeup helped me a lot when I struggled

https://drf0x.github.io/HAJokerCTF

