/* conditional expressions */

if ( > b) /* computes the larger of a and b */
    z = a;
else
    z = b;
    
/* the conditional expression with ternary operator "?:", provides an alt*/

expr1 ? expr2 : expr3

/* expr1 is evaluated first; if non-zero, then expr2 is evaluated, and that
is the value of the conditional expression; otherwise, expr3 is evaluated
and that is the value; only one of the expr2 and 3 are evaluated; from
the earlier expression: */

z = (a > b) ? a : b; /* z = max(a, b) */

/* the conditional expression is an expression and can be used wherever and
expression can be used */

/* precedence of "?" is very low, above assignment */

for (i = 0; i < n; i++)
    printf("%6d%c" a[i], (i%10==9 || i==n-1) ? '\n' : ' ');
    
    /* \n is printed after every 10th and nth element; all other elements 
    are followed by one blank; more consise than the equivalent
    if-else statement; another example: */

printf("You have %d items%s.\n", n, n == 1 ? "" : "s");




