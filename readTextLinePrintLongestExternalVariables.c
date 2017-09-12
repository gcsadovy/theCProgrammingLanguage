#include <stdio.h>

#define MAXLINE 1000		/* maximum line input size */

int max;			/* maximum length seen so far */
char line[MAXLINE];		/* current input line */
char longest[MAXLINE];		/* longest line saved here */

int getline (void);
void copyline (void);

/* print longest input line; external variable version */

main ()
{

  int len;
  extern int max;
  extern char line[];
  extern char longest[];

  max = 0;
  while ((len = getline ()) > 0)
    if (len > max)
      {
	max = len;
	copyline ();		/*!!!!!!!!!!!!!bug here - program exits early when a line contains fewer characters than the one before it, but there is a longer character line after it - program will only print the line already stored in longest[] */
      }
  if (max > 0)			/* there was a line */
    printf ("%s", longest);
  return 0;

}

/* getline: v1.1 with external variables */
int
getline (void)
{

  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar ()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n')
    {
      line[i] = c;
      ++i;
    }
  line[i] = '\0';
  return i;
}

/* copyline: v1.1 with external variables */
void
copyline (void)
{

  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}

