/* if-else */

/* the if-else statement is used to express decisions; the syntax is */

    if (expression)
        statement1
    else
        statement2
        
/* where the else part is optional; the expression is evaluated; if 
it is true, statement1 is executed; if it is false and there is an else, 
then statement2 is executed instead */

    if (expression) == if (expression != 0)
    
/* there is an ambiguity if an else is left blank; this can be solved by 
associating the else with the closest if statement */

if ( >0)
    if ( > b)
        z = a;
    else
        z = b

/* ambiguity is bad in situations like this: */

if (n > 0)
    for (i = 0; i < n; i++)
        if (s[i] > 0) {
            printf("...");
            return i;
        }
else            /* WRONG */
    printf("error -- n is negative\n");
    
/* good idea to use braces for nested if statments */