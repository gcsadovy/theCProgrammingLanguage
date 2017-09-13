/* loops: do-while */

/* while and for loops test the termination conditon at the top of the loop;
Do-While loops test the termination condition at the bottom of the loop after
making each pass through the loop body; the Do-While loop is always executed
at least once; */

/* syntax */

    do 
        statement
    while (expression);
    
/* the statement is executed and then the expression is evaluated; if TRUE
the statement is executed again; if not the loop terminates; */

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    
    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;
    do /* generate digits in reverse order */
    {
        s[i++] = n %10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if  (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}