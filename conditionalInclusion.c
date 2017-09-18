//conditional inclusion

//it is possible to control preprosessing through conditional statements 
//evaluated before the code is run; in this way, you can selectively include
//or exclude code based on the conditions of the arguments passed

/*the #if line evaluates a constant integer expression (may not include sizeof()
casts, or enum constants); if the expression is non-zero, then the program will
execute until it reaches a #endif, #else, or #elif*/

//the expression defined(name) is 1 if the name has been defined and 0 if not

//to make sure that the contents of a file are included only once, the contents
//of the file are surrounded with a conditional like this:

#if !defined(HDR)
#define HDR

//the contents of hdr.h go here

#endif

//the first inclusion of hdr.h defines the name HDR; subsequent inclusions will
//find the name  defined and skip down to the #endif

/* this style can be used to avoid including files multiple times; if used 
consistently, then each header can itself include other headers on which it depends,
without the user of the header having to deal with the interdependence */

//sequence testing the name SYSTEM to decide which versionof a header to include

#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD 
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif
#include HDR


//the #ifdef and #ifndef lines are specialized forms that test whether a name is defined
//the first example of #if above could have been written as:

#ifndef HDR
#define HDR

/*contents of hdr.h go here */

#endif

//i.e. if you might be calling hdr.h multiple times by different .c files, then 
//using this code at the top of each file to grab header files will prevent you
//from generating hdr.h twice in memory storage; means you can point everything to
//a single file




