# writeups

```
22/tcp    open  ssh     syn-ack OpenSSH 8.2p1 Ubuntu 4ubuntu0.4 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   3072 7ddceb90e4af33d99f0b219afcd577f2 (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQDLgmREvZByFxoWZEVRzGogcBi04sMOoMHUcJ8P2t9mi8q1V+lRvZczumOJ9RliQ1khNRHsIgnJ7/Yp4iCz9UFRLYsIlQ2PAgODBjNyhIWepELlSatGLZqviC6qnxEASC2OrwFvHmYNklZIjbc4+Yli2bn8I2PjntRKoMQHjehoWip/V955dYwa7KysnPPMsmXlrx9dhHJ0yheqYIOxwlN2xRC7ZtQMfY28mn0ifRhMnM9RRgC5CDAJh3QeJYM90gBdIq466x4p6yWQzjK/t0i5zIKFBJBLp85DaT3WkWBn3ueHFoedeeAsXeO16BNX6SomLNWsslp5a3E1YQiOBX3LNEm64Rr8ekPxtrXhTzcBUMGJYzc7QaE2/N9yCnkvL0vCApO+XFmo+lr9bAt8qGixpqk1awPqIhxOTUWIr4lAShsu7b+mwQlGeYO7aEeaO3R7ZFaZwGfp2vF/yYwReT+mVimFbs67yiVcMCNhVgvI5vLFrh+OyvufUK2tnCe4xbs=
|   256 83a74a61ef93a3571a57385c482aeb16 (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBEuffg4vybQqbP0RmSCYjd6nillwqgiGF1OAIPUsBCewLy6eiVYsnzAF3Z2TAHKjA8GqTlhRu05KWfdys7J+MQc=
|   256 30bfef9408860700f7fcdfe8edfe07af (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAILHnXOBOqSHpnx9JPguwJAsiurhjCuLjkOIfNSp9f9ai
2222/tcp  open  ssh     syn-ack OpenSSH 8.2p1 Ubuntu 4ubuntu0.4 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   3072 74edb9a181070c225a96a9e63976161f (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQDVz+bZXyEyxSiTJUDlsHjsXV5E2NcAb3Md35OTwNQvL2d5jN/cD5rn9iYgSYXBQAyJRl3aufMb5lc1XA8ywf9fHqHLQRxGJtAJLDNgqewxc2soXWdIxRJQMA5uCQlgjzApkjzRIQGjrikeRjL82BWSBzXjmwF+G+MIDbDL/udiSsjhTEFUNTBgZxSqdWj1Ilb+YUhgndzYuxdXBVi4w0W79I4Sf/OM0HKek/fkJVmNWiK70eL7+496MFeHE5hzyHx1+6Bwuko0aM20ZDGUnm0QSdpk0DB+nR1rcrxz2uIF7LxN/LGDyhEVVuQ0KQSuDTlRbYpNBmixWyjlZ7gca0169wMX+gLkoDKisTc6BQKyqwylRQp6jT3OnvyuIacOXli8um2dnDwj7ieRSqeREWk/GCCSou7kMXaJ4jEEOIcxl1e8N3kZCISRuFyvLp/Mnu1ugoQVb4mOCCEG4DZfOJuyKa4XwOothx2GuR+ZA6PisfwvoyUFkSLt0P4I4008lck=
|   256 ce98f98064c409cf00676febab3dfd59 (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBFMEuLCAT/R6BUg/DC8lDEQKiauwMWCaoHGiHSnhXRiS84YlaT0GSYEDVfEEVUaOe0kXIgA6lNl9tPz4k28iPj8=
|   256 03841db29ae95423da0fe49cce1abf4e (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIDEcNCKTzz492jIFqM4P0Oy2sU7gTDme3HQmcaR5qUwn
31337/tcp open  Elite?  syn-ack
| fingerprint-strings: 
|   DNSStatusRequestTCP, DNSVersionBindReqTCP, FourOhFourRequest, GenericLines, GetRequest, HTTPOptions, Help, Kerberos, LANDesk-RC, LDAPBindReq, LDAPSearchReq, LPDString, NULL, RPCCheck, RTSPRequest, SIPOptions, SMBProgNeg, SSLSessionReq, TLSSessionReq, TerminalServer, TerminalServerCookie, X11Probe: 
|     In case I forget - user:pass
|_    ubuntu:Dafdas!!/str0ng
```
after making some nmap scanning I could get a strange port 31337. so I see some creds, when I
tried to connect within by netcat so, it looks like that: 
``` 
nc 10.10.192.39 31337
In case I forget - user:pass
ubuntu:Dafdas!!/str0ng
```
so after that, I tried to connect but nothing they only gave me some user:pass creds, but while
doing the scanning I saw that there was a port 22(ssh) open so I imagine this creds was just for
connecting to this ssh, and after conclude that I connected to the ssh with success.

so when I get connected, I tried some sudo but nothing work, so I decided to explore the machine
and I found some hide file with root permission in python in the `/opt/` dir, and my user can write
into this file but I don't do this because my flag it's just in /home/user, there were 2 users, I connected
like ubuntu, and "user" have my flag, and there it is
`flag{251f309497a18888dde5222761ea88e4}`, so and the machine doesn't have any challenges yet.



https://systemweakness.com/intermediate-nmap-93e1c7c71ca6
