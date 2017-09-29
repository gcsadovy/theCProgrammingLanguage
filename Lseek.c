//random access

//input and output are normally sequential; each read or write takes place at a position in the file right after the previous one ;

//when necessary, a file can be read or written in any arbitrary order; the system call lseek provides a way to move around in a file without reading or writing any data

long lseek(int fd, long offset, int origin);

//sets the current position of the file whos descriptor is fd to offset, which is taken relative to the location specified by origin; subsequent reading or writing will begin at that position;

//origin can be 0, 1, 2 to specify that offset is to be measured from the beginning, from the current position, or from the end of file respectively

//for example, to append a file, the redirection >> in unix shell or "a" for fopen, seek to the end before writing

lseek(fd, 0L, 2);

//to get back to the beginning

lseek(fd, 0L, 0)

//the 0L argument could have been written as (long) 0 or just as 0 if lseek is properly declared

//with lseek it is possible to treat files more or less like arrays, at the peice of slower access; for example, the following function reads any number of bytes for any arbitrary place in a file; it returns the number read, or -1 on error:

#include "syscalls.h"

//get: read n bytes from position pos
int get(int fd, long pos, char *buf, int n)
{
  if (lseek(fd, pos, 0) >= 0) //to get to pos
      return read(fd, buf, n);
  else
    return -1;
}

//the return value from lseek is a long that gives the new position in the file or -1 if an error occurs

//the stdlib function fseek is similar to lseek except that the first argument is a FILE * and the return is non-zero is an error occurred
