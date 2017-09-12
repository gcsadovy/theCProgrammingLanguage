#include <stdio.h>

/* strlen: return length of s */
/* strlen() is defined in the standard header <string.h> */


strlen (char s[])
{

  int i;

  i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
  
}
