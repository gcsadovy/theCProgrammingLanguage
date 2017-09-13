// goto and labels

/* goto is infinately abusable and almost never necessary in c; however
there are some cases where it can be used to exit from a deeply nested
loop where break cannot work, as it only breaks out of the innermost
loop, and does not have the ability to break out of two loops at once */

    for (...)
        for(...) 
        {
            ...
            if (disaster)
                goto error;
        }
    ...
error:
    /* clean up the mess */
    
/* this is handy when the error handling code is non-trivial, and if errors
can occur in several places */

/* the label has the same form as a variable name, and is followed by a colon;
it can be attached to any statement in the same function as goto; the scope
of the label is the entire function */

// determine whether 2 arrays a and b have an element in common

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (a[i] == b[j])
                goto found;
    /* didn't find any common element */
    ...
found:
    // got one: a[i] == b[j]
    ...
    
// code with a goto never has to use the goto, perhaps at the price of an extra variable

    found = 0;
    for (i = 0, i < n && !found; i++) //!found == found != 1 != TRUE
        for (j = 0; j < m && !found; j++)
            if (a[i] == b[j])
                found = 1;
    if (found)
        // got one: a[i] == b[j]
        ...
    else
       /* didn't find any common element */
       ...
       

//code with goto statements is generally harder to maintain;
//if you don't need to use it, you probably shouldn't 