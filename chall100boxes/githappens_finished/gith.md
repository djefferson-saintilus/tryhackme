#writeups

--nmap gathering--
80/tcp open  http    syn-ack nginx 1.14.0 (Ubuntu)
| http-methods: 
|_  Supported Methods: GET HEAD
|_http-server-header: nginx/1.14.0 (Ubuntu)
| http-git: 
|   10.10.117.229:80/.git/
|     Git repository found!
|_    Repository description: Unnamed repository; edit this file 'description' to name the...
|_http-title: Super Awesome Site!
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel



--dirlisting--
```
//[22:50:03] 200 -   23B  - /.git/HEAD  : nothing serious
                                     
[22:50:03] 301 -  194B  - /.git  ->  http://10.10.117.229/.git/
[22:50:03] 200 -    1KB - /.git/hooks/                                     
[22:50:03] 200 -   73B  - /.git/description                                
[22:50:03] 200 -    1KB - /.git/                                           
[22:50:03] 200 -  179B  - /.git/branches/                                  

//[22:50:03] 200 -  240B  - /.git/info/exclude : nothing serious

[22:50:03] 301 -  194B  - /.git/logs/refs/heads  ->  http://10.10.117.229/.git/logs/refs/heads/
[22:50:03] 200 -  216B  - /.git/logs/HEAD                                  

//[22:50:03] 200 -  110B  - /.git/config : nothing serious

[22:50:03] 301 -  194B  - /.git/logs/refs/remotes  ->  http://10.10.117.229/.git/logs/refs/remotes/
[22:50:03] 200 -  283B  - /.git/info/
[22:50:03] 200 -  216B  - /.git/logs/refs/heads/master
[22:50:03] 301 -  194B  - /.git/logs/refs  ->  http://10.10.117.229/.git/logs/refs/
[22:50:03] 200 -  390B  - /.git/logs/                                      
[22:50:03] 200 -  102B  - /.git/packed-refs
[22:50:03] 200 -    4KB - /.git/objects/
[22:50:03] 200 -  505B  - /.git/refs/
[22:50:03] 200 -  645B  - /.git/index
[22:50:03] 301 -  194B  - /.git/refs/heads  ->  http://10.10.117.229/.git/refs/heads/
[22:50:03] 200 -   41B  - /.git/refs/heads/master                          
[22:50:03] 301 -  194B  - /.git/refs/tags  ->  http://10.10.117.229/.git/refs/tags/
[22:50:03] 301 -  194B  - /.git/refs/remotes  ->  http://10.10.117.229/.git/refs/remotes/
[22:50:03] 200 -  792B  - /.gitlab-ci.yml                                  
[22:50:17] 200 -   54B  - /README.md                                        
[22:50:43] 301 -  194B  - /css  ->  http://10.10.117.229/css/               
[22:50:57] 200 -    7KB - /index.html                                       
config : nothing serious
descript : same                                      
packed-refs : same

```


the Login main page, don't work


/README.md
```                                    
# git-fail

Sometimes, bad things happen to good sites
```                                      

index, an important file
```
DIRC
.gitlab-ci.yml
Dockerfile
        README.md
css/style.css
dashboard.html
default.conf
index.html
TREE
```

--nikto---
```
+ /css/: Directory indexing found.
+ /css/: This might be interesting.
+ /.git/index: Git Index file may contain directory listing information.
+ /.git/HEAD: Git HEAD file found. Full repo details may be present.
+ /.git/config: Git config file found. Infos about repo details may be present.
+ /#wp-config.php#: #wp-config.php# file found. This file contains the credentials.
```

let's keep this hash
`d0b3578a628889f38c0affb1b75457146a4678e5`

./logs, it's a different dir

```
0000000000000000000000000000000000000000 d0b3578a628889f38c0affb1b75457146a4678e5 root <root@ubuntu.(none)> 1595543975 +0200	
clone: from https://hydragyrum:kMhJnM42EHdTN7MXNWeD@gitlab.com/cfe-atc/seccom/git-fail.git
```

--info--

Adam Bertrand 
Hydragyrum


after, I use gitTools, then use gitTools, just to copy the .git from my machine and then make git log
and I see
```
commit 395e087334d613d5e423cdf8f7be27196a360459
Author: Hydragyrum <hydragyrum@gmail.com>
Date:   Thu Jul 23 23:17:43 2020 +0200

    Made the login page, boss!
```
and show the git process, by scrolling down, I see that, But later there was a note
that said *Awesome! Use the password you input as the flag!*
```
+          username === "admin" &&
+          password === "Th1s_1s_4_L0ng_4nd_S3cur3_P4ssw0rd!"
```
then this was all for this.


really helpful this one, when I got stuck
source : https://basicpentesting.blogspot.com/2020/08/git-happens-tryhackme.html
