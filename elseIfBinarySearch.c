/* else-if */

    if (expression)
        statement
    else if (expression)
        statement
    else if (expression)
        statement
    else if (expression)
        statement
    else
        statement
        
/* this is the most general way of writing a multi-way decision */

/* terminal else statement is optional, and can be used for error
checking when passed an 'impossible' condition */

/* check the binary search function below */

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high) 
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

