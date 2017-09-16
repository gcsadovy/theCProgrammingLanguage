//functions may not be defined within other functions, thus c does not have a block structure
//however variables within a function can be defined in a block structured fashion; declarations of variables may follow the left brace that introduces any compound statement; not just the one that begins the function
//in this way, you can hide variables in the outer blocks, as they remain in existence until the next right brace

if(n > 0)
  {
    int i; //declare a new i

    for (i = 0; i < n; i++)
      ...;
  }

//the scope of the i is the true branch of the if statement
//it is initialized everytime that the block is entered

int x;
int y;

f(double x)
{
  double y;
}
//within the function f, x refers to the parameter which is a double
//outside f, they refer to the external int

//as a matter of style: avoid variable names the conceal names in an outer scope; the potential for error and confusion is too great
