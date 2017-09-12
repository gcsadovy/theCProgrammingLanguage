#include <stdio.h>

int power(int m, int n); /* function prototype - has to agree with the 'power' function - parameter names are not consequential and do not need to be defined*/
/* well chosen names are good documentation, so better to include them*/

/* test power function*/

main() {
    
    int i;
    
    for (i = 0; i < 10; ++i) /* initializes i as 0, while i is less than 10, and after computing add 1 to i*/
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
    return 0;
}

/* power: riase base to the n-th power; n >= 0 */
int power(int base, int n) {
    int i, p;
    
    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

/* example of the power function calling by value - more concise and compact */

/*

int power(int base, int n)
{
    int p;
    
    for(p=1; n > 0; --n)
        p = p * base;
    return p;
}



