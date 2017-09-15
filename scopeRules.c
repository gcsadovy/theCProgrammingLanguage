
// the scope of a name is the part of the program within which the name can be used
//for an aoutmatic variable called at the beginning of a function, the scope is the function in which the name was declared
//local variables with the same names are unrelated; as are parameters
//in this example, sp and val may be used in push and pop by naming them, but these names are not visible in main, nor are push and pop themselves

//main() {...}

//int sp = 0;
//double val[MAXVAL];

//void push(double f) {...}

//double pop(void) {...}


//but if the external variable is referred to before it is defined, or if defined in a different source file than the one calling it: an extern declaration is mandatory

//a declaration of an external varibale announces the properties of the variable
//a definition also causes storage to be set aside

//functions push and pop could be defined in one file, and the variables val and sp defined and initialized in another - then definitions and declarations would be necessary to tie them together:

//file1

//  extern int sp;
//  extern double val[];

//  void push(double f) {...}

//  double pop(void) {...}

//file2

//int sp = 0
//double val[MAXVAL]



