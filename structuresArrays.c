//arrays of structures

//consider writing a program to count the sccurrences of each C keyword; need an array of character strings to hold the names, and an array of integers for the counts; you can use two parallel arrays, keyword and keycount, as in:

char *keyword[NKEYS];
int keycount[NKEYS];

//but if the arrays are parallel, then it suggests the possibility of an array of structures with each keyword as a pair:

char *word;
int cout;

//and there is an array of pairs; the structure declaration:

struct key {
  char *word;
  int count;
} keytab[NKEYS];

//declares a structure type key, defines an array keytab of structures of thus type, and sets aside storage for them; each element of the array is a structure

//it could also have been written as:

struct key {
  char *word;
  int count;
};

struct key keytab[NKEYS];

//since the structure keytab contains a constant set of names, it is the easiest to make it an external variable and initialize it one and for all when it is defined; initialization is analogous to earlier ones - the definition followed by a list of initializers enclosed in braces:

struct key {
  char *word;
  int count;
} keytab[] = {
  "auto", 0,
  "break", 0,
  "case", 0,
  "char", 0,
  "const", 0,
  "continue", 0,
  "default", 0,
  //...
  "unsigned", 0,
  "void", 0,
  "volatile", 0,
  "while", 0
};

//the initializers are listed in pairs coresponding to the structure members; it would be more precise4 to enclose the initializers for each "row" or structure in braces as in:

{ "auto", 0 },
{ "break", 0 },
{ "case", 0 },
...

//but inner braces are not necessary when the initializxers are simple variables or character strings, and when all are present

//the number of entries in the array keytab will be computed if the initializers are present and the [] is left empty

//the program begins with the definition of keytab; the main routine reads the input by repeatedly calling a function getword that fetches one word at a time

//each word is looked up in keytab with a version of the binary search function that we wrote earlier in chap 3; the list of keywords must be sorted in increasing order in the table;

#include <stdio.h>
#include <ctype.h>
#include 

  
