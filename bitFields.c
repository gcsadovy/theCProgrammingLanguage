//when storage space is at a premium. you have to pack several objects into a single machine word; one common use is a set of single-bit flags in applications like compiler symbol tables;

//externally imposed data formats, such as hardware devices also require tha ability to get at pieces of a word

//the most compact way to encode a piece of information about a certain identifier is in a set of one-bit flags or in a single char or int

//the usual way this is done is to define a set of "masks" corresponding to the relevant bit positions, as in

#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04

//or

enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };

//the numbers must be powers of 2

//accessing the bits becomes a matter of "bit-fiddling" with the shifting, masking, and complementing operators that were described in chapter 2

//certain idioms appear frequently

flags |= EXTERNAL | STATIC;

//turns on the EXTERNAL and STATIC bits in flags, while

flags &= ~(EXTERNAL | STATIC);

//turns them off, and

if ((flags & (EXTERNAL | STATIC)) == 0) ...;

//is true if both bits are off

//C offers the capability of dedining and accessing dields within a word directly rather than by bitwise operators; a bit-field or field is a set of adjacent bits within a single implementation-defined storage unit that we will call a word; the symbol table #defines could be replaced with:

struct {
  unsigned int is_keyword : 1;
  unsigned int is_extern : 1;
  unsigned int is_static : 1;
} flags;

//this defines a variable table called flags that contains three 1-bit fields
//the number following the colon represents the field width in the bits; the fields are declared unsigned int to ensure that they are unsigned quantities

//individual fields are referenced the same way as other structure members: flags.is_keyword etc

//fields behave like small integers, and may participate in arithmetic expressions just like other integers; the previous examples may be written as:

flags.is_extern = flags.is_static = 1;

//to turn the bits on;

flags.is_extern = flags.is_static = 0;

//to turn them off, and

if (flags.is_extern == 0 && flags.is_static == 0);

//to test them

//everything about fields is implementation dependent

//unnamed fields (a colon and a width) are used for padding

//special width 0 may be used to force alignment at the next word boundary

//right to left or opposite assignment of fields is machine dependent

//fields are not arrays, and thus don't have addresses, so the operator & cannot be applied to them


  

