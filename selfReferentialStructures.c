//self referential structures

//suppose that you want to count the occurences of all the words in some input; since the list of words isn't known in advance, we can't conveniently sort it and use a binary search

//but we can't do a linear search fir each word as it arrives, to see if it;s already been seen; the program would take too long; more precisely its running time is likely to grow quadratucally with the number of input words

//how to organize a dataset to copy efficiently with a list of arbitrary words?

//one solution: to keep the set of words seen so far sorted at all times, by placing each word into its proper position in the order as it arrives; this shouldn't be done by shifting eotfd in a linear array, though - that also takes too long

//instead we will use a data structure called a binary tree

//tree contains one "node" per distinct word; each node contains
/* 1) a pointer to the text of the word
2) a count of the number of occurrences
3) a pointer to the left child node
4) a pointer to the right child node
*/

//no node may have more than two children; it might have only zero or one

//nodes are maintained so that at any node the left subtree contains only words that are lexicographically less than the word at the node, and the right subtree contins only words that are greater;

//to find out whether a new word is already in the tree start at the root and compare the new word to the word stored at that node; if the match, the question is answered affirmatively;

//if the new record is less than the tree word, continue searching at the left child, otherwise at the right child; if there is no child in the required direction, the new word is not in the tree, and in fact the empty slot is the proper place to add the new word

//this process is recursive, since the search from any node ises a search from one of its children; Accordingly, recirsive routines for inserion and printing will be most natural;

//the node is represented as a structure with 4 components:

struct tnode { //the tree node:
  char *word; //points to the text
  int count; // nuimber of occurrences
  struct tnode *left; //left child
  struct tnode *right; //right child
};

//this recursive declaration of a nude might look chancy buyt it's correct; it is illegal for a structure to contain an instance of itself, but:

struct tnode *left;

//deckares left to be a pointer to a tnode, not a tnode itself

//occasionally one needs a variation of self-referential structures: two structures that refer to each other; the way to handle this is:

struct t {
  ...
  struct s *p; //p points to an s
};
struct s {
  ...
  struct t *q; // q poinras to a t
};

//the code for the whole program is suprisingly small, given a handful of supporting routhins like getword that we have already written; the main routhine reads words with getword and installs them in the tree with addtree;

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

//word frequency count
main()
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);
  treeprint(root);
  return 0;
}

//the function addrtree is recursive; a word is presented by main to the top level the root of the tree; at each stage that word is compared to the word already stored at the node and is perdolated doen to either the left or the right subtree by a recurvive call to addtree

//eventually, the word either matchers something slready in the tree, in which case the count is incremented, or a null pointer is encountered, indicating that a node must be created and added to the tree

//if a new node is created, addtree returns a pointer to it, which is installed in the parent node;

struct tnode *talloc(void);
char *strdup(char *);

//addtreeL add a node with w, at or below p
struct treenode *addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL) { //a new wpord has arrived
    p = talloc(); //make a new node
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++; //repeated word
  else if (cond < 0) // less than into left subtree
    p->left = addtree(p->left, w);
  else //greater than into right subtree
    p->right = addtree(p->right, w);
  return p;
}

//storage fior the new node is fetched by a routine talloc which returns a pointer ro a free space suitable for holding a tree node, and the new word is copied into a hidden space by strdup;

// the count is initialized and the two children are made null; this part of the code is executed only at the leaves of the tree, when a new node is being added; we have omitted error checking on the values returned by strdup and talloc;

//treeprint prints the tree in sorted orderl at each node it prints the left subtree (all the words less than this word), then the word itself, then the right subtree (all the words greater);

//if you feel shaky about how recursion works, simulate treeprint as it operates on the tree shown above

//treeprint: in-order print of the tree p
void treeprint(struct tnode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->countm p->word);
    treeprint(p->right);
  }
}

//if the tree becomes "unbalanced" because the words don't arrive in random order, the running time of the program can grow too much; as a eorst case, id the words are already in order, this program does an expensive simulation of linear search

//there are generalizations of the binary tree that do not suffer from this worst-case behavior, but we will not describe them here

//it is desireable that there be only one storage allocator in a program, even though it allocates all different kinds of objects;

//but if one allocator is to process requests for, say pointers to chars and pointers to struct tnodes, there are two questions:

//how does it meet the requirement of most real machines that objects of certain types muct satisfy alignment restructions (for example, integfers often must be located atr even addresses)?

//what declararions can cope with the fact that an allocator must necerrarily return different kinds of pointers?

//alignment requirements can generally be satisfied easily, at the cost of some wasted space, by ensuring that the allocator always returns a pointer that meets all alignment restructions;

//the alloc does not guarantee any particular alighment, so we will use the standard lib function malloc which does;

//in C the proper method is to declare that malloc returns a pointer to void then explicitly coerce the pointer into the desired ty[pe with a cast; malloc and related routines are declared in the standard header <stdlib.h>; thus talloc can be written as;

#include <stdlib.h>

//talloc: make a tnode
struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

//strdup copies the string given by its argument into a safe place, obtained by a call on malloc:

char *strdup(char *s) // make a duplicate of s
{
  char *p;

  p = (char *) malloc(strlen(s) + 1); // +1 for '\0'
  if (p != NULL)
    strcpy(p, s);
  return p;
}

//malloc returns NULL id no space is available; strdup passes that value on, leaving error-handling to its caller

//storage obtained by calling malloc may be freed for re-use by calling free





