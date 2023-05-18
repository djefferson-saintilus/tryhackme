# writeups

deskel


`+ /: Uncommon header 'busted' found, with contents: Hey, you found me, take this Easter 6: THM{l37'5_p4r7y_h4rd}.`
`Easter 1: THM{4u70b07_r0ll_0u7}`

by decoding the base64, multiple time( I mean the base64 that was in the robots.txt), I found
*DesKel_secret_base*, let's see what's that, and I found a new one

`Easter 2: THM{f4ll3n_b453}`


--dirListing
```
TRASH}/button               (Status: 200) [Size: 39148]
TRASH}/cat                  (Status: 200) [Size: 62048]
/cgi-bin/             (Status: 403) [Size: 286]
TRASH}/dinner               (Status: 200) [Size: 1264533]
TRASH}/egg                  (Status: 200) [Size: 25557]
/index                (Status: 200) [Size: 94328]
TRASH}/iphone               (Status: 200) [Size: 19867]
/login                (Status: 301) [Size: 308] [--> http://10.10.8.17/login/]
TRASH}/nicole               (Status: 200) [Size: 367650]
TRASH}/ready                (Status: 301) [Size: 308] [--> http://10.10.8.17/ready/]
/robots               (Status: 200) [Size: 430]
/robots.txt           (Status: 200) [Size: 430]
/server-status        (Status: 403) [Size: 291]
/small                (Status: 200) [Size: 689]
/static               (Status: 200) [Size: 253890]
/ty                   (Status: 200) [Size: 198518]
/index                (Status: 200) [Size: 94328]
/login                (Status: 301) [Size: 308] [--> http://10.10.8.17/login/]
/button               (Status: 200) [Size: 39148]
/static               (Status: 200) [Size: 253890]
/cat                  (Status: 200) [Size: 62048]
/small                (Status: 200) [Size: 689]
/who                  (Status: 200) [Size: 3847428]
/robots               (Status: 200) [Size: 430]
/iphone               (Status: 200) [Size: 19867]
/game1                (Status: 301) [Size: 308] [--> http://10.10.8.17/game1/]
/egg                  (Status: 200) [Size: 25557]
/dinner               (Status: 200) [Size: 1264533]
/ty                   (Status: 200) [Size: 198518]
/ready                (Status: 301) [Size: 308] [--> http://10.10.8.17/ready/]
/saw                  (Status: 200) [Size: 156274]
```

I found a flag in, /login source code `EASTER 3, THM{y0u_c4n'7_533_m3}`, 
after that, in the /login I tried a sqli, and found `POST parameter 'username' is vulnerable. ` and after
a while I got

```
---
Parameter: username (POST)
    Type: time-based blind
    Title: MySQL >= 5.0.12 AND time-based blind (query SLEEP)
    Payload: username=test' AND (SELECT 5552 FROM (SELECT(SLEEP(5)))ExFc) AND 'qJEY'='qJEY&password=test&submit=submit
---
```









