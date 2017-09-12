#include <stdio.h>

#define MAXLINE 1000

/* Declarations: varius codings in declarations */

/* examples include: */

main(){
    
    int lower, upper, step;
    char c, line[1000];
    
    /* using \n to declae different variables has the advantage of 
    giving you a chance to comment on each of the variables as they 
    are passed */

    /* variables can also be initialized in the declaration */
    
    char esc = '\\';
    int i = 0;
    int limit = MAXLINE + 1;
    float eps = 1.0e-5;
    
    /* external and static variables are initialized to 0 by default */
    
    /* the aualifier const can be applied to the declaration of any 
    variable to specify that the value of the variable will not be
    changed */
    
    const double e = 2.71828182845905;
    const char msg[] = "warning: "; /* the function does not change the array */
    int strlen(const char[]);
    
}









