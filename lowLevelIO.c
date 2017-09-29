//low level IO - reading and writing in c

//input and output uses the read and write functions, which are system calls; the first argument is a file descriptor, then a char array, then the number of bytes to be transferred

int n_read = read(int fd, char *buf, int n);
int n_written = write(int fd, char *buf, int n);

//each call returns the number of bytes transferred

//a return value of 0 bytes is EOF, and -1 is some error

//any number of bytes can be read or written in one call; the most common values are 1, which means one character at a time ("unbuffered") and a large number like 1024 or 4096 that corresponds to a physical block size on a peripneral device

//larger sizes will be more efficient because fewer system calls will be made

//can write a program to copy it's input to it's output, the equivalent of the file copying program written for chap 1; this can copy anything to anything, since the input and output can be redirected to any file or device

#include "syscalls.h"

main() //copy input to output
{
  char buf[BUFSIZ];
  int n;

  while ((n = read(0, buf, BUFSIZ)) > 0)
    write(1, buf, n);
  return 0;
}

//syscalls is not standard; packages the function prototypes for system calls

//the arameter BUFSIZ is also defined in syscalls.h; it's value is a good size for the local system

//if the file size is not a multiple of BUFSIZ, some read will return a smaller number of bytes to be written by write; the next call to read after that will return zero.

//version of getchar that does unbuffered input

#include "syscalls.h"

//getchar: unbuffered single character input

int getchar(void)
{
  char c;

  return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

//c must be a char because read needs a character pinter - casting c to unsigned char in the return statement eliminates any problem of sign extension

//the second version of getchar does input in big chunks, and hands out the characters one at a time

#include "syscalls.h"

//getchar simple buffered version
int getchar(void)
{
  static char buf[BUFSIZ];
  static char *bufp = buf;
  static int n = 0;

  if (n == 0) { //buffer is empty
    n = read(0, buf, sizeof buf);
    bufp = buf;
  }
  return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

//if these versions of getchar were to be compiled with <stdio.h>, then you would have to #undef the name getchar in case it is implemented as a macro

