//typedef

//C provides a facilityu called typedef for creating new data type names; for example, the declaration:

typedef int Length;

//makes the name Length a synonym for int; the type Length can be used in declarations, casts, rtc, in the same ways that the int type can be;

Length len, maxlen;
Length *lengths[];

//and the declaration

typedef char *String;

//makes String a synonym for char * or character pointer, which may then be used in declarations and casts;

String p, lineptr[MAXLINES], alloc(int);
int strcmp(String, String);
p = (String) malloc(100);

//the type being declared in a typedef appears in the position fo a variable name, not right after the word typedef; syntactically, typedef is like the storage classes extern, static, stc; we have used capitalized names for typedefs to make then stand out;

//we could make typedefs for the tree nodes shown earlier

typedef struct tnode *Treeptr;

typedef struct tnode { //the tree node:
  char *word; //points to the text
  int count; //number of occurrences
  struct tnode *left; //left child
  struct tnode *right; //right child
} Treenode;

//this creates two new type keywords called Treenode (a structure) and Treeptr (a pointer to the structure); then the routine talloc could become

Treeptr talloc(void)
{
  return (Treeptr) malloc(sizeof(Treenode));
}

//a typedef declaration does not create a new type; it only creates a name for a type that already exists; variables declared this way have the exact same properties as variables whose declarations are explicit

//in effect, typedef is like #define, except that since it is interpreted by the compiler, it can cope with textual substitutions that are beyond the capabilities of the preprocessor; for example:

typedef int (*PFI) (char *, char *);

//creates the type PFI for "pointer to function (of two char * arguments) returning int" which can be used in contexts like:

PFI strcmp, numcmp;

//in the sort program in chapter 5

//two reasons to use typedefs

//to parameterize a program against portability problems; if typedefs are used for data types that may be machine-dependent, only the typedefs ned change when the program is moved;

//a common situation in using typedef, is to use typedef names for various integer quantutues, then make an appropriate set of choices of short, int, and long for rach host machine; types like size_t and ptrdiff_t from the standard lib are examples

//the second purpose of typedefs is to provide better documenta5tion for a program; a type called Treeptr may be earier to understand than one declared only as a pointer to a complicated structure


