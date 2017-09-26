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

