//keyword counting program

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD

int getword(char *, int);
int binsearch(char *, struct key *, int);

//count C keywords
main()
{
  int n;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      if ((n = binsearch(word, keytab, NKEYS)) >= 0)
	keytab[n].count++;
  for (n = 0; n < NKEYS; n++)
    if (keytab[n].count > 0)
      printf("%4d %s\n", keytab[n].count, keytab[n].word);
  return 0;
}

//binsearch: find wors in tab[0]...tab[n - 1]
int binsearch(char *word, struct key tab[], int n)
{
  int cond;
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if ((cond = strcmp(word, tab[mid].word)) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

//each call to getword finds a word, whicvh is copied into the array named as its first argument

//the quantuty NKEYS is the number of keywords in keytab

// you could set this by hand, but much less risky to have the machine do it especially if the list is subject to change
//one possibility would be to terminate the list of initializers with a null pointer, then loop along keytab until the end is found

//this is more than is needed

//we can do it with size of keytab/size of struct key

//C provides a compile time unary operator called sizeof that can be used to compute the size of any object; the expressions:

sizeof object

//and

sizeof(type name)

//yield an integer equal to the size of the specified object or type in bytes

//strictly, sizeof produces an unsigned integer value whose type, size_t, is defined in the header <stddef.h>

//an object can be a variable or array or structure

//a type name can be the name of a basic type like int or double, or a derived type like a structure or a pointer

//in this case the number of keywords is the size of the array divided by the size of one element; this computation is used in a #define statement to set the value of NKEYS:

#define NKEYS (sizeof keytab / sizeof(struct key))

//another way to write this is to divide the array bu the size of a specific element

#define NKEYS (sizeof keytab / sizeof(keytab[0]))

//this has the advantage that it does not need to be changed if the type changes

//a sizeof expression cannot be used in a #if line, because tghe preprocessor does not parse type names; but the expression in the #define is not evaluated by the preprocessor, so the code is legal here

//getword: more general than is necessary; it fetches the next "word" from the input, there a word is either a string of letters and digits beginning with a letter, or a single non-white space character

//the function value is the first character of the word or EOF for end of file, or the character itself if it is not alphabetic

//getword: get next word or character from input
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace (c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

//uses the getch and ungetch from chapter 4

//when the collection of an alphanumeric token stops, getword has gone one character too far; the call to ungetch pushes that charactyer back on the input for the next call

//getword also uses isspace to skip whitespace, isalpha to identify letters, and isalnum to identify letters and digits; all are from the standard header <ctype.h>


