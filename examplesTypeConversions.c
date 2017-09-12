/* Type conversions */

#include <stdio.h>

main ()
{

  /* automatic conversions of variable types occur when multiple types
     are present in an operation, usually converting a narrower 
     operand type into a wider one, without losing information - i.e.
     converting an int into a float in f +i */

  /* a char is just a small integer, so it can be converted into anything
     else within an operation */
  return 0;
}

/* function atoi: converts string of digits into its numeric equivalent */

atoi (char s[])
{
  int i, n;

  n = 0;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;

  /* sample input: char s['123'] -> int 123 */

}

/* lower maps a single character to lower case */


lower (int c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}

/* this works for ASCII because lower and upper case letters have a fixed
distance apart as numeric values and each alphabet is contiguous -- nothing
but letters b/w a and z */

/* <ctype.h> includes tests and conversions that are independent of character
set. ex: (c >= '0' && c <= '9') == isdigit(c) */

/* specify signed or unsigned if non-character data is to be stored in char
variables for portability */

/* d = c >= '0' && c <= '9' sets d to 1 if it is a digit and 0 if not; however
functions like isdigit may return a non-zero value for true. In test part 
of loops, TRUE == "non-zero", so this makes no difference. */

/* if an operator like + || - (binary: takes two operands) has two types of 
operands, the lower type is promoted to the higher type before the operation.
The result is an int */

/* rules:
    - If either operand is long double, convert the other to long double.
    - Else, if either operand is double, convert the other to double.
    - Else if either operand is float, convert the other to float.
    - Else convert char and short to int
    - If either operand is long, convert the other to long
*/

/* in general functions in <math.h> will use double precision */

/* main reason to use float is to save storage in large arrays */

/* the type of the right side is converted to the type of the left side,
which is the type of the output */

/* left off on page 52 */
