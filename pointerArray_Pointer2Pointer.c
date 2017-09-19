//pointer arrays; pointers to pointers

//pointers are variables and can be stored in arrays

/* the shell sort function would sort an array of integers; but herewe have to deal 
with lines of text which are different lengths, and which, unlike integers can't be
compared or moved in a single operation

an array of pointers can be called as a dataframe for these text elements

two lines of text can be compared by passing their pointers to strcmp()

when two out of order lines have to be exchanged, the pointerse in the pointer array are exchanged,
not the text lines themselves

*this eliminates the 2 problems of complex storage management and high overhead that would go with moving the
lines themselves

** 3 steps:

1) read all the lines of input
2) sort them 
3) print them in order

1) input routine has to collect and save the characters of each line, and build 
an array of pointers to the lines; it will also have to calculate the number of 
input lines; this is needed for sorting and printing

* if too much input is presented can return an illegal count like -1

3) the output routine only has to print the lines in the order in which they appear in the array
of pointers */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 //max lines to be sorted

char *lineptr[MAXLINES]; //array of pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

//sort input lines
main() 
{
    int nlines; //the number of input lines read 
    
    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else 
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 //max length of any input line

int getline(char *, int);
char *alloc(int)

//readlines: read input lines
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p line[MAXLEN]
    
    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
        if(nlines >= maxlines || p = alloc(len) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0'; //delete new line
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}


//writelines: write output lines
void writelines(char *lineptr[], int nlines)
{
    int i;
    
    for(i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

//getline() is a function from section 1.9

//the main new thing is the declaration for lineptr[]

char *lineptr[MAXLINES];

/* says that lineptr is an array of MAXLINES elements, each element of which is 
a pointer to a character; lineptr[i] is a character pointer, and *lineptr[i] is the
character to which it points, the first character of the i-th saved text line 

since lineptr is an array name, it can be treated as a pointer and writelines can
be written as */

//writelines: write output lines, version 2;
void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}

//initially, *lineptr points to the first line; each element advances it to the
//next line pointer while nlines is counted down

//quicksort from chapter 4 needs some modifications to declarations, comparisons

//algorithm remains the same, so confident that it will still work

//qsort: sort v[left] ... v[right] into increasing order
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    
    if(left >= right) //do nothing if array contains fewer than 2 elements
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1, i <= right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, left, last);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

//swap: interchange v[i] and v[j]
void swap(char *v[], int i, int j)
{
    char *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

//since any individual element of v(alias lineptr) is a character pointer, temp
//must be also, so one can be copied to the other

