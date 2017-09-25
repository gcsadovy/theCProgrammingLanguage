//structures & structure basics

//structure: a collection of one or more variables, possibly of different typ[es, frouped together under a sinfle name for convenient handling

//structures help to organize complicated data, particularly in large programs, because they permit a group of related variables to be treated as a unit instrad of as separate entities

//am example is a payroll record; another: a point is a pair of coordinates, and a rectangle is a pair of points and so on

//structures may be copied and assigned to, passed to functions, and returned byy functions; automatic structures and arrays may now also be initialized

//basics

//structures for graphics

//the basic object is a point, which has two integer components, an x and a y value, declared like this

struct point {
  int x;
  int y;
};

//struct introduces a structure declaration, which is a list of declarations enclosed in braces

//an optional name called a structure tag may follow the word struct as with point here; the tag names the kind of structure, and can be used subesquently as a shorthand for the part of the declaration in braces

//the variables named are called members; a structure member or tag and an ordinary (non-member) variable can have the same name without conflict, since they are always distinguished by context

//the same member names may occue in different structures, though they should be closely related objects

//a struct declaration defines a type; the right brace that terminates the list of members may be followed by a list of variables just as for any basic type

struct {...} x, y, z;

//is analogous to

int x, y, z;

//the declaration tag can be used in definitions of instances of the structure

//given the declaration of point eariler,

struct point pt;

//defines a variable pt which is a structure of type struct point. A structure can be initialized by folloeing its definition with a list of initialisers, each a constant expression, for the members:

struct maxpt = { 320, 200 };


//an automatic structure may also be initialized by assignment or by calling a function that returns a structure of the right type

//a member of a structure is referred to in an expression by the construction form:

//structure-name.member

//tje structure member operator . connects the structrure name to the member name

printf("%d, %d", pt.x, pt.y);

//prints the coordinates of point (x, y)

//or to compute the distance from the origin (0, 0) to pt

double dist, sqrt(double);

dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);

//structures can be nested; example is a rectangle

struct rect {
  struct point pt1;
  struct point pt2;
};

//the rect structure contains two point structures; if we declare screen as

struct rect screen;

//then

screen.pt1.x

//refers to the x coordinate of the prt member of the screen
