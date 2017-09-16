//a register declaration advises the compiler that a variable is going to be heavily used
//register variables are to be placed in machine registers, which can result in smaller and faster programs

/*register declarations look like this;*/

register int x;
register char c;

//the register declaration can only be applied to automatic varibes and to the formal parameters of a function - in the later case it looks like:

f(register unsigned m, register long n)
{
  register int i;
  ...;
}

//there are limits on registered variables, but if you go over it will automatically disregard it 

