//pointers and multidimensional arrays

//given the definitions

int a[10][20];
int *b[10];

/* then a[3][4] and b[3][4] are both syntactically legal references to the same
object, a single int; 

but a is a true two dimensional array: 200 int sized locations have been set aside
and the conventional subscript calculation 20 * row + col is used to find the 
element a[row][col] 

for b however, the definition only allocates 10 pointers and does not initialize them
initialization must be done explicitly; either statically or with code

assuming that b does point to a 20 element array, 200 ints will be set aside along
with 10 cells for the pointers

the advatage of using the pointer array to reference the array is that the pointer
array can reference rows in an array that are of different lengths;

each element of b need not be a 20 element vector; some may point to 2 elements,
some may point to 50



by far the most common use of pointers is to store character strings of diverse
lengths, as in the function month_name

compare */

char *name[] = {"Illegal month", "January", "Febuary", "March"};

//with

char aname[][15] = {"Illegal month", "January", "Febuary", "March"};

//in the first, it uses only enough chars to store the names and the pointers

//in the second, it gives a char with a length of 15 to each of the months, even
//if there is no more information to be recorded

