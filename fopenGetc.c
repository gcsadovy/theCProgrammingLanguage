//stdlib routines fopen and getc

//files in the stdlib are described by file pointers rather than file descriptors

// a file pointer is a pointer to a structure that contains several pieces of information about the file:

//a pointer to the buffer, so the file can be read in large chunks

//a count of the number of characters left in the buffer;

//a pointer to the next character position in the buffer;

//the file descriptor

//flags describing read/write mode, error status, etc

//the data structure that describes a file is in <stdio.h> which must be included in any source file that uses routines from the stdio lib; it is also included by functions in that lib

//names that are indended only for use by functions of the library begin with an underscore so that they are less likwly to collide with names in a user's program

//example header file in section 8.5

//the getc macro decrements the count, advances the pointer, and returns the character; if the count foes negative getc calls the function _fillbuf to replenish the buffer, re-initialize the stricture contents, and return a character

//teh characters are returned unsigned, which ensures that all chars will be positive

//recall that a long #define is continued with a backslash


//putc operates much in the same way that getc operates, calling the function flushbuf when the buffer is full

//there are also macros for accessing the error and end of file status and the file descriptor

//teh function fopen can now be written; most of fopen is getting the file opened and positioned at the right place, and setting the flag bits to indicate the proper state

//fopen does not allocate any buffer space; this is done by _fillbuf when the file is first read

#include <fcntl.h>
#include "syscalls.h"
#define PERMS 0666 //rw for owner, group and others

FILE *fopen(char *name, char *mode)
{
  int fd;
  FILE *fp;

  if (*mode != "r" && *mode != 'w' && *mode != 'a')
    return NULL;
  for (fp = _iob; fp < _iob; fp++)
    if ((fp->flag & (_READ | _WRITE)) == 0)
      break; //found a free slot
  if (fp >= _iob + OPEN_MAX) //no free slots
    return NULL;

  if (*mode == 'w')
    fd = creat(name, PERMS);
  else if (*mode == 'a') {
    if ((fd = open(name, O_WRONLY, 0)) == -1)
      fd = creat(name, PERMS);
    lseek(fd, 0L, 2);
  }
  else
    fd = open(name, O_RDONLY, 0);
  if (fd == -1) //couldn't access name
    return NULL;
  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;
  fp->flag = (*mode == 'r') ? _READ : WRITE;
  return fp;
}

//this version of fopen does not handle all of the access mode possibilities of the standard, though adding them would not take much code

//in particular our fopen foes not recognize the b that signals binary access, since that is meaningless on unix systems, nor the '+' that permits both reading and writing

//the first call to getc for a particular file finds a count of zero, which forces a call of fillbuf; if fillbuf finds that the file is not open for reading, it returns EOF immediately; otherwise it tries to allocate a buffer (if reading is to be buffered)

//once the buffer is established, fillbuf calls read to fill it, sets the count and pointers, and returns the character at the beginning of the buffer; subsequent calls to fillbuf will find a buffer allocated

#include "syscalls.h"

//filbuf: allocate and fill input buffer
int _fillbuf(FILE *fp)
{
  init bufsize;

  if ((fp->flag & (_READ|_EOF_ERR)) != _READ)
    return EOF;
  bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
  if (fp->base == NULL) //no buffer yet
    if ((fp->base = (char*) malloc(bufsize)) == NULL)
      return EOF; //can't get buffer
  fp->ptr = fp->base;
  fp->cnt = read(fp->fd, fp->ptr, bufsize);
  if (--fp->cnt < 0) {
    if (fp->cnt == -1)
      fp->flag |= _EOF;
    else
      fp->flag |= _ERR;
    fp->cnt = 0;
    return EOF;
  }
  return (unsigned char) *fp->ptr++;
}

//the only remaining thing? how to get started: the array _iob must be defined and initialized for stdin, stdout, and stderr


FILE _iob[OPEN_MAX] = { //stdin, stdout, stderr
  { 0, (char *) 0, (char *) 0, _READ, 0},
  { 0, (char *) 0, (char *) 0, _WRITE, 1},
  { 0, (char *) 0, (char *) 0, _WRITE, | _UNBUF, 2}
};

//the initialization of the flag part of the structure shows that stdin is to be read, stdout is to be written, and stderr is to be written unbuffered



