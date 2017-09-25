//structures and functions

//legal operations with structures:
//copying it or assigning it as a unit
//taking its address with &
//accessing its members

//copy and assignment include passing arguments to finctions and returning values from functions as well; structures may not be compared; a structure may be initialized by an assignment

//some functions to manipulate points and rectangles; three possible approaches
//[ass components separately
//pass an entire structure
//pass a pointer to it

//each has its ups and downs

//makepoint: make a point from x and y components
struct point makepoint(int x, int y)
{
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}

//there is no conflict between the argument name and the member with the same name; the re-use of the names stresses the relationship

//makepoint can now be used to initialize any structure dynamically, or to provide structure arguments to a function:

struct rect screen;
struct point middle;
struct point makepoint(int, int);

screen.pt1 = makepoint(0,0);
screen.pt2 = makepoint(XMAX, YMAX);
middle = makepoint((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y + screen.pt2.y)/2);

//the next step is to add some functions to do arithmetic on points; for instance:

//addpoints: add two points
struct addpoint(struct point p1, struct point p2)
{
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

//here both the argumernts as well as the return type are structures; the structures are incremented to emphasize that structure parameters are passed by value like any others

//we have adopted the convention that a rectangle includes its left and bottom sides but not its top and right sides:

//ptinrect: return 1 if p in r, 0 if not
int ptinrect(struct point p, struct rect r)
{
  return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

//assumes the rectangle is presented in a stanfdard form where the pt1 coordinates are less than the pt2 coordinates; the following returns a rectangle guaranteed to be in canonical form:

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

//canonrect: canonicalize coordinates of rectangle
struct rect canonrect(struct rect r)
{
  struct rect temp;

  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y - max(r.pt1.y, r.pt2.y);
  return temp;
}

//if a large structure is to be passed to a function, it is generally more efficient to pass a pointer than to copy a whole structure; structure pointers are just like pointers to ordinary variables;

struct point *pp;

//says that pp is a pointer to a structure of type struct point; if pp points to a point structure, *pp is the structure and (*pp).x and (*pp).y are the members


struct point origin, *pp;

pp = &origin;
printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);

//the () are necessary in (*pp).x because the precedence of the structure member operator . is higher than *; the expression *pp.x means *(pp.x), which is illegal ghere because x is not a pointer

//pointers to structures are so frequently used that there is a shorthand; if p is a pointer to a structure:

p->member-of-structure

//reders to the partuiclar number; so you could write:

printf("origin is (%d,%d)\n", pp->x, pp->y);

//both . and -> associate from left to right, so if:

struct rect r, *rp = &r;

//then these expressions are equivalent

r.pt1.x
rp->pt1.x
(r.pt1).x
(rp->pt1).x

//structure operators . and ->, along with () for function calls and [] for subscripts are at the top of the precedence hierarchy, and thus bind very tightly

struct {
  int len;
  char *str;
}
*p;

//then

++p->len

//increments len and not p because the implied () is:

++(p->len)

//to alter binding

(++p)->len

//increments p before accessing len, and

(p++)->len

//increments p after accessing len

//in the same way *p->str fetches whatever str points to;

*p->str++

//increments str after accessing whatever it points to (just like *s++);

(*p->str)++

//increments whatever str points to;

*p++->str

//increments p after accessing whatever str points to

