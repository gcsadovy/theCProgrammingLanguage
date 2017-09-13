/* break and continue */

/* the break statement provides an exit from a for, while, do-while loop, 
just as it did with switch; a break causes the intermost loop or switch to
be terminated immediately; */

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[]) 
{
    int n;
    
    for (n = strlen(s) - 1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n + 1] = '\0';
    return n;
}

/* continue statements cause the next iteration of the enclosing for, while
or do loop to begin; in the while and do this means that the test part is executed immediately;
for for loops control passes to the increment/decrement; continue does not 
apply to switches; a continue inside a switch inside a loop causes the next loop iteration */

    for (i = 0; i < n; i++)
        if (a[i] < 0) /* skip negative elements */
            continue;
        ... /* do positive elements */
        
/*the continue statement is often used when the part of the loop that follows
is complicated, so that reversing a test and indenting another level would nest the program
too deeply */

