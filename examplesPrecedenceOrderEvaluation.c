/* Precedence and order of evaluation */

/* Operators:                   Associativity:

() [] -> .                       left to right
! ~ ++ -- + - * (type)sizeof     right to left
* / %                            left to right
+ -                              left to right
<< >>                            left to right
< <= > >=                        left to right
== !=                            left to right
&                                left to right
^                                left to right
|                                left to right
&&                               left to right
||                               left to right
?:                               right to left
= += -= *= /= %= &= ^= |= <<= >>=right to left
,                                left to right


 - unary & +, -, and * have higher precedence than binary forms */
 
 if ((x & MASK) == 0) ...
 
/* bit testing expressions must be fully parenthesized */

x = f() = g();

/* the order the operands of the operator are evaluated in is not specified */
/* thus x can depend on the order of evaluation, if it is changed within 
the operand; you can use dummy variables to store temporary results to ensure
a particular sequence */

printf("%d %d\n", ++n, power(2, n)); /* WRONG; produces different results
                                     on different compilers based on whether
                                     n is incremented before or after power is called;
                                     the solution is: */
                                     
++n;
printf("%d %d\n", n, power(2, n));

/* it is bad form to write code where the output depends on the order
of evaluation within the function or statement */
