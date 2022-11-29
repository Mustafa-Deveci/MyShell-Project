# MyShell Project
Operating Systems course myShell project

* Shell command info should be seen as "myshell >>"

* You cannot exit until the “exit” contest is entered. Allowing new command information as "myshell>>" every time
should give.

* Shell If a command that does not exist, an incorrect command is entered (parameter error), or the invoked
when there is an error in the programs, it should write "you entered a wrong command" and myshell can be commanded again
should become.

* When the "bash" decision is entered, the bash program in the system should be called and normal operations in bash
should be done. The other main process must wait until output is written to this bash.
- my shell >> bash
- bash>>echoxxx
- xxx
- bash>>exit
- my shell>>

* “cat text...” output: “cat:text...”
* Wash “clear” screen.
* Shows the files in the "ls" folder.

* A program with the name “execx” that takes “-t times program” parameter should be written. This program has been given
should run the programs in succession as many as the number entered. Myshell should continue running in the background. The remainder of the program must be passed to the right as a parameter to the subprogram. Execx should wait for the process to finish its work each time it creates child porcelains.
- myshell>>execx-t3wriref
- my shell>> execx -t 3 wriref -f my file

* A program named “writef” should be written. This program should take -f "filename". if as a parameter
If the given file exists, they should append "append", if not, create something and add it.
should write. It should write the system time, pid and ppid value in the file in one line.
