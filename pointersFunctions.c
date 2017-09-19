//pointers and function arguments

/* c passes arguments by value; no direct way for the called function to alter
a variable in the calling function; not enought to write something like:*/

swap(a, b);

//where the swap function is defined as:

void swap(int x, int y) //WRONG
{
    int temp;
    
    temp = x;
    x = y;
    y = temp;
}

//because of call by value, swap() can't affect the arguments a and b in the 
//routine that called it; the function above swaps copies of a and b

//the way to obtain the desired effect is to add pointers to the values of a and b

swap(&a, &b); //interchange *px and *py)

void swap(int *px, int *py)
{
    int temp;
    
    temp = *px;
    *px = *py;
    *py = temp;
    
}

//&a is a pointer to a; in swap() the parameters are declared as pointers,
//and the operands are accessed indirectly through them

//*px gives you a pointer to the value of the variable that was passed as 
//the first argument; *py gives you the value of the second variable


//this allows you to access and change objects in the function that called it
//VERY USEFUL!!! A FUNCTION THAT CHANGES THE VARIABLES OF THE FUNCTION THAT CALLED it

//a solution to returning both an int value as well as an EOF value is to return 
//EOF as the function value and to use a pointer argument to store the converted 
//integer back in the calling function - used by scanf() as well

//the following loop fills an array with integers by calls to getint()

int n, array[SIZE], getint(int *);

for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;
    
//each call sets array[n] to the next integer found in the input

//getint() returns EOF if end of file, 0 if the input is not a number,
//and 1 if the input contains a valid number

#include <ctype.h>

int getch(void);
void ungetch(int);

// getint: get next integer from input into *pn 

int getint(int *pn)
{
    int c, sign;
    
    while(isspace(c = getch())) //skip white spaces
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-')
    }
        ungetch(c); //c is not a number
        return 0;    
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c --'-')
        c = getch();
    for(*pn = 0; isdigit(c), c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if(c != EOF)
        ungetch()
    return c;
}

//throughout getint, *pn is used as an ordinary int variable 
//we also used getch() and ungetch() so that the one extra character that must be
//read can be pushed back onto the input



