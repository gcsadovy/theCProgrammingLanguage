//standard input and output

//the library implements a simple model of text input and output; a text stream consists of a series of lines that terminate in a new line char

//the simplest imput mechanism is to read one char at a time from the standard input, normally the keyboard, with getchar()

int getchar(void);

//getchar returns the next input character each time it is called, or EOF when it encounters the end of the file; the symbolic constant EOF is defined in <stdio.h>; the value is typically -1, but tests should be written in EOF so as to be independent of the specific value

//the file may be sustituted for the keyboard by using the < convention for input redirection; if a program prog uses getchar, then the command line

prog <infile

//causes prog to read characters from infile instead; prog is not dependent on the switch of file for command line; it is not passed as one of the argvs; input switching is also invisible if the input comes from another program via a pipe mechanism - on some systems:

otherprog | prog

//runs two programs, other prog and prog and pipes the standard output of one prog into the other prog

//the function:

int putchar(int)

//is used for output: putchar(c) puts the character c on the standard output, which is by default the screen; putchar returns the character written, or EOF is an error occurs

//output can be directed to a file with >filename; if prog uses putchar

prog >outfile

//will write the standard output to the outfile instead

//output produced by printf also finds its way to the standard output; calls to putchar() and printf() may be interleaved; output happens in the order in which the calls are made

//each source file that refers to an input/output library function must contain the line

#include <stdio.h>

//before the first reference

//when the name is bracketed by <> a search is made for the header in a standard set of places

//many programs read and write only one output stream each; for these getchar, putchar, and printf are sufficient; this is particularly true is redirection is used to coerce the output from one program into the input of another program

#include <stdio.h>
#include <ctype.h>

main() //lower: convert input to lower case
{
  int c;

  while ((c = getchar()) != EOF)
    putchar(tolower(c));
  return 0;
}

//tolower() is defined in <ctype.h>; it converts an uppercase  letter into a lower case letter and returns other characters untouched

//functions like getchar and putchar in <stdio.h> and tolower in <ctype.h> are often macros, avoiding the overhead of a function call per-character; programs that implement these programs are shielded from knowledge of the character set

