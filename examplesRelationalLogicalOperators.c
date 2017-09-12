/* relational and logical operators */

#include <stdio.h>

main ()
{
    
    int i, c, lim
    char s[]
    
    /* the relational operators are > >= < <= all with the same 
    precedence below them in precedence are == and != */

    (i < lim-1) == (i < (lim-1))

    /* relational operators are below arithmetic operators in 
    precedence */
    
    /* the logical operators are && and ||; expressions are evaluated 
    left to right and evaluation stops when truth or falsehood of the
    result is known */
    
    for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
        
    /* precedence of && is higher than ||, and both are of lower precedence
    than relational and equality variables - expressions like the one below
    do not need any parentheses */
    
    i < lim-1 && (c=getchar()) != '\n' && c!= EOF
    
    /* since precedence of != is higher than assignment, you need () */
    
    (c = getchar()) != '\n';
    
    /* numeric value of relational/logical expression = 1 if TRUE &
    0 if FALSE */
    
    /* unary negation operator ! converst a non-zero operand into 0 and
    a zero operand into 1. see below: */
    
    if (!valid) /* read: if "not valid" */
    
    /* rather than */
    
    if (valid == 0)
    
    /* equivalent for loop without && or || */
    
    int i = 0
    while(i < lim - 1)
        if((c=getchar()) != '\n')
            if(c != EOF) {
                s[i] = c;
                ++i
            }
    
    
}
