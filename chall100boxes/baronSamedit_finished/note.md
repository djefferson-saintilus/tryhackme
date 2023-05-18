# writeups

baron samedit
```
Specifically, this was a heap buffer overflow allowing any user to escalate privileges to root -- 
no misconfigurations required. This exploit works with the default settings, for any user regardless 
of sudo permissions, which makes it all the scarier. The vulnerability has been patched, but affects 
any unpatched version of the sudo program from 1.8.2-1.8.31p2 and 1.9.0-1.9.5p1, meaning that it's been 
around for the last ten years.

```

check vulnerability
`sudoedit -s '\' $(python3 -c 'print("A"*1000)')`

result
```
malloc(): memory corruption
Aborted (core dumped)
```


`sudo -V` : check sudo version

`THM{NmU4OWYwMWJmMjkxMDdiYTU4MWIxNWVk}`

