#include <stdio.h>

/* strlen: return length of s */


strlen (char s[])
{

  int i;

  i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
  
}
