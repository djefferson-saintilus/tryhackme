# writeups

` <!-- use guest:guest credentials until registration is fixed -->`

I found that in login.php the main page of the website

I log into with guest:guest, I was connected with guest account

and then I got another one

`    <!-- admin account could be vulnerable, need to update -->`

so look a little the url

```
view-source:http://10.10.163.24/profile.php?user=guest
```

it seems like the page called the user adress, with the variable user
so why not trying to change the value, by setting "admin"

```
10.10.163.24/profile.php?user=admin
```
and it works,

```
Hi, admin. Welcome to your site. The flag is: flag{66be95c478473d91a5358f2440c7af1f}
```


END
