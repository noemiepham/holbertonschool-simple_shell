# # C - Simple Shell
In Unix System, the most generic sense of the term **shell** means any program that users employ to type commands. A shell hides the details of the underlying operating system and manages the technical details of the operating system's application programming interface, which is the level of the operating system that programs running on that operating system use.

**#C - Simple Shell is a project to handle some of those hidden features and algorithms what actually work inside a shell, and find how are they executed properly after they  have been entered.**

## Something about Shell

-   **Who designed and implemented the original Unix operating system?**

In the 1960s and 1970s Dennis Ritchie and Ken Thompson invented Unix, arguably the world's most important computer operating system.

-   **Who wrote the first version of the UNIX shell?**

The first Unix shell was the Thompson shell, sh, written by Ken Thompson at Bell Labs and distributed with Versions 1 through 6 of Unix, from 1971 to 1975.

-   **Who invented the B programming language (the direct predecessor to the C programming language)?**

Ken Thompson invented the B programming language, the direct predecessor to the C programming language, and was one of the creators and early developers of the Plan 9 operating system.

-   **Who is Ken Thompson?**

Kenneth Lane Thompson (born February 4, 1943) is an American pioneer of computer science. Thompson worked at Bell Labs for most of his career where he designed and implemented the original Unix operating system. He also invented the B (programming language), the direct predecessor to the C (programming language), and was one of the creators and early developers of the Plan 9 from Bell Labs operating system. Since 2006, Thompson has worked at Google, where he co-developed the Go (programming language).
Other notable contributions included his work on regular expression and early computer text editors QED (text editor) and ed (text editor), the definition of the UTF-8 encoding, and his work on computer chess that included the creation of endgame tablebase and the chess machine Belle (chess machine). He won the Turing Award in 1983 with his long-term colleague Dennis Ritchie.

## More about Shell

-   **How does a shell work?**

