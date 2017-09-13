/* loops - while and for */

/* for (expr1; expr2; expr3)
        statement
        
    ==
    
    expr1;
    while (expr2) {
        statement
        expr3;
    }

*/

/* any of the three for expressions can be omitted, but the ;s must remain;
if the test, expr2 is not present it is taken as permenantly true; thus

    for (;;) {
        ...
    }

is an infinite loop, to be broken by a break or return expression; */

/* using while or for is a matter of personal preference */

    while ((c = getchar()) == " " || c == '\n' || c = '\t')
        ; /* skip white space characters */
        
/* no initialization or reinitialization, so while is natural */

/* for is preferrable with a simple initialization and an increment; it
keeps the loop statements close together and visible at the top of the loop */
    
    for (i = 0; i < n; i++)
    
/* it is bad form to force unrelated computations into the initialization and 
increment of a for; better reserved for loop control operations */

/* skip white space, if any
get sign, if any
get integer part and convert it */

#include <ctype.h>

/* atoi: convert s to integer; v2.0 */
int atoi(char s[])
{
    int i, n, sign;
    
    for (i = 0; isspace(s[i]); i++) /* skip the white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

/* the stdio.h includes a more elaborate function to convert strings to
long: strtol() */

/* the Shell sort (D.L. Shell, 1959) is designed to compare far-apart elements
early on, rather than adjacent ones as in simpler interchange sorts; this
tends to elininate large amounts of disorder quickly, so later stages have 
less work to do; the interval between compared elements in gradually decreased to 1,
at which point the sort effectively becomes an adjacent interchange method. */



/* shellsort: sort v[0] ... v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    
    for (gap = n/2; gap > 0; gap /= 2) /* controls gap between elements */
        for (i = gap; i < n; i++) /* steps along elements */
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) /* compares elements and reverses if out of order */
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}

/* , operator in c is mainly used in for statements; a pair of expressions
separated by a comma is evaluated left to right; the type and value of the 
result are the type and value of the operand;it is possible to put multiple 
expressions in the various parts of a for loop, for instance to process
two indicies in parallel */

#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* , that separate function arguments are not comma operators and do not
guarantee left to right evaluation; */

/* comma operators should be used sparingly; most suitable in constructs 
that are strongly related to each other, like a for loop or a macro where
a multistep computation has to be a single expression; the exchange of 
elements in reverse can be thought of as a single operation */

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;



