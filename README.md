# # C - Simple Shell
In Unix System, the most generic sense of the term **shell** means any program that users employ to type commands. A shell hides the details of the underlying operating system and manages the technical details of the operating system's application programming interface, which is the level of the operating system that programs running on that operating system use.
**Simple Shell** is a project to handle some of those hidden features and algorithms what actually work inside a shell, and how are they executed properly after they  have been entered?

### General

-   Who designed and implemented the original Unix operating system
In the 1960s and 1970s Dennis Ritchie and Ken Thompson invented Unix, arguably the world's most important computer operating system.

-   Who wrote the first version of the UNIX shell
The first Unix shell was the Thompson shell, sh, written by Ken Thompson at Bell Labs and distributed with Versions 1 through 6 of Unix, from 1971 to 1975.

-   Who invented the B programming language (the direct predecessor to the C programming language)
Ken Thompson invented the B programming language, the direct predecessor to the C programming language, and was one of the creators and early developers of the Plan 9 operating system.

-   Who is Ken Thompson
Kenneth Lane Thompson (born February 4, 1943) is an American pioneer of computer science. Thompson worked at Bell Labs for most of his career where he designed and implemented the original Unix operating system. He also invented the B (programming language), the direct predecessor to the C (programming language), and was one of the creators and early developers of the Plan 9 from Bell Labs operating system. Since 2006, Thompson has worked at Google, where he co-developed the Go (programming language).
Other notable contributions included his work on regular expression and early computer text editors QED (text editor) and ed (text editor), the definition of the UTF-8 encoding, and his work on computer chess that included the creation of endgame tablebase and the chess machine Belle (chess machine). He won the Turing Award in 1983 with his long-term colleague Dennis Ritchie.

-   How does a shell work
The shell is your interface to the operating system. It acts as a command interpreter; it takes each command and passes it to the operating system.  It then displays the results of this operation on your screen. There are several shells in widespread use.

-   What is a pid and a ppid
In Linux and Unix-like systems, each process is assigned a process ID, or PID. This is how the operating system identifies and keeps track of processes.
PPID is a process that creates a new process is called a parent process; the new process is called a child process. The parent process ID (PPID) becomes associated with the new child process when it is created.

-   How to manipulate the environment of the current process

-   What is the difference between a function and a system call
The main difference between system call and function call is that a system call is a request for the kernel to access a resource while a function call is a request made by a program to perform a specific task.

-   How to create processes
By calling fork (). A new process can then be created. By copying the addresses of the previous processes into the new ones, you can create a new identity. This produces a new process from the old one. It is a parent process, and a child process is created following it.

-   What are the three prototypes of  `main`
int main()
int main(int argc, char *argv[])
int main (int argc, char *argv[], char *envp[])

-   How does the shell use the  `PATH`  to find the programs
The shell tries each directory in the PATH , left-to-right, and runs the first  executable program  with the matching command name that it finds. Slashes in the path name prevent the shell from using PATH to look up the command name, so the shell executes /bin/date directly.

-   How to execute another program with the  `execve`  system call
Like all of the `exec` functions, `execve` replaces the calling process image with a new process image. This has the effect of running a new program with the process ID of the calling process. Note that a new process is not started; the new process image simply overlays the original process image. The `execve` function is most commonly used to overlay a process image that has been created by a call to the `fork` function.
Prototype: int execve(const char *file, char *const argv[], char *const envp[]);
The following example illustrates the use of `execve` to execute the `ls` shell command. Notice that the `STEPLIB` environment variable is set for the new process.

  #include <sys/types.h>
  #include <unistd.h>
  #include <stdio.h>

  main()
  {
     pid_t pid;
     char *const parmList[] = {"/bin/ls", "-l", "/u/userid/dirname", NULL};
     char *const envParms[2] = {"STEPLIB=SASC.V6.LINKLIB", NULL};

     if ((pid = fork()) ==-1)
        perror("fork error");
     else if (pid == 0) {
        execve("/u/userid/bin/newShell", parmList, envParms);
        printf("Return not expected. Must be an execve error.n");
     }
  }

-   **How to suspend the execution of a process until one of its children terminates?**
A call to wait() blocks the calling process until one of its child processes exits or a signal is received. After child process terminates, parent continues its execution after wait system call instruction.

-   **What is  `EOF`  / “end-of-file”?**
EOF/end-of-file is a condition in a computer operating system where no more data can be read from a data source. The data source is usually called a file (computing) or stream (computing).

## PID & PPID

A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call  `getpid`  (man 2  `getpid`):

```
julien@ubuntu:~/c/shell$ cat pid.c
#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%u\n", my_pid);
    return (0);
}
julien@ubuntu:~/c/shell$ gcc -Wall -Werror -pedantic pid.c -o mypid && ./mypid
3237
julien@ubuntu:~/c/shell$ ./mypid 
3238
julien@ubuntu:~/c/shell$ ./mypid 
3239
julien@ubuntu:~/c/shell$ 

```

Note in the example above, that every time you run the program, a new process is created, and its ID is different.

Each process has a parent: the process that created it. It is possible to get the PID of a parent process by using the  `getppid`  system call (man 2  `getppid`), from within the child process.

### Exercises

#### 0. getppid

Write a program that prints the PID of the parent process. Run your program several times within the same shell. It should be the same. Does  `echo $$`  print the same value? Why?

#### 1. /proc/sys/kernel/pid_max

Write a shell script that prints the maximum value a process ID can be.

## Arguments

The command line arguments are passed through the  `main`  function:  `int main(int ac, char **av);`

-   `av`  is a  `NULL`  terminated array of strings
-   `ac`  is the number of items in  `av`

`av[0]`  usually contains the name used to invoke the current program.  `av[1]`  is the first argument of the program,  `av[2]`  the second, and so on.

### Exercises

#### 0. av

Write a program that prints all the arguments, without using  `ac`.

#### 1. Read line

Write a program that prints  `"$ "`, wait for the user to enter a command, prints it on the next line.

man 3  `getline`

**important**  make sure you read the man, and the RETURN VALUE section, in order to know when to stop reading Keyword: “end-of-file”, or  `EOF`  (or  `Ctrl+D`).

_#advanced_: Write your own version of  `getline`.

```
julien@ubuntu:~/c/shell$ gcc -Wall -Wextra -Werror -pedantic prompt.c -o prompt
julien@ubuntu:~/c/shell$ ./prompt 
$ cat prompt.c
cat prompt.c
julien@ubuntu:~/c/shell$ 

```

#### 2. command line to av

Write a function that splits a string and returns an array of each word of the string.

man  `strtok`

_#advanced_: Write the function without  `strtok`
