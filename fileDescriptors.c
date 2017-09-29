//the unix system interface Chapter 8

//the unix os, there are programs embedded within the os named system calls that can be exploited by the user - to get extra functionality etc

//file descriptors

//all input or output is done by reading files, because all peripheral devices, even keyboard and screen are files in the file system

//the process of opening the file; does the file exist? does the user have the appropriate permissions; are you going to read or write it; if all is well it returns to the program a small non-negative integer called a file descriptor

//all information about an open file is maintained in the system; the user program refers to the file only by the file pointer

//when the shell runs a program, 3 files are open, stdin, stdout and stderr, with file descriptors 0, 1, 2; if the program reads 0, and writes 1 and 2, it can do input and output without worrying about opening files

//the user of a program can redirect I/O to and from files with < and >

prog <infile >outfile

// here the default assignments for the file descriptors 0 and 1 are changed to infile and outfile

//normally file descriptor 2 remains attached to the screen so error messages are more readily passed

//similar observations hold for a pipe

//the program does not know where its input comes from nor where its output goes, so long as it uses file 0 for input and 1 and 2 for output

