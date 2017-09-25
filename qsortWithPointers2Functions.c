//a function is not a variable, but it is possible to defin pointers to functions, which can be assigned, placed in arrays, passed to functions, returned by functions, and so on;

//for the following example: qsort that will sort the input lines numericallu instead of lexographically if the optional -n argument is passed

//a sort consists of three parts: a comparison the determines the ordering of any pair of objects, an exchange that reverses that order, and a sorting algorithm that makes comparisons and exchanges until the objects are in order

//the sorting algorithm is independent of the comparision and exchange operations; so passing different comparison and exchange functions to it we can arrange to sort by different criteria

//lexigraphic comparison of two lines is done by strcmp, as before; we will also need a routine numcmp that compares two lines on the basis of numeric value and returns the same kind of condition indication as strcmp does

//these functions are declared ahead of main and a pointer to the appropriate one is passed to qsort;

//no error passing for arguments here

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 //max #lines to be sorted
char *lineptr[MAXLINES]; //pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int(*comp)(void *, void *));

int numcmp(char *, char *);

//sort input lines
main(int argc, char *argv[])
{
  int nlines; //number of input lines read;
  int numeric = 0; //1 if numeric sort

  if(argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void**) lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  }
  else {
    printf("input too big to sort\n");
    return 1;
  }
}

// in the call qsort, strcmp and numcmp are addresses of functions; since they are known to be functions, the & is not necessary in the same way that it is not needed before an array name

//this qsort can process any data type, not just character strings

//as indicated in the function prot6otype, qsort expects an array of pointers, two integers, and a function with two pointer arguments.

//the generic pointer type void * is used for the pointer arguments;
//any pointer can be cast to void * and back again without loss of information, so we can call qsort by casting arguments to void *;

//the elaborate cast of the function argument casts the arguments of the comparison function;

//these will generally have no effect on actual represnetation, but assure the compiler that all is well

//qsort: sort v[left]...v[right] into increasing order

void qsort(void *v[], int left, int right, int(*comp)(void *, void *))
{
  int i, last;

  void swap(void *v[], int, int);

  if(left >= right) //do nothing if array contains
    return; //fewer than two elements
  swap(v, left, (left + right) / 2);
  last = left;
  for(i = left + 1; i <= right; i++)
    if((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1, comp);
  qsort(c, last + 1, right, comp);
}

//the fourth parameter of qsort is:

int (*comp)(void *, void *);

//says that comp is apointer to a function that has two void * arguments and returns an int

//the use of comp in the line

if((*comp)(v[i], v[left]) < 0);

//is consistent with the declaration: comp is a pointer to a function, *comp is the function, and:

(*comp)(v[i], v[left])

//is the call to it; without parentheses

int *comp(void *, void *) //WRONG

//says that comp is a function returning a pointer to an int, which is very different

//numcmp compares two strings on a leading numeric value, computed by calling atof:

#include <stdlib.h>

//numcmp: compare s1 and s2 numerically
int numcmp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if(v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

//the swap function which exchanges two pointers, is identical to what we presented earlier in the chapter, except that the declarations are changed to void *

void swap(void *v[], int i, int j;)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}


