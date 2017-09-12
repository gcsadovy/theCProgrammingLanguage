/* increment and decrement operators */

++				/* adds one to operand */
  --				/* subtracts one from operand */
  ++n == n++			/* BUT as a prefix, it increments before the value is used, 
				   whereas, as a suffix, it increments the value after it has 
				   been used */
  /* the context of use for both of the operators is different, not the
     effect */
  if (n == '5')
  x = n++;			/* sets x to 5 */
x = ++n;			/* sets x to 6 */

    /* in both cases n = 6 */


/* squeeze: delete all c from s */
void squeeze (char s[], int c)
{
  
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
        s[j++] = s[i]; /* everytime a non-c occurs, it is copied to the current j position, and only then is j incremented*/
        
}

/* this is equivalent to: */

    if (s[i] != c)
    {
        s[j] = s[i];
        j++;
    }

/* another example is the getline function from chapter 1 */

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    
/* where it can be replaced by the more compact */

    if (c == '\n')
        s[i++] = c;
    
/* strcat: concatenate t to the end of s; s must be big enough */
void strcat(char s[], char t[])
{
    int i, j;
    
    i = j = 0;
    while (s[i] != '\0') /* find the end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}
    
    