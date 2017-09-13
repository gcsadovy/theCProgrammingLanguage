/* switch */

/* the switch statement is a multi-way decision that tests whether an experssion matches
one of a number of constant int values, and branches accordingly */

/*
    switch (expression)
    {
        case const-expr: statements
        case const-expr: statements
        default: statements
    }
*/

/* if a case matches the expression vale, then the execution starts
at the case; default is executed if none of the other cases are satisfied;
default is optional; cases and default clause can occur in any order */

/* countDigitWhiteSpaceOther but now with switch instead of if-else 
statements */

#include <stdio.h>

main() /* count digits, white space, others */
{
    int c, i, nwhite, nother, ndigit[10];
    
    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c-'0']++;
                break; /* causes an immediate exit from switch; need to do this, otherwise the program falls through to the next case and eats up valuable processing time */
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            default:
                nother++;
                break;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
    return 0;
}


/* break and return are the most common ways to leave a switch */

/* a break statement can be used to force an immediate exit from while, for, and do loops */

/* fall throughs should be used sparingly and should be commented; the 
program may be less robust with fall throughs */

/* adding a break at the end of default is unnecessary, but it consititutes
defensive programming; someone will come along and add antoher case to 
the program */


