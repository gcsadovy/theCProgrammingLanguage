//formatted input

// the function scanf is the input analog of printf, providing many of the same conversion facilities in the opposite direction

int scanf(char *format, ...);

/* scanf reads characters from the standard input, interprets them according to the specification in format, and stores the results through the remaining arguments

the other arguments (not format), each of which must be a pointer, indicated where the corresponding converted input should be stored

this is a summary of the most important features not an exhaustive list

scanf stoprs when it exhausts its format string, or when some input dails to match the control specification; 

it returns as its value the number of successfully matched and assigned input items; this can be used to decide how many items were found;

on the EOF, EOF is returned; note that this is different from 0, which means that the next input character does not match the first specification in the format string

the next call to scanf resumes searching immediately after the last character already converted

there is also a function sscanf that reads from a string instead of the standard input */

int sscanf(char *string, char *format, arg1, arg2, ...);

//it scans the string according to the format in format and stores the resulting values through arg1, arg2, etc; these arguments must be pointers

//the format string ususally contains conversion specifications, which are used to control conversion of input; the format string may contain:

//blanks or tabs, which are not ignored
//ordinary characters (not %), which are expected to match the next non-white space character of the input stream
//conversion specifications, consisting of the char %, an optional assignment suppression character *, an optional number specifying a maximum field width, an optional h, 1 or L indicating the width of the target, and a conversion character

/* a conversion specification directs the conversion of the next input field; normally the result is placed in the variable pointed to by the corresponding argument

if assignment suppression is indicated by the * char, the input filed is skipped; no assignment is made;

an input field is defined as a string of non-white space characters; it extends wither to the next white space character or until the filed width, is specified, is exhausted

this implies the scanf will read accross boundaries to find its input, since newlines are counted as white space - white space characters are blank, tab, newline, carriage return, vertical tab, and formfeed

the conversion character indicates the interpretation of the input field; the corresponding argument must be a pointer, as required by the call by value semanitcs of C (padding additional space around a call to a type with less bytes, or picking the byte to scale down to less bytes)

//conversion characters are in table 7.2

