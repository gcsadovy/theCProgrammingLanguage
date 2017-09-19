//pointers and arrays

//pointers have been conbined with goto() to form impossible to read code
//pointer to void is the generic pointer

//pointers and addresses

/* talking about memory; a typical machine has an array of consequitively 
numbered or addressed memory cells that may be maniuplated individualy
or in contiguous groups; any byte can be a char, a pair of one byte cells can be 
a short integer. amd four adjacent bytes to form a long - a pointer is a group
of cells, often two or four, that hold an address - so if c is a char, and p is a 
pointer that points to it, you could represent it as a block referencing a block
*/

p = &c

//the unary operator & gives the address of the object; this statement assigns the
//address of c to the variable p, and p is said to point to c; the & only applies
//to objects in memory: variables and array elements; it cannot be applied to
//expressions, constants, or register variables

//the unary operator * is the dereferencing or indirection operator; when applied
//to a pointer, it accesses the object that the pointer points too

// x and y are integers, and ip is a pointer to int

int x = 1, y = 2, z[10];
int *ip //ip is a pointer to int

ip = &x //ip now points to x 
y = *ip //y is now 1
*ip = 0 //x is now 0 
ip = &z[10] //ip now points to z[10]

//the expression int *ip is intended as a mnemonic; it says that the expression
//*ip is an int; the syntax for the declaration for a variable mimics the syntax
//of expression in which a variable might appear

//applies to functions as well

double *dp, atof(char *) 

//says expression *dp and atof(s) have values of double, and that the argument
//atof is a pointer to char

//a pointer is restricted to a single data type (unless it is a pointer to void)

//if ip points to an integer, then it can occur anywhere an integer could

*ip = *ip + 10

//increments ip by 10

y = *ip + 1

//takes whatever ip points to, adds one, and then assigns the value to y

*ip += 1

//increments what *ip points to, as do 

++*ip

//and

(*ip)++

//parentheses are necessary, such that you don't increment ip, rather than
//the thing it points to (unary operators associate right to left)

//pointers are variables, can be used without dereferencing

int *iq
int *ip

iq = ip

//copies the contents of ip to iq, making iq a pointer to whatever ip was pointed to




