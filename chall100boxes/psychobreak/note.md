# writeups

===Information gatherin===

source code of index.html
```
	<!-- Sebastian sees a path through the darkness which leads to a room => /sadistRoom -->
```
/sadistRoom

the new page, `Key to locker Room => 532219a04ab7a02b56faafbec1a4c1ea`, also a 
link `https://theevilwithin.fandom.com/wiki/Sadist`, in the same page, below
you'll see a 'script.js', when I look into I saw
```
(".btn-danger").click(function(e) {
	const key = prompt("Enter Key To The Locker Room ");
	if (key == "532219a04ab7a02b56faafbec1a4c1ea"){
		window.open("../lockerRoom/","_self")
	}
});
```
http://10.10.211.64/lockerRoom/
now I'm in the locker room, a new key but we have to decode it first 
```
Tizmg_nv_zxxvhh_gl_gsv_nzk_kovzhv

Grant_me_access_to_the_map_please
```
I use this website to get into this key https://www.boxentriq.com/code-breaking/atbash-cipher

after that new page, map.php where we supposed to put the key, and now we have 2 new pages
safe heaven and abandonedroom, safe heaven have some pictures, nd adbandonedroom asking for
keeperKey

let's take a look more further with safeheaven source code, I found a commend
```
<!-- I think I'm having a terrible nightmare. Search through me and find it ... -->
``` 
search through maybe wanna say make a dirlisting


===dirListing===
```
/sadistRoom
/lockerRoom
/map.php
/SafeHeaven
/adandonedRoom
```

posible users: "Sebastian"


nmpa recon
```
-Passive scan-
21/tcp open  ftp     syn-ack
22/tcp open  ssh     syn-ack
80/tcp open  http    syn-ack

-targeted-
21/tcp open  ftp     syn-ack ProFTPD 1.3.5a
22/tcp open  ssh     syn-ack OpenSSH 7.2p2 Ubuntu 4ubuntu2.10 (Ubuntu Linux; protocol 2.0)
80/tcp open  http    syn-ack Apache httpd 2.4.18 ((Ubuntu))
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

```

