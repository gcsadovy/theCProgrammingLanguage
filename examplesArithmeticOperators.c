/* arithmetic operators */

#include <stdio.h>

main ()
{

    /* binary arithmetic operators are +, -, *, and / and the modulous
     operator %. Integer division truncates a fractional part */

    int x = 5, y = 3;

    printf ("%d", x % y)		/* produces 2, the remainder of x / y */
    /* determine leap year by divisibility: leap divisible by 4 and 400,
       but not by 100 */
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        printf ("%d is a leap year\n", year);
    else
        printf ("%d is not a leap year\n", year)
      /* the % operator cannot be applied to either a float or a double */
}
