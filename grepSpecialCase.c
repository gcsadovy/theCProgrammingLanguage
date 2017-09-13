/* basics of functions */

//design a program to search for a pattern or string of characters in several lines of text;
//this is a specialized case of the UNIX program grep;

//three pieces;

//while (there's another line) -> this is the program getline from earlier
    //if (the line contains the pattern) -> need to write a new function called strindex
	//print it; -> this is the function printf

#include <stdio.h>
#define MAXLINE 1000		//maximum line input length

int getline (char line[], int max);
int strindex (char source[], char searchfor[]);

char pattern[] = "ould";	//pattern to search for

//find all lines matching pattern
main ()
{
  char line[MAXLINE];
  int found = 0;

  while (getline (line, MAXLINE) > 0)
    if (strindex (line, pattern) >= 0)
      {
	printf ("%s", line);
	found++;
      }
  return found;
}

//getline: get line into s, return length
int
getline (char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar ()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

// strindex: return index of t in s; -1 if none
int
strindex (char s[], char t[])
{
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++)
    {
      for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
	   ;
      if (k > 0 && t[k] == '\0')
	return i;
    }
  return -1;
}
