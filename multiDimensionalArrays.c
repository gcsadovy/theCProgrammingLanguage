//multi-dimensional arrays

/* C provides rectangular multi-dimensional arrays, although they are much less used
than arrays of pointers

consider the problem of date conversion; from day of the month to day of the year
and vice versa

Ex: march 1st is the 60th day of a non-leap year, and the 61st of a leap year

lets define two functions; one that converts month and day into the day of the year
and one that does the opposite transformation

since the latter function computes two values, the month and day arguments will be pointers*/

month_day(1988, 60, &m, &d)

//sets m to 2 and d to 29 (Febuary 29th)

/* each of these functions needs the same information, a table of the number of days in each month 

since the number of days per year varies with leap years it's easier to separate them into two rows 
of a two dimensional array than to keep track of what happens to February during computation

the array and functions for performing the transformations is:*/

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

//day of the year: set day of the year from month & day
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    
    for(i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

//month_day: set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for(i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

//recall that the arithmetic value of a logical expression, such as one for leap
//is either 0 if FALSE and 1 if TRUE, so it can be used as a subscript of the array daytab

//the array deaytab has to be external to both day_of_year and month_day, 
//so that they can both use it

//here it is char to demonstrate the legitmate use of char for storing small non-character integers

//in C a two dimentional array is really a 1D array each of whose elements are an array

daytab[i][j] //[row][col]

//rather than

daytab[i, j] //WRONG

/* elements are stored by rows, so the rightmost subscript, column, varies fastest as 
elements are accessed in storage order

an array is initialized by a list of initializers in braces; each row of a 2D array is 
initialized by a corresponding sub-list; we started daytab with a column of zero
so that the month numbering would match reality; 

if a 2D array is to be passed to a function, the parameter declaration must contain the 
number of columns; the number of rows is irrelevant, since what is passed is, as before 
a pointer to an array of rows, where each row is an array of 13 ints; here it is a pointer to objects that
are arrays of 13 ints

thus if the array daytab is to be passed to a function f, the declaration of f would be
*/

f(int daytab[2][13]) { ... }

//it could also be

f(int daytab[][13]) {...}

//because the rows are irrelevant, or it could be

f(int (*daytab)[13]) { ... }

/* which says that the parameter is a pointer to an array of 13 integers; () are
necessary since [] have higher precedence than *  */

int *daytab[13]

//gives you an array of 13 pointers to integers

//only the first dimension of an array is free; all others have to be specified