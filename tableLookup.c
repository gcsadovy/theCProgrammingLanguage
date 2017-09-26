//table lookup

//this will demonstrate the innards of a table-lookup package to illustrate nmore aspects of structures; this code is typical of what might be found in the symbnol table management routines of a macro processor or a monpiler;

#define IN 1

//the name IN and the replacement text 1 are stored in a table; later when the name IN appears in a statement like:

state = IN;

//it must be replaced by 1

//there are two routines that manipulate the names and replacement texts

//install(s,t) records the name s and the replacement text t in a table; s and t are just character strings;

//lookup(s) searches for s in the table, and returns a pointer to the place where it was found, or NULL if it wasn't there

//the algorithm is a hash-search: the incoming name is converted into a small non-negative integer, which is then used to index into an array or pointers; an array element points to the beginning of a linked list of blocks describing names that have that hash value; it is NULL id no names have hashed to the value

//a block in the list is a structure containing pointers to the name, the replacement text, and the next block on the list; a null next-pointer marks the end of the list;

struct nlist { //table entry:
  struct nlist *next; //next entry in chain
  char *name; //defined name
  char *defn; //replacement text
};

//the pointer array is just

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE]; //pointer table

//the hashing function which is used by both lookup and install, adds eachj cjaracyer value in the string to a scrambled combination of the previous ones and returns the remainder modulo the array size

//this is not the best possible hash function, but it is short and effective

//hash: form hash value for string s
unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

//unsigned aritmetic ensures that the hash value is non-negative

//the hashing process produces a starting index in the array hashtab; if the strnig is to be found anywhere it will be in the list of blocks beginning there;

//the search is performed by lookup; if lookup finds the entry already present, it returns a pointer to it; if not, it retruns NULL

//lookup: look for s in hashtab
struct nlist *lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np; //found
  return NULL; //not found
}

//the for loop in lookup is the standard idiom fgor walking along a linked list:

for (ptr = headl ptr != NULL; ptr = ptr->next)
  ...;

//install uses lookup to determine whether the name being installed is already present; if so, the new definition will supersede the old one; otherwise, a new entry is created; install returns NULL if for any reason there is no room for a new entry

struct nlist *lookup(char *);
char *strdup(char *);

//install: prt (name, defn) in hashtab
struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) { //not found
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else //already there
    free((void *) np->defn); //free previous definition
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}


