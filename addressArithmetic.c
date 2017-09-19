//address Arithmetic

/* if p is a pointer to some element of an array, then p++ inccrements p by 1 
and p += i increments p by i. these and otherr constructions are the simplest
forms of pointer or address arithmetic */

//C's strong address arithmetic makes it one of the most useful languages

//need to write a rudimentary storage allocator

/* 2 routines: 1) alloc(n) returns a pointer to n consecutive character positions
which can be used by the caller of alloc() for storing characters, and 2) afree(p)
which releases storage thhus acquired so it can be used later; routines are rudimentary
because calls to afree() must be made in the opposite order to the calls made on alloc()
That is the storage managed by alloc() and afree() is a stack; last-in == first-out
The standard library has functions malloc() and free() that do not have these 
restrictions; easiest to have alloc() hand out pieces of a llarge character array 
that we will call allocbuf; this array is private to alloc() and afree(); they deal
in pointers, not array indicies, so no other routine need know the name of this array;
the array can be declaared static in the source file containing alloc() and afree(), 
and thus be invisible outside of it; the array may not eeven have a name, as if it were
called by malloc() */

//the other information needed is how much of allocbuf has been used
//use pointer allocp that points to the next free element
//when alloc() is asked for n characters, it checks to see if there is enough
//room left in allocbuf.

//if so, alloc() returns the current value of allocp ((i.e. the beginning of the free block))
//then it increments it by n to point to the next free area
//if there is no room, alloc() returns 0
//afree(p) sets allocp to p if p is inside allocbuf

#define ALLOCSIZE 10000 //size of available space

static char allocbuf[ALLOCSIZE] //storage for alloc()
static char *allocp = allocbuf; //next free position //pointer can be initialized like any variable

char *alloc(int n) //return pointer to n characters
{
    if(allocbuf + ALLOCSIZE - allocp >= n) //it fits
    {
        allocp += n;
        return allocp - n; //old p 
    }
    else //not enough room
        return 0;
}

void afree( char *p) //free storage pointed to by p 
{
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        alloccp = p;
}


//the declaration:

static char *allocp = allocbuf;

//defines allocp to be a char pointer and initializes it to pointt to the beginning of allocbuf
//which is the next free position when the program starts
//coould also have been written as:

static char *allocp = &allocbuf[0]

//since the array name is the address of the 0th element

//the test 

if(allocbuf + ALLOCSIZE - allocp >= n) 

//checks to see if there is enough room to satisfy a request for n characters
//if there is, the new value of allocp would be at most one beyond the end of alloccbuf

//if the request can be satisfied, alloc() returns a pointer to the beginning of a block 
//of characters(notice the declaration of the functionn itself); If not, alloc() 
//returns a signal that there is no space left

//C guarantees that 0 is never valid for data, so a return value of 0 can be used to
//signal an abbnormal event

//pointers and integers are not interchangeable; exceppt for 0 

//the symbolic constant NULL is often used in place of 0 for pointers, to indicate that
//it is a special value for the pointer - NULL is defined in <stdio.h>

//ttests like:

if(allocbuf + ALLOCSIZE - allocp >= n)

//and

if(p >= allocbuf && p < allocbuf + ALLOCSIZE)

//show important points of pointer arithmetic

//for example:
//pointers may be compared under certain circumstances;
//iff p and q point to the same array, then operators like ==, !=, < and >= work

p < q 

//is true if p points to an earlier element in the array than q does
//any pointer can be compared to 0 to check (in)equality
//for pointers that point to different arrays, arithmetic is undefined

//a pointer or an integer may be added or subtracted

p + n 

//means the address of the nth object beyond the object that p points to
//this is true regarddless of the type of object;
//n is scaled to the size of the objects that p points to;
//this is in turn determined by the declaration of p 

//ex: if an int is 4 bytes, the int will be scaled by 4

//pointer subtraction is also valid
//if q and p point to the same aarray, and p < q, then:

q - p + 1

//is the number of elements from p to q inclusive
//you can use this to write another version of strlen()

//strlen: return the length of a string 
int strlen(char *s)
{
    char *p = s;
    
    while(*p != '\0')
        p++;
    return p - s;
}

//in its declaration, p is init to s, to point to the first char of the string
//in the while loop each char is compared to '\0' to find thhe end of the string
//p points to charaacters, p++ advances p to the next string character each time
//p - s gives the number of characters aadvanced ovver: the string length

//the header <sttddef.h> defines a type ptrdiff_t that is large enough to hold
//the signed difference of two pointer values

//if being cautious, we would use size_t for the return value of strlen(), to
//match the standard lib definition

//size_t is the unsigned integer type returned by the sizeof operator 

//pointer arithmetic is consistent; if the array had contained floats, then p++
//would have advanced in the same way

//we could write another function that handles floats by replacing all the chars with floats
//pointer manipulations take into account the size of the objects pointed to


}