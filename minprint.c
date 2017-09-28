//variable length argument lists

//minprinf will process the fomat string and arguments but will call the real printf to do the format conversions

//the proper declaration for printf is:

int printf(char *fmt, ...);

//where the ... means that the number and types of these arguments may vary; the declaration ... can only appear at the end of an argument list

//minprintf is declared as

void minprintf(char *fmt, ...);

//since we do not return the character count that printf does

//how does minprintf walk along the argument list when the list doesn't have a name

// <stdarg.h> contains a set of macro definitions that define how to step through an argument list

// the type va_list is used to declare a variable that will refer to each argument in turn; in minprintf, this variable is called ap, for "argument pointer."

//the macro va_start initializes ap to point to the first unnamed argument; it must be called before ap is used; there must be at least one named argument; the final named argument is used by va_start to get started

//each call of va_arg returns one arguments and steps ap to the next; va_arg uses a type name to determine what type to return and how big a strp to take; finally va_end does whatever cleanup is necessary; it must be called bfore the program returns

//these properties for the basis of this powerful generic printf

#include <stdarg.h>

//minprint: generic printf with variable argument list
void minprintf(char *fmt, ...)
{
  va_list ap; //points to each unnamed arg in turn
  char *p, *sval;
  int ival;
  double dval;

  va_start(ap, fmt); //make ap point to the 1st unnamed argument);
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p) {
    case 'd':
      ival = va_arg(ap, int);
      printf("%d", ival);
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf("%f", dval);
      break;
    case 's':
      for (sval = va_arg(ap, char *); *sval; sval++)
	putchar(*sval);
      break;
    default:
      putchar(*p);
      break;
    }
  }
  va_end(ap); //cleanup when done
}

//this generic print function does not contain all of the possible arguments that can be passed with printf; for instance, it does not handle any precision characters or long or short calls;

//in order to improve this minprint, you would have to go back and possibly change the default; and then possibly add another for loop that looked at ++(++p) to see if there were characters after p that also fulfilled conditions

//you would definitely have to add ot the conditional functions by which the first if loop operates, and possibly add another if loop at the end

//might want to consider a call of isdigit() to check for digits, and *p == '.'

//need to go back and consider all of the arguments listed in chapter 7.2




      
