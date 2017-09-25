//complicated declarations

//the potentially complicated syntax of c is an attempt to make the declaration and the use agree; it works well for simple cases, but it can be harder to understand convoluted declarations, because they cannot be read left to right, and () are overused

//the diference btw

//int *f(); //function returning pointer to int

//and

//int(*pf)(); //pointer to a function returning int

//illustrates this problem: * is a prefix operator and it has lower precedence than (), so () are necessary to force the proper association

//truly complicated declarations rarely arise in practice; it is important to know how to understand them, and if necessary, how to create them

//a good way to synthesize declarations is in small steps with typedef; as an alternative, there are a pair of programs theat convert from valid C to a word description and back again; reads left to right

//the fist, dcl, is the more complex; it converts a C declaration into a word description:

/*

char **argv
argv: pointer to char
int (*daytab)[13]
  daytab: pointer to array[13] of int
int *daytab[13]
  daytab: array[13] of pointer to int
void *comp()
  comp: function returning pointer to void
void (*comp)()
  comp: pointer to function returning void
char (*(*x())[])()
  x: function returning pointer to array[] of pointer to function returning char

char (*(*x[3])())[5]
  x: array[3] of pointer to function returning pointer to array[5] of char

*/

//dcl is based on the grammar that specifies a declarator, which is dpelled out precisely in appendix A; this is a simplified form:

/* dcl: optional *'s direct-dcl
direct-dcl name
  (dcl)
  direct-dcl()
  direct-dcl[optional size]

*/

//in words a dcl is a direct-dcl, perhaps preceded by *'s; a direct-dcl is a name, or a ()ed dcl, or a direct-dcl followed by (), or a direct-dcl followed by btackets with an optional size;

//this grammar can be used to parse functions; for instance, consider this declarator:

//(*pfa[])()

//pfa will be identified as a name and thus as a direct-dcl; then pfa[] if also a direct-dcl and thus a dcl;

//we can also illustreate the parse with a tree like this:

//the heart of the dcl program is a pair of functions, dcl and sirdcl, that parse a declarartion according to this grammar;

//because the grammar is recursively defined, the functions call each other recusively as they recognize pieces of a declaration; the program is called a recursive-descent parser

//dcl: parse a declarator
void dcl(void)
{
  int ns;

  for (ns = 0; gettoken() == '*'; ) //count *'s
    ns++;
  dirdcl();
  while (ns-- > 0)
    strcat(out, "pointer to");
}

//dirdcl: parse a direct declarator
void dirdcl(void)
{
  int type;

  if (tokentype == '(') { //dcl
    dcl();
    if (tokentype != ')')
      printf("error: missing )\n");
  }
  else if(tokentype == NAME) //variable name
    strcpy(name, token);
  else
    printf("error: expected name or (dcl)\n");
  while ((type = gettoken()) == PARENS \\ type == BRACKETS)
    if (type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
}

//since these programs are intended to be illustratibe, not bullet-proot, there are significant restrictions on dcl;

// it can only hangdle a simple data type line char or int; it does not handle argument types in functions, or qualifiers like const; spurious blanks confuse it; there is no error recovery, so invalid declarations will also confuse it

//main routine and global variables

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype; //type of the last token
char token[MAXTOKEN]; //last token string
char name[MAXTOKEN]; //identifer name
char datatype[MAXTOKEN]; // data type = char, int, etc.
char out[1000];

main() //convert declaratons to words
{
  while (gettoken() != EOF) { //1st token on the line
    strcpy(datatype, token); // is the datatype
    out[0] = '\0';
    dcl(); //parse the rest of the line
    if (tokentype != '\n')
      printf("syntax error\n");
    printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}

//the function gettoken skips blanks and tabs, then finds the next token in the input; a token is a name, a pair of (), a pair of [] perhaps including a number, or any other single character

int gettoken(void) //return next token
{
  int c, getch(void);
  void ungrtch(int);
  char *p = token;

  while ((c = getch()) == ' ' || c == '\t')
    ;
  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    }
    else {
      ungetch(c);
      return tokentype = '(';
    }
  }
  else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']'; )
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  }
  else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch()); )
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  }
  else
    return tokentype = c;
}

//going in the other direction is easier; if we do not worry about generating redundant (), it is very easy

//the program undcl converts a word description like "x is a function returning a pointer to an array of pointers to functions returning char, " which can be expressed as:

//x () * [] * () char

//to

//char (*(*x())[])()

//the abbreviated syntax lets us reuse the gettoken functionl undxl also uses the same external variables as dcl does;

//undcl: convert word descriptions to declarations

main()
{
  int type;
  char temp[MAXTOKEN];

  while (gettoken() != EOF) {
    strcpy(out, token);
    while ((type = gettoken()) != '\n')
      if (type == PARENS || type == BRACKETS)
	strcat(out, token);
      else if (type == '*') {
	sprintf(temp, "(*%s)", out);
	strcpy(out, temp);
      }
      else if (type == NAME) {
	sprintf(temp, "%s %s", token, out);
	strcpy(out, temp);
      }
      else
	printf("invalid input at %s\n", token);
  }
  return 0;
}

