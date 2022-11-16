**Don't forget to compile the code using `make` command**

### Compare:
**Usage:**
```ruby
ubuntu@ubuntu-ASUS-TUF:~/Documents/Matala1OS$ ./cmp test1.txt test2.txt
Identical
ubuntu@ubuntu-ASUS-TUF:~/Documents/Matala1OS$ ./cmp symlink test2.txt
Identical
```

### Copy:
**Usage:**
```ruby
ubuntu@ubuntu-ASUS-TUF:~/Documents/Matala1OS$ ./copy test1.txt test2.txt
file is copied
ubuntu@ubuntu-ASUS-TUF:~/Documents/Matala1OS$ ./copy symlink test2.txt
file is copied
```

### Encode:
**Usage:**
```ruby
ubuntu@ubuntu-ASUS-TUF:~/Documents/Matala1OS$ ./encode codec1 This_Is__TeST1Ng@@[]
tHIS_iS__tEst1nG@@[]
ubuntu@ubuntu-ASUS-TUF:~/Documents/Matala1OS$ ./encode codec2 this_is_testing@
-116-104-105-115-95-105-115-95-116-101-115-116-105-110-103-64
```

### Decode:
**Usage:**
```ruby
ubuntu@ubuntu-ASUS-TUF:~/Documents/Matala1OS$ ./decode codec1 tHIS_iS__tEst1nG@@[]
This_Is__TeST1Ng@@[]
ubuntu@ubuntu-ASUS-TUF:~/Documents/Matala1OS$ ./decode codec2 -116-104-105-115-95-105-115-95-116-101-115-116-105-110-103-64
this_is_testing@
```
