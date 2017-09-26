//the keyword counting program written to use pointers instead of arrays

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

//count C keywords; pointer version
main()
{
  char word[MAXWORD];
  struct key *p;

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      if ((p = binsearch(word, keytab, NKEYS)) != NULL)
	p->count++;
  for (p = keytab; p < keytab + NKEYS; p++)
    if (p->count > 0)
      printf("%4d %s\n", p->count, p->word);
  return 0;
}

//binsearch: find word in tab[0]...tab[n - 1]
struct key *binsearch(char *word, struct key *tab, int n)
{
  int cond;
  struct key *low = &tab[0];
  struct key *high = &tab[n];
  struct key *mid;

  while (low < high) {
    mid = low + (high - low) / 2;
    if ((cond = strcmp(word, mid->word)) < 0)
      high = mid;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return NULL;
}


//several things of note here; first, the declaration of binsearch must indicate that it returns a pointer to struct key instead of an integer; this is declared in both the function prototype and in binsearch; if binsearch finds the word it returns a pointer to it; if it fails it returns NULL;

//the elements of keytab are now accessed by pointers; this requires significant changes in binsearch

//the initializers for low and high are now pointers to the beginning and just past the end of the table

//the computation of the middle element can no longer be simply

mid = (low + high) / 2; // wrong

//because the addition of pointers is illegal; subtraction is legal however, so high-low is the number of elements, and thus:

mid = low + (high-low) / 2;

//sets mid to the element halfway between low and high

//the most important change is to adjust the algorithm to make sire that it does not generate an illegal pointer or attempt to access an element outside the array

//both &tab[-1] and &tab[n] are outside the limits of the array tab

//the former is strictly illegal, and it is illegal to dereference the latter

//the language definition does guarantee however that pointer arithmetic that involves the first element beyond the end of an array (that is, &tab[n]) will work correctly

//in main

for (p = keytab; p < keytab + NKEYS; p++);

//if p is a pointer to a structure, arithmetic on p takes into account the size of the structure, so p++ increments p by the correct amount to get the next element of the array of structures, and the test stops the loop at the right time;

//dont assume tjat thje size of a structure is the sum of the sizes of its menbers

//because of alignment requirements for different objects, there may be unnamed "holes" in a structure; thus for instance is a char is one byte and an int four bytes, the structure:

struct {
  char c;
  int i;
};

//might require eight bytes, not five; the sizeof operator returns the proper value

// when a function returns a complicated type like a structure pointer, as in:

struct key *binsearch(char *word, struct key *tab, int n);

//the function names can be hard to see, and to find with a text editor; accordingly, an alternate style is sometimes used:

struct key *
binsearch(char *word, struct key *tab, int n);

//but this is a matter of personal taste

