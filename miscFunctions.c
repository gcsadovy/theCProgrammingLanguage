//the standard library has a wide variety of functions - this file denotes a few of them

//string operations

//there are the string functions strlen, strcpy, strcat, and strcmp found in <string.h>; in the following, s and t are char *'s and c and n are ints

strcat(s, t) //concatenate t to the end of s

strncat(s, t, n) //concatenate n char of to to the end of s

strcmp(s, t)  //return negative, zero, or positive for s < t, s == t, s > t

strncmp(s, t, n) //same as strcmp but only in first n char

strcpy(s, t) //copy t to s

strncpy(s, t, n) //copy at most n characters of t to s

strlen(s) //return length of s

strchr(s, c) //return pointer to firse c in s or NULL if not present

strrchr(s, c) //return pointer to last c in s, or NULL if not present



//character class testing and conversion

//several functions from <ctype.h> perform character tests and conversions; in the following c is an int that can be represented as an unsigned char or EOF; the function returns int

isalpha(c) //non-zero if c is alphabetic, 0 if not

isupper(c) //!= 0 if c is uppercase, 0 if not

islower(c) //same if lowercase, 0 if not

isdigit(c) //positive if c is a digit, 0 if not

isalnum(c) //positive if isalpha(c) or isdigit(c), 0 if not

isspace(c) //positive if c is blank, tab, newline, return, formfeed, vertical tab

toupper(c) //return c converted to uppercase

tolower(c) //return c converted to lowercase



//ungetc

//the standard library provides a restricted version of the function ungetch from chapeter 4.0 called ungetc

int ungetc(int c, FILE *fp)

//pushes the character c back onto the file fp and returns either c or EOF for an error

//only one character of pushback is guaranteed per file; ungetc may be used with any of the input functions like scanf, getc, or getchar




//command execution

//the function system(char *s) executes the command contained in the character string s, then resumes the execution of the current program; on unix systems the statement:

system("date");

//causes the program date to be run; it prints the date and time of day on the standard output; system returns a system-dependent integer status from the command executed

//in the unix system, the status return is the value returned by exit



//storage management

//the functions malloc and calloc obtain blocks of memory dynamically

void *malloc(size_t n);

//returns a pointer to n bytes of uninitialized storage, or null if the request cannot be satisfied

void *calloc(size_t n, size_t size);

//returns a pointer to enough free space for an array of n objects of the specified size, or NULL if the request cannot be satisfied; the storage is initialized to zero

//the pointer returned by malloc or calloc has the proper alignment for the object in question, but it must be cast into the appropriate type, as in:

int *ip

ip = (int *) calloc(n, sizeof(int));

//free(p) frees the space pointed to by p, where p was originally obtained by a call to calloc or calloc; there are no restrictions on the order in which space is freed, but it is a ghastly error to free something not obtained by calling malloc or calloc

//it is also an error to use something after it has been freed; a typical but incorrect piece of code is this loop that frees items from a list:

for (p = head; p != NULL; p = p->next) //wrong
  free(p);

//the right way is to save whatever is needed before freeing

for (p = head; p != NULL; p =q) {
  q = p->next;
  free(p);
 }



//mathematical functions

//more than 20 functions declared in <math.h>; each takes one or two double argumnts and returns a double

sin(x) //sine of x, x in radians

cos(x) //cosine of x in radians

atan2(y,x) //arctangent of y/x in radians

exp(x) //exponential function e^x

log(x) //natural (base e) logrithm of x (x > 0)

log10(x) //common (base 10) logarithm of x (x > 0)

pow(x, y) // x^y

sqrt(x) //square root of x (x > 0)

fabs(x) //absolute value of x




//random number generation

//the function rand() computes a sequence of pseudo-random integers in the range zero to RAND_MAX, which is defined in <stdlib.h>

//one way to produce random floating-point numbers greater than or equal to zero but less than one is

#define frand() ((double) rand() / (RAND_MAX + 1.0))

//if your library already has a function for floating point random numbers, it probs has better statistical distribution than this one

//the function srand(unsigned) sets the seed for rand; the portable implementation of rand and srand suggested by the standard appears in 2.7
