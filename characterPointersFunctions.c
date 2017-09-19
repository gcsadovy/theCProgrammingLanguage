//character pointers and functions

//a string constant is accessed by a pointer to it's first element

//if pmessage is declared as:

char *pmessage

//then

pmessage = "this is not a string copy"

//is a pointer to character array with length = # of elements in array + 1 ('\0')

//C does not provide any operators to operate on a string of chars as a unit

//important difference between:

char amessage[] = "now is the time"; //array
char *pmessage = "now is the time"; //pointer

//amessage is an array big enough to hold all of the elements + '\0'
//if the elements in amessage are changed, amessage still exists

//pmessage is a pointer, initialized to point to a string constant,
//pmessage can be modified to point elsewhere

//need a loop to copy a char string from one variable to another

//strcpy: copy t to s; array subscript version
void strcpy(char *s, char *t)
{
    int i;
    
    i = 0;
    while((s[i] = t[i]) != '\0')
        i++;
}

//compare to

//strcpy: copy t to s; pointer version
void strcpy(char *s, char *t)
{
    int i;
    
    i = 0;
    while((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}

//compare to

//strcpy pointer version2
void strcpy(char *s, char *t)
{
    while((*s++ = *t++) != '\0')
        ;
}

//the value of *t++ was the value that t pointed to before it was incremented
// postfix t++ doesn't change the value of t until after the character has been fetched

//as a final abbreviation, don't compare to '\0' since the function returns either true/false anyway

//strcpy: copy t to s; pointer version 3 
void strcpy(char *s, char *t)
{
    while(*s++ = *p++)
    ;
}

//cryptic but amazingly convienient notation
//these are tropes in C code

//the strcpy() in teh standard lib <string.h> returns the target string as it's function value

//strcmp: return < 0 if s < t, 0 if s == t, > 0 if s > t 
int strcmp(char *s, char *t)
{
    int i;
    
    for(i = 0; s[i] == t[i]; i++)
        if(s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

//the pointer version

int strcmp(char *s, char *t)
{
    for(; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t; 
}



//ex

*--p

//decrements p before fetching the character that p points to
//the pair of expressions:

*p++ = val; //push val onto stack 
val = *--p; //push top of stack into val

//are the standard idiom for pushing and popping a stack

//the header <string.h> contains a variety of relevant functions

