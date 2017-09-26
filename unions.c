//unions

/* a union is a variable that may hold (at different rimes) objects of different types and sizes with the compuler keeping track of size and alignment requirements;

unions provide a way to manipulate different kinds of data in a single area of storage, without embedding any machine-dependent information in the program; 

as an example such as might be found in a compiler symbnol table manager, suppose that a constant may be anm int, a float, or a char *; 

the value of a particular constant muct be stored in a variable of the proper type, yet it is most convenient for table management id the value occupies the same amount of storage and is stord in the same place regardless of its type

this is the purpose of a union - a single variable that can legitimately hold any of one of several types

the syntax is based on structures:
*/

union u_tag {
  int ival;
  float fval;
  char *sval;
} u;

//the variable u will be large enough to hold the largest of the three typesl the specific size is implementation-dependent

//any of these types may be assigned to u and then used in expressions, so long as the usage is consistent; the type retrived must be the type most recently stored

//it is the programmers respondibility to kee[ track of which type is currently stored in a union; the results are implementaion-deoendent if something is stored as one type and extracted as another
//syntactaclly members of a union are accessed as

//union-name.member

//or

//union-pointer->member

//just as for structures; if the variable utype is used to kee- track of the current type in stored in u, then on might see code such as

if (utype == INT)
  printf("%d\n", u.ival);
if (utype == FLOAT)
  printf("%f\n", u.fval);
if (utype == STRING)
  printf("%s\n", u.sval);
 else
   printf("bad type %d in utype\n", utype);

//unions may occur within structures and arrays, and vice versa; the notation for accessing a member of a union in a structure (or vice versa) is identical to that for nested structures

//in the structure array defined by:

struct {
  char *name;
  int flags;
  int utype;
  union {
    int ival;
    float fval;
    char *sval;
  } u;
} symtab[NSYM];

//the member ival is referred to as

symtab[i].u.ival

//and thje first character opf thje string sval by either of

*symtab[i].u.sval

symtab[i].u.sval[0]

//in effect a union is a structure in which all members have offset zero from the base, the structure is big enough to hold the widest member, and the alignment is appropriate for all of the types in the union

//functions are the same as with a structure: assignment to or copying as a unit, taking the address, and accessing a member

//union may only be initialized with a value of the ty[e of its first member; thus union u described above can only be initialized with an integer value

//the storage allocator in chapter 8 shows how a union can be used to force a variable to be a;igned on a particular kind of storage boundary

