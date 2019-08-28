SIMPLE SHELL
============

  <img src="https://techcrunch.com/wp-content/uploads/2015/11/holberton-logo-horizontal.jpg?w=990&crop=1">

Recreate a simple shell for [Holberton](https://www.holbertonschool.com/). This assignment tasks us to build a shell which outputs exactly as the sh shell. 

### Prerequisites
Only use the following functions and system calls:
```
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
fstat (man 2 fstat)
getcwd (man 3 getcwd)
getline (man 3 getline)
kill (man 2 kill)
lstat (man 2 lstat)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (man 2 stat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
_exit (man 2 _exit)
```
## Environment
Simple Shell was built and tested in the Ubuntu 14.04 LTS via Vagrant in VirtualBox and compiled with GCC version 4.8.4

## Respository Contents
Simple Shell files:

| **File** | **Description** |
|----------|-----------------|
| holberton.h | Header file that contains all the functions and standard C library header files needed |
| prompt.c | Contains the int main(void) function, entry point and **prompt_handler** |
| _strtok.c | Contains function that store commands in double pointer: **find_command_length**, **array_from_strtok functions** |
| helpers.c | Contains all helper functions: **_strncpy**,**_strncpyconst**, **_strlen_const**, **_strcmp**,**_strlen** |
| habitat.c | Contains all functions that handle environment/path: **find_semis**, **store_env_variables**, **_getenv**, **_strncpycmd**, **print_env** |
| free_all.c | Contains function that frees memory: **free_it_all** |
| errors.c | Contains functions that handle error messages: **build_error_message**, **_puterror**, **end_of_file**, **fork_fail**|
| childs_play.c | Contains functions that handle all child proccess functionality: **command_is_null**, **exit_out**, **env_out**, **parent_free_buff_commands**, **c_path**|

## How to Install
Clone the repo below
```
https://github.com/747-diego/simple_shell
```

## How to Compile
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Example Output
```
vagrant@vagrant-ubuntu-trusty-64:$ ./hsh
$ pwd
/home/vagrant/simple_shell
$ /bin/pwd
/home/vagrant/simple_shell
$ ls -la
total 176
drwxrwxr-x 3 vagrant vagrant  4096 Aug 28 14:27 .
drwxrwxr-x 4 vagrant vagrant  4096 Aug 28 14:27 ..
drwxrwxr-x 7 vagrant vagrant  4096 Aug 28 14:05 SHELL_TEST
-rwxrwxr-x 1 vagrant vagrant 13986 Aug 28 14:45 a.out
-rw-rw-r-- 1 vagrant vagrant   369 Aug 28 14:47 free_all.c
-rw-rw-r-- 1 vagrant vagrant  1179 Aug 28 14:31 helpers.c
-rw-rw-r-- 1 vagrant vagrant   815 Aug 28 14:42 holberton.h
-rwxrwxr-x 1 vagrant vagrant 13891 Aug 28 14:20 hsh
-rwxrwxr-x 1 vagrant vagrant  3259 Aug 28 14:27 print_environ.c
-rwxrwxr-x 1 vagrant vagrant  2363 Aug 28 14:18 prompt.c
-rw-rw-r-- 1 vagrant vagrant  1302 Aug 28 14:25 strtok_example.c
```

## To do

### Mandatory
- [x] Handle EOF
- [x] Parser interprets ``exit`` -- Currently, if the first 4 characters of the string are ``exit``, the shell will exit.
- [x] Handle path
- [x] Build env function

### Advanced
- [x] ``exit`` handles arguments to exit -- What is ``exit status 4``?

#### Parser
- [x] Handle ``^C`` (CTRL + C) -- Find the signal and change its behavior.
- [ ] Handle ``;``
- [ ] Handle ``&&``, and ``||``
- [ ] Handle ``#`` Comments

#### Recreate standard library functions
- [ ] getline
- [x] strtok
- [x] getenv
- [ ] setenv
- [ ] unsetenv

#### Shell Builtins
- [x] register builtins before executing commands
- [x] cd
- [ ] alias
- [ ] help
- [ ] history
- [ ] Deal with variables
- [ ] Scripts as input

## Bugs
- [x] unfreed mallocs somewhere. (Check with Valgrind.)
- [ ] Only delimiters handled are spaces and newlines.



## Authors
* Diego Tardio
* Jonathan Patterson