![Simple Shell loop](https://user-images.githubusercontent.com/105150447/182952977-26fabee4-a8a2-474e-8ba4-4f5d1de6adef.png)

A shell is a program that acts as an interpreter which passes commands inputs entered by a user that are then executed by the operating system. The shell runs in a sort of infinite _loop of different functions (i.e. reading typed command, format the command, manage exceptions and execute)_ until the next command is entered.

-   **What is a pid and a ppid?**

In Linux and Unix-like systems, each process is assigned a process ID, or PID. This is how the operating system identifies and keeps track of processes.
PPID is a process that creates a new process is called a parent process; the new process is called a child process. The parent process ID (PPID) becomes associated with the new child process when it is created.

-   **How to manipulate the environment of the current process?**

Every process comes with an environment. When a new process is created, it inherits a copy of its parent’s environment. To access the entire environment within a process, you have several options:
-via the  `main`  function
-via the global variable  `environ`  (man environ)

-   **What is the difference between a function and a system call?**

The main difference between system call and function call is that a system call is a request for the kernel to access a resource while a function call is a request made by a program to perform a specific task.

-   **How to create processes?**

By calling fork (). A new process can then be created. By copying the addresses of the previous processes into the new ones, you can create a new identity. This produces a new process from the old one. It is a parent process, and a child process is created following it.

 -   **What are the three prototypes of  `main`?**

	 - int main()
	 - int main(int argc, char *argv[])
	 - int main (int argc, char *argv[], char *envp[])

 -   **How does the shell use the  `PATH`  to find the programs?**

The shell tries each directory in the PATH , left-to-right, and runs the first  executable program  with the matching command name that it finds. Slashes in the path name prevent the shell from using PATH to look up the command name, so the shell executes /bin/date directly.

-   **How to execute another program with the  `execve`  system call?**

Like all of the `exec` functions, `execve` replaces the calling process image with a new process image. This has the effect of running a new program with the process ID of the calling process. Note that a new process is not started; the new process image simply overlays the original process image. The `execve` function is most commonly used to overlay a process image that has been created by a call to the `fork` function.

The following example illustrates the use of `execve` to execute the `ls` shell command. Notice that the environment variable is set for the new process.      


    #include <sys/types.h>
    #include <unistd.h>
    #include <stdio.h>
    
    int main()
    {
        pid_t pid;
        char *args[] = {"/bin/ls", "-l", "/usr/", NULL};
        char *env[] = {0};
    
	    if ((pid = fork()) == -1)
	        perror("fork error");
	    else if (pid == 0)
	    {
	        execve("/bin/ls", args, env);
	        printf("Return not expected.\n");
	        exit(1);
	    }
    }


-   **How to suspend the execution of a process until one of its children terminates?**

A call to wait() blocks the calling process until one of its child processes exits or a signal is received. After child process terminates, parent continues its execution after wait system call instruction.

-   **What is  `EOF`  / “end-of-file”?**

EOF/end-of-file is a condition in a computer operating system where no more data can be read from a data source. The data source is usually called a file (computing) or stream (computing).

## How to use Shell?

On a Mac or Linux machine, you can access a shell through a program called _Terminal_, which is already available on your computer. The Terminal is a window into which we will type commands. If you’re using Windows, you’ll need to download a separate program to access the shell.


## Requirements

### General

-   Allowed editors:  `vi`,  `vim`,  `emacs`
-   All your files will be compiled on Ubuntu 20.04 LTS using  `gcc`, using the options  `-Wall -Werror -Wextra -pedantic -std=gnu89`
-   All your files should end with a new line
-   A  `README.md`  file, at the root of the folder of the project is mandatory
-   Your code should use the  `Betty`  style. It will be checked using  [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl")  and  [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
-   Your shell should not have any memory leaks
-   No more than 5 functions per file
-   All your header files should be include guarded
-   Use system calls only when you need to ([why?](https://intranet.hbtn.io/rltoken/rp53OodD6JzhS5Cv4DHkxQ "why?"))

### GitHub

**There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.**

## More Info

### Output

-   Unless specified otherwise, your program  **must have the exact same output**  as  `sh`  (`/bin/sh`) as well as the exact same error output.
-   The only difference is when you print an error, the name of the program must be equivalent to your  `argv[0]`  (See below)

Example of error with  `sh`:

```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$

```

Same error with your program  `hsh`:

```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$


```

### List of allowed functions and system calls

-   `access`  (man 2 access)
-   `chdir`  (man 2 chdir)
-   `close`  (man 2 close)
-   `closedir`  (man 3 closedir)
-   `execve`  (man 2 execve)
-   `exit`  (man 3 exit)
-   `_exit`  (man 2 _exit)
-   `fflush`  (man 3 fflush)
-   `fork`  (man 2 fork)
-   `free`  (man 3 free)
-   `getcwd`  (man 3 getcwd)
-   `getline`  (man 3 getline)
-   `getpid`  (man 2 getpid)
-   `isatty`  (man 3 isatty)
-   `kill`  (man 2 kill)
-   `malloc`  (man 3 malloc)
-   `open`  (man 2 open)
-   `opendir`  (man 3 opendir)
-   `perror`  (man 3 perror)
-   `read`  (man 2 read)
-   `readdir`  (man 3 readdir)
-   `signal`  (man 2 signal)
-   `stat`  (__xstat) (man 2 stat)
-   `lstat`  (__lxstat) (man 2 lstat)
-   `fstat`  (__fxstat) (man 2 fstat)
-   `strtok`  (man 3 strtok)
-   `wait`  (man 2 wait)
-   `waitpid`  (man 2 waitpid)
-   `wait3`  (man 2 wait3)
-   `wait4`  (man 2 wait4)
-   `write`  (man 2 write)

## Compilation

Your shell will be compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

```

### Testing

Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

```

But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

```
## An example on exec_wait_fork.c

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <error.h>
    
    int main(int argc, char **argv)
    {
	   pid_t my_pid;
	   int status;
	   char *args[] = {"/bin/ls", "-l", 0};
	   char *env[] = {0};
		   		   
	   my_pid = fork();
	   if (my_pid == -1)
	   {
		   perror("fork fails");
		   return (1);
	   }
	   if (child == 0)
	   {
		    if (execve("/bin/ls", args, env) == -1)
	            {
			    perror("Error");
			    return (1);
		    }
	   }
	   wait(&status);
	   return (0);
	}

## :rocket: About us  :joystick:

This is our second group project at Holberton School !   
We hope you enjoy our work !  
For more questions, don't hesitate to contact us in our links down below.  
Made by:
-   **Noémie Pham:**  [Github](https://github.com/noemiepham)  /  [Linkedin](https://www.linkedin.com/in/no%C3%A9mie-huynh-74aa1b141/)
-   **Iker Lubamba Mbambi**:  [Github](https://github.com/ikerikks)  /  [Linkedin](https://www.linkedin.com/in/iker-lubamba-28688b230/)
-   **Yeh-Hsin (mia) Lee**:  [Github](https://github.com/mimi-fOlle)  /  [Linkedin](https://www.linkedin.com/in/yeh-hsin-lee-74922a23b/)

