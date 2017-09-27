//formatted output - printf

// the output function printf translates internal values to characters:

int printf(char *format, arg1, arg2, ...);

//printf converts, formats, and prints the arguments on the standard output under control of the format; it returns the number of characters printed

/* the format string contains two types of objects: ordinary chars which are copied to the output stream and conversion specifications, each of which causes conversion and printing of the next successive argument to printf

each conversion specification begins with a % and ends with a conversion character - between the conversion character and the % there may be:

1) a minus sign, which specifies left adjustment of the converted argument
2) a number that specifies the minimum field width; the converted argument will be printed in a field at least this wide; if necessary it will be padded on the left to make up for field width
3) a period, which separates the field width from precision
4) a number, the precision, that specifies the maximum number of characters to be printed from a string, or the number of digits after the decimal point of a floating-point value, or the minimum number of digits for an integer
5) an h if the integer is to be printed as a short, or l if as a long

//conversion chars are shown in table 7.1 on page 167 of the book; if the char after % is not a conversion char, the behavior is undefined

//a width or precision may be specified as *, in which case the value is computer by converting the next argument (which must be an int): to print at most MAXCHAR from a string, s

*/

printf("%.*s", max, s)

// a warning - printf uses its first argument to decide how many arguments follow and what theyr type is; it will get confused ind give wrong answers, if there are not enough arguments or if they are the wrong type

//need to be aware of the difference btw these two calls

printf(s); //fails if s contains %
printf("%s", s) //safe

//the function sprintf does the same conversions as printf does, but stores the output in a string

int sprintf(char *string, char *format, arg1, arg2, ...);

//sprint formats the arguments in arg1, and arg2 according to format, but places the result in string instead of the standard output; string must be big enough to recieve the result

