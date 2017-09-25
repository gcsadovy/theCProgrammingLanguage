//specify a grep that is specified by an argument in the command line

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);

//find: print lines that match pattern from the 1st arg
main(int argc, char *argv[])
{
  char line[MAXLINE];
  int found = 0;

  if (argc != 2)
    printf("Usage: find pattern \n");
  else
    while(getline(line, MAXLINE) > 0)
      if(strstr(line, argv[1]) != NULL) {
	printf("%s", line);
	found++;
      }
  return found;
}

//the standard library function strstr(s, t) returns a pointer to the first occurrence of the string t in the string s, or NULL if there is none; declared in <string.h>

//suppose we want to allow two potional arguments: 1) print all the lines except those that match the pattern, and 2) precede each printed line by its line number

//a common convention for c programs on unix systems is that an argument beginswith an inversion, and the -n (number) to requiest line numbering, then the command

find -x -npattern

//will print each line that doesn't match the pattern, preceded by its line number
