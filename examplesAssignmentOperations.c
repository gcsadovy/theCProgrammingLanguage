#include <stdio.h>

/* assignment operators and expressions */

i = i + 2;
/* can be written in the compressed form: */
i += 2;
/* the operator += is called an assignment operator; most binary operators
with two operands, have a corresponding assignment operator op=, where op:
is one of:

+  -  *  /  %  <<  >>  &  ^  |

*/

/* if expr1 and expr2 are expressions, the first is equivalent
to the second */

(expr1 op= expr2) == (expr1 = (expr1) op (expr2))

/* but expr1 is only computed once */

(x *= y + 1) == (x = x * (y + 1)) != (x = x * y + 1)

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;
    
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

/* declaring the argument x to be unsigned ensures that when right shifted, vacated bits will be filled
with zeros, not sign bits; assignment operators are not only consise, but they correspond to the way
that people think; i.e. "add 2 to i" || "increment i by 2" NOT "take i, add 2, then put the result back 
in i"; thus: */

i += 2;

/* is preferable to */

i = i + 2;

/* for a complicated expression: */

yyval[yypv[p3+p4] + yypv[p1]] += 2;

/* is more intuitivly understood and perhaps more efficient for the compiler */


/* assignment statments can occur in expressions: */

while ((c = getchar()) != EOF)

