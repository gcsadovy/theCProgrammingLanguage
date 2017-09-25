//an elaboration of an earlier grep model

//a commonconvetion for c programs on unic systems is that an argfument that begins with a minus sign introduces an optional flag or parameter; if we chose -x (for except) to signal the inversion and -n (number( to request the line numbering then the command

find -x -npattern

//will print each line that doesn't match the pattern, preceded by its line number

//optional arguments should be permitted in any order; the rest of the program should be independent of the number of arguments that we present; further more, is is convienitnt for used if optional arguments can be combined, as in:

find -nx pattern

//here is the program

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);

//find: print lines that match pattern from 1st arg
main(int argc, char *argv[])
{
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;

  while(--argc > 0 && (*++argv)[0] == '-')
    while(c = *++argv[0])
      switch(c) {
      case 'x':
	except = 1;
	break;
      case 'n':
	number = 1;
	break;
      default:
	printf("find: illegal option %c\n", c);
	argc = 0;
	found = -1;
	break;
      }
  if(argc != 1)
    printf("Usage: find -x -n pattern\n");
  else
    while(getline(line, MAXLINE) > 0) {
      lineno++;
      if((strstr(line, *argv) != NULL) != except) {
	if(number)
	  printf("%ld:", lineno);
	printf("%s", line);
	found++;
      }
    }
  return found;
}

//argc is decremented and argv is incremented before each optional argument. Ar the end of the loop, if there are no errors, argc tells how many arguments remain unprocessed and argv points to the first of these. Thus argv should be 1 and *argv should point at the pattern

//notice that *++argv is a pointer to an argument string so (*++argv)[0] is its first character (an alternate valid form would be: **++argv); because [] binds tighter than * and ++ the patentheses are necessary; without them the expression woulf be taken as *++(argv[0]); that is what we have used in the inner loop, where the task is to walk along a specific argument string; in the inner loop, the expression *++argv[0] increments the pointer argv[0]!

//it is rare that one uses pointer expressions more complicated than these; in such cases, breaking them into two or three staps will be more intuitive




