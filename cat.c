//cat with error handling added (7.6)

//the treatment of errors in ct is not ideal; if one of the files can't be accessed for some reason, the diagnostic is printed at the end of the concatenated output; that might be acceptable is the output is going to a screen, but not if it's going into a file or another program via a pipeline

//to handle this situation, a second output stream, called stderr, is arrigned to a program in the same way that stdin and stdout are; output ritten on stderr normally appears on the screen even if the standard output is redirected

//revise cat to write its error messages on the standard error

#include <stdio.h>

//cat: concatenate files, version 2 with error handling
main(int argc, char *argv[])
{
  FILE *fp;
  void filecopy(FILE*, FILE *);
  char *prog = argv[0]; //name of the program called for the error ouput

  if (argc == 1) //no args; copy standard input
    filecopy(stdin, stdout);
  else
    while (--argc > 0)
      if ((fp = fopen(*++argv, "r")) == NULL) {
	fprintf(stderr, "%s: can't open %s\n", prog, *argv);
	exit(1);
      }
      else {
	filecopy(fp, stdout);
	fclose(fp);
      }
  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }
  exit(0);
}

//needs filecopy definition from fileAccess.c

//the program signals error in two ways

//diagnostic output  produced by fprintf goes to stderr, so it find its way to the screen instead of disappearing down a pipeline or into an output file

//we included the program name from argv[0] in the message so it this program is used with others, the outce of an error is identified

//the program uses the standard library function exit, which terminates program execution when it is called; the argument of exit is available to whatever process called this one so the success or failure of the program can be tested by another program that uses this one as a subprocess

//conventionally, a return value of 0 signals that all is well; non zero-values usually signal abnormal situations. exit calls fclose for each open output file, to flush out any buffered output

//within main, return expr is equivalent to exit(expr); exit has the advantage that is can be called from other functions, and that calls to it can be found with a pattern-searching program like tose in chapter 5

//the function ferror returns non-Zero if an error occurred on the stream fp

int ferror(FILE *fp);

//although output errors are rare, they do occur, for example if a disk fills up, so a production program should check this as well

//the function feof(FILE *) is analogus to ferror; it returns a non-Zero if the end of file has occurred on the specified file

int feof(FILE *fp);

//any serious program should take care to return sensible, useful status values

