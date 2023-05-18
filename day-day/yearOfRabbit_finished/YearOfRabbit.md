fisrt thing the port 80, there is nothing so interesting here, certainly there is apache server but don't have
any HOMEPAGE

my fisrt scan with nmap 

PORT   STATE SERVICE REASON  VERSION
21/tcp open  ftp     syn-ack vsftpd 3.0.2
22/tcp open  ssh     syn-ack OpenSSH 6.7p1 Debian 5 (protocol 2.0)
80/tcp open  http    syn-ack Apache httpd 2.4.10 ((Debian))

lo que pasa es que durante busco las carpetas para el sitio web de repente encuentro dos carpetas por magia
/assets
/icons


pero /assets parece muy interesante que el otro, durante busco algunas informaciones muy importante justo por
cusiosidad encuentro un archivo que se llama RickRolled.mp4 es justo un video de tres minutos pero al instante
encuentro tambien una cosa muy distintas que es el *style.css* aunque a veces el no tiene nada de importante pero
este vez parece que el desarollador es muy rigolo.

mira lo que encuentro
```Nice to see someone checking the stylesheets.
     Take a look at the page: /sup3r_s3cr3t_fl4g.php```
cuando me voy al este camino no encuentro nada de serio, aunque un mensaje que me dice *DESACTIVE YOUR JS*
para no estar pesimista voy a intentarlo para ver loque va conseguir porque desde ahora no llego a comprender nada
pero espero encuentro algo interesante sin duda, continua ...

bingooo, cuando desactivo el javascript todo cae bien y no hay ningun defecto y el ayuda como me dice es dentro el
video eso quiere decir que tengo que mirar el video para ir al etapa siguiente, vamonos

http://10.10.70.163/sup3r_s3cret_fl4g/

antes de continuar paranos un ratito para ver si no hay ningun redireccion de la parte del servidor que algunas veces 
son muy equivocador, usamos el herramineta burpsuite para interceptar los peticiones 

y hop he encontrado eso */intermediary.php?hidden_directory=/WExYY2Cv-qU* un camino para llegar a un carpeta/fichero, no 
se, vamos a ver, este camino nos llega a un repertorio donde hay un fichiero precisamente un .png de una mujer que ahora
no se quien es pero vamos a descargar el imagen y despues vamos a investigar sobre el en profundo.

primero busco a saber si hay unos caracteres que se esconden,
strings fichero.png

despues he encontrado un cumulo de caracteres pero a pesar de este cumulo de caracteres he encontrado algunas cosas importantisimo
como 

userName servidor : ftpuser
y el contrasena tambien he encontrado una lista de palabras donde pienso que al dentro de ellos hay la buena contrsena gracias a Dios
tenia una buena idea que es usar HYDRA para hallar el contrasena ehhh bingoo

`[21][ftp] host: 10.10.70.163   login: ftpuser   password: 5iez1wGXKfPKQ`
cuando he llegado, habia encontrado un fichero txt que el lenguaje escrito estaba el *Brainfuck*, mira a que el parece
```
+++++ ++++[ ->+++ +++++ +<]>+ +++.< +++++ [->++ +++<] >++++ +.<++ +[->-
--<]> ----- .<+++ [->++ +<]>+ +++.< +++++ ++[-> ----- --<]> ----- --.<+
++++[ ->--- --<]> -.<++ +++++ +[->+ +++++ ++<]> +++++ .++++ +++.- --.<+
+++++ +++[- >---- ----- <]>-- ----- ----. ---.< +++++ +++[- >++++ ++++<
]>+++ +++.< ++++[ ->+++ +<]>+ .<+++ +[->+ +++<] >++.. ++++. ----- ---.+
++.<+ ++[-> ---<] >---- -.<++ ++++[ ->--- ---<] >---- --.<+ ++++[ ->---
--<]> -.<++ ++++[ ->+++ +++<] >.<++ +[->+ ++<]> +++++ +.<++ +++[- >++++
+<]>+ +++.< +++++ +[->- ----- <]>-- ----- -.<++ ++++[ ->+++ +++<] >+.<+
++++[ ->--- --<]> ---.< +++++ [->-- ---<] >---. <++++ ++++[ ->+++ +++++
<]>++ ++++. <++++ +++[- >---- ---<] >---- -.+++ +.<++ +++++ [->++ +++++
<]>+. <+++[ ->--- <]>-- ---.- ----. <
```
y el resultado es 
```
User: eli

Password: DSpDiM1wAEwid
```
ahora tengo otra credencial pero no se que voy a hacer con el, supongo que debemos continuar a investigar siempre,
me recuerdo que al principio tenemos 3 puertos abiertos ftp,ssh,http ( el ftp hemos encontrado hasta ahorita, el http tambien
hemos visto todo, lo que no falta es el ssh), vamos a aprobar el ssh para ver, tal vez por suerte lo encontramos con exito.

bingoo cuando el ssh ha abierto hemos encontrado un mensaje de bienvenido
```
1 new message
Message from Root to Gwendoline:

"Gwendoline, I am not happy with you. Check our leet s3cr3t hiding place. I've left you a hidden message there"

END MESSAGE
```
lo pienso hacer es empezar a haller esta carpeta que es escondido 
 locate s3cr3t

```
/usr/games/s3cr3t
/usr/games/s3cr3t/.th1s_m3ss4ag3_15_f0r_gw3nd0l1n3_0nly!
/var/www/html/sup3r_s3cr3t_fl4g.php
```
lo que me parece un poco sopechoso es el segundo fichero que dice este fichero es solamente por GWENDOLINE( segun mi un usuario)
al dentro de este fichero hay algunas informaciones como el contrasena de GWENDOLINE, mira lo que tiene el fichero cuando lo leo
```
Your password is awful, Gwendoline. 
It should be at least 60 characters long! Not just MniVCQVhQHUNI
Honestly!

Yours sincerely
   -Root
```
ahora que sabemos que hay un usuario que se llama GWENDOLINE y que tenemos su contrasena los que nos faltan es el paso a grado superior 
sobre el sistema ( escalate privilege), vamonos a pasar en grado superior gracias al comando SU

bingoo que he llegado sobre la cuenta de gwendoline he visto un fichero user.txt, y lo abro y paf la bandera( flag)
THM{1107174691af9ff3681d2b5bdb5740b1589bae53}

ahora vamos a hallar la ultima bandera,

https://7s26simon.github.io/thm-writeups/yotr.html

no peudo explicar eso 


