//other than the default standard input and output, you must explicitly open files in order to read or write them; there are two system calls for this; open and creat

//open is like the fopen, except that instead of returning a file pointer, it returns a file descriptor, which is just an int; returns -1 if an error occurs

#include <fcntl.h>

int fd;
int open(char *name, int flags, int perms);

fd = open(name, flags, perms);

//as with fopen, the name argument is a character string containung the filename; the second argument, flags is an int that specifies how the file is to be opened; the main values are

//O_RDONLY - open for reading only
//O_WRONLY - open for writing only
//O_RDWR - open for reading and writing

//these constants are defined in <fcntl.h> and <sys/file.h> on BSDs

//to open an existing file for reading:

fd = open(name, O_RDONLY, 0);

//the perms argument is always zero for the uses of open that we will discuss

//it is an error to try to open a file that does not exist; the system called creat creates new files, or re-writes old ones

int creat(char *name, int perms);

fd = creat(name, perms);

//returns a file descriptor if it was able to create the file and -1 if not; if the file arlerady exists, creat will truncate it to zero length, discarding previous contents; it is not an error to creat a file that already exists

//if creat creates a new file, it creates the file with the permissions specified in the argv perm - there are nine bits of permission information associated with a file that control read, write, and execute access

//a three digit octal is conveinient for specifying permissions; for example 0775 specifies read, write, and execute permission for the owner, and read and execute permission for the group and everyone else

//simplified version of the program cp; copies only one file, does not eprmit the second argument to be a directory, and invents permissions instead of copying them

#include <stdio.h>
#include <fcntl.h>
#include "syscalls.h"
#define PERMS 0666 //rw for owner, group, others

void error(char *, ...);

//cp: copy f1 to f2
main(int argc, char *argv[])
{
  int f1, f2, n;
  char buf[BUFSIZ];

  if (argc != 3)
    error("Usage: cp from to");
  if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
    error("cp: can't open %s", argv[1]);
  if ((f2 = creat(argv[2], PERMS)) == -1)
    error("cp: can't create %s mode %03o", argv[2], PERMS);
  while ((n = read(f1, buf, BUFSIZ)) > 0)
    if (write(f2, buf, n) != n)
      error("cp: write error on file %s", argv[2]);
  return 0;
}

//this program creates the ouput file with fixed permissions of 0666; with the stat system call; described in 8.6 we can determine the mode of an existing file and thus give the same mode to copy

//Notice that the function error is called with cariable argument lists much like printf; the implementation of error illustrates how to use another member of the printf family; the standard lib function vprintf is like printf except that the variable argument list is replaced by a single argument that has been initialized by calling macro va_start

//similarly, vfprintf and vsprintf, are correspondent with fprintf and sprintf

#include <stdio.h>
#include <stdarg.h>

//error: print an error message and die
void error(char *fmt, ...)
{
  va_list args;

  va_start(args, fmt);
  fprintf(stderr, "error: ");
  vprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  va_end(args);
  exit(1);
}

//the limit of files that a program may have open simultaneously is ~20

//accordingly any program that intends to process many files muct be prepared to re-use file descriptors;

//the function close(int fd) breaks the connection between a file descriptor and an open file; and frees the file descriptor for use with some other file; it corresponds to fclose in the standard library except that there is no buffer to flush

//termination of a program via exit or return from the main program closes all open files

//the function unlink(char *name) removes the file name from the file system; it corresponds to the std library function remove

