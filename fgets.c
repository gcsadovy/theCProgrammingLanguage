//fgets in 7.7 line input and output

//the standard library provides an input and output routine fgets that is similar to the getline function that we have used

char *fgets(char *line), int maxline, FILE *fp);

//fgets reads the next input line, including the newline from file fp into the character array line; at most maxline-1 characters will be read

//the resulting line is terminated with '\0'; normally fgets returns line; on an end of file or error it returns NULL; our getline returns the line length, which is a more useful value; zero means end of file

//for output, the function fputs writes a string(which need not containa newline to a file

int fputs(char *line, FILE *fp);

//it returns EOF if an error occues and non-negative otherwise

//the library functions gets and puts are similar to fgets and fputs, but operate on stdin and stdout; confusingly, gets deletes the terminating '\n' and puts adds it

//fgets and fputs from the standard library

//fgets: get at most n chars from iop
char *fgets(char *s, int n, FILE *iop)
{
  register int c;
  register char *cs;


  cs = s;
  while (--n > 0 && (c = getc(iop)) != EOF)
    if ((*cs++ = c) == '\n')
      break;
  *cs = '\0';
  return (c == EOF && cs == s) ? NULL : s;
}

//fputs: put string s on file iop
int fputs(char *s, FILE *iop)
{
  int c;

  while (c = *s++)
    putc(c, iop);
  return ferror(iop) ? EOF : 0;
}


//for no obvious reason, the standard specifies different return values for ferror and fputs

//it is easy to implement the getline from fgets:

//getline: read a line, return length
int getline(char *line, int max)
{
  if (fgets(line, max, stdin) == NULL)
    return 0;
  else
    return strlen(line);
}

