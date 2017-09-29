//file access

//the examples so far have all read the stdio and written the stanard output, which are automatically defined for a program by the local operating system

//write a program that accesses a file that is not already connected to the program; cat represents a program that needs such opertions, which concatenates a set of files into the standard output - cat is used for printing files on the screen and
//as a general purpose input collector for programs that do not have the capability of accessing files by name

//the command

cat x.c y.c

//prints the contents of the files x.c and y.c (and nothing else) on the standard output

//the question is how to arrange for the named files to be read - that is how to connect the external names that a user thingks of to the statements that read the data

//before it can be read or written, a file has to be opened by the library function fopen; fopen thakes an external name like x.c or y.c, does some housekeeping and negotiation with the os a dnr eturns a pointer to be used in subsequent arguments to read or write the file

//this points, called the file pointer, points to a structure that contains information about the file such as
//the location of a buffer
//the current character position in the buffer
//whether the file is being read or written
//whether errors or end of file has occurred


//users don't need to know the details, because definitions obtained from <stdio.h> include a structure declaration called FILE - the only declaration for a file pointer is exemplified by:

FILE *fp;
FILE *fopen(char *name, char *mode);

//this says that fp is a pointer to a FILE, and fopen returns a pointer to a FILE; FILE is a type not a structure tag; it is defined with a typedef

//the call to fopen in a program is:

fp = fopen(name, mode);

//the first argument of fopen is a character string containing the name of the file; the second argument is mode, also a char string indicating how one intends to use the file

//allowable modes include read("r"), write ("w"), and append ("a"); for binary files a "b" must be appended to the mode string on some machines

//if a files that does not exist is opened for writing or appending, it is created if possible; opening an existing file for writing causes the old contents to be discarded, wheile opening for appending preserves them

//trying to read a dile that does not exist is an error, and there nay be other causes of error as well like trying to read a file when you don't have permission

//if there is any error, fopen will return NULL

//the next thing needed is a way to read or write the file once it is open; getc returns the next charcter from a file; it needs the file pointer to tell it which file

int getc(FILE *fp);

//getc returns the next character from the stream referred to by fp; it returns EOF for end of file or error

//putc is an output function:

int putc(int c, FILE *fp);

//putc writes the character c to the file fp and returns the character written, of EOF is an error occurs; like getchar and putchar, getc and putc may be macros instead of functions

//remember that getc and putc came up in a conversation about reading input in c, and they were considered dangerous calls to make





//when a c program is started the os env is responsible for opening three files and providing pointers for them; these files are the standard input, the standard output and the standard error

//the corresponding pointer files are called stdin, stdout, and stderr and are declared in <stdio.h>; normally stdin is connected to the keyboard and stdout and stderr are connected to the screen, but stdin and stdout may be redirected to files or pipes

//getchar and putchar can be defined in terms of getc, putc, stdin, and stdout as follows

#define getchar()  getc(stdin)
#define putchar()  putc((c), stdout)

//for formatted input or output of files, the functions fscanf and fprintf may be used; these are identical to scanf and printf, except that the first argument is a file pointer that specifies the file to be read or written

//the format string is the second argument

int fscanf(FILE *fp, char *format, ...);
int fprintf(FILE *fp, char *format, ...);

//now we can write the program cat to concatenate files; the design is conveinnt for many programs

//if there are command-line arguments, they are interpreted as filenames, and processed in order. If there are no arguments, the standard input is processed#include <stdio.h>

//cat: concatenate files, version 1
main(int argc, char *argv[])
{
  FILE *fp;
  void filecopy(FILE *, FILE *);

  if (argc == 1) //no args; copy standard input
    filecopy(stdin, stdout);
  else
    while (--argc > 0)
      if ((fp = fopen(*++argv, "r")) == NULL) {
	printf("cat: can't open %s\n", *argv);
	return 1;
      }
      else {
	filecopy(fp, stdout);
	fclose(fp);
      }
  return 0;
}


//filecopy: copy file ifp to file ofp

void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}

//the file pointers stdin and stdout are objects of the type FILE *. They are constants, however, not variables, so it is not possible to assign to them

//the function

int fclose(FILE *fp);

//is the inverse of fopen; it breaks the connection between the file pointer andthe external name that was established by fopen, freeing the file pointer for another file

//since most operating systems have some limit on the number of files that a program may jabe opened simultaneously, it is a good idea to free file pointers when they are no longer needed as we did in cat

//it also flushes the buffer in which putc is collecting output; fclose is called automatically for each open file when a program terminates normally

//you can close stdin and stdout if they are not needed - they can also be reassigned by the library function freopen
