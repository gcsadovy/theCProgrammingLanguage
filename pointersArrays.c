//pointers and arrays

//strong relationship between the two
//a pointer will be faster but harder to understand

int a[10]
//defines an array of size 10, a block of 10 consecutive objects named a[0]...a[9]
//he notation a[i] refers to the ith element in the array
     int *pa
//pointer to an integer, then
       pa = &a[0]
//sets pa to point to element zero of a; that is pa contains the address of a[0]
       x = *pa
//copies the contents of a[0] into x
//if pa points to an element n in an array then pa + 1 = a[n + 1], and pa + i = a[n + i]
//the value of a variable of expression of type array is the address of element 
//zero in that array; thus
       pa = &a[0];

//pa and a have identical values; since the name of an array is a synonym to the 
//first object in that array you can also assign using:

pa = a;

//a reference to

a[i]
//can also be written as
  * (a + i)
//in evaluating a[i], c converts it to *(a+i) immediately; the two forms are equivalent
  & a[i] == a + i
//a + i is the address of the ith element beyond a
  pa[i] == *(pa + i)
//an array and index expression is the same as one written as a pointer and offset
//REMEMBER: a pointer is a variable, so pa = a and pa++ are legal; an array name
//is not a variable; a = pa and a++ are illegal
/*when an array name is passed to a function, what is passed is the address of the 
initial element; within the called function, this argument is a local variable, 
and so an array name paramenter is a pointer, that is a variable ontaining an address
*/
//strlen: return the length of a string
     int strlen (char *s)
{
  int n;

  for (n = 0; *s != '\0', s++)
    n++;
  return n;
}


/*since s is a pointer, incrementing it is perfectly legal; s++ has no effect on 
the character string in the function that called strlen, but merely increments
strleng's private copy of the pointer; calls like:*/

strlen ("hello world");		//string constant
strlen (array);			//char array[100]
strlen (ptr);			//char *ptr

//are all valid operation; as formal parameters in a function

char s[];

//and

char *s
//are equivalent - we prefer the latter, because it says explicitly that the 
//variable is a pointer; when an array name is passed to a function, the function
//can at it's conveinence believe that it has been handed either an array or a pointer
//and manipulate accordingly
//it is possible to pass part of an array to a function by passing a pointer to the
//beginning of the subarray; if a is an array:
f (&a[2])
//and
f (a + 2)
//both pass to the function f the address of the subarray that starts at a[2]
//within f, the parameter definition can read:
f (int arr[])
{
...}

//or 

f (int *arr)
{
...}

//to f it is of no consequence that the parameter refers to a larger array

//if you are sure that elements exist, you can index backwards in an array

p[-1] p[-2]
//refer to the elements that immediately preceed p[0]; it is illegal to refer to
//objects that are not within the array bounds
