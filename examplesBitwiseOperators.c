/* bitwise operators */

/* c has six operators that are special to bitwise operations that can 
only be used with integers (char, long, short, int; unsigned or signed)
& == bitwise AND;
| == bitwise inclusive OR;
^ == bitwise exclusive OR;
<< == left shift
>> == right shift
~ == one's complement (unary)

*/

/* & can be used to mask off bits whereas | can be used to turn bits on; */
/* the OR operator ^ sets a one in each bit position where its operands have
different bits and a zero where they are the same. */

/* need to distinguish from && and ||; 
int x=1, y=2;
x & y == 0
x && y == 1 
*/

/* << and >> perform left and right shifts of their left operand by the number
of bit positions given by the right operand; must be non-neg; thus, x << 2 
shifts the value of x by two positions, filling vacated positions with zero;
this is equivalent to multiplication by 4; */

/* the unary ~ yields the one's complement of an int; it converts each 1 bit 
into a 0 bit and vice versa */

x = x & ~077 /* sets the last 6 bits of x to 0 */

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n); /* need to figure out what the hell this is doing */
}
