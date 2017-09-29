//listing directories

//sometimes you want to know about a file but not what it contains

//the ls command is one example

//fsize: a special ls clone that prints all the sizes of all the files named in its commandline argument list; if one of the files is a directory; it applies itself recursively through that directory

//if there are no arguments at all, it processes the current directory

//a directory is a file that contains a list of file names and some indication of where they are located; the location is an index into another table called the "innode list". The innode for a file is where all information about the file except its name is kept;

//a directory entery generally consists of only two items, the filename and the innode number

//the format and the contents of a directory are not always the same; need to divide the task in two to isolate the non-portable parts

//the outer level defines a structure called a Dirent and three routines opendir, readdir, and closedir to provide system-independent access to the name and inode number in a firectory entry

//the dirent structure contains the inode number and the name; the max length of a filename component is NAME_MAX, which is a system-dependent value; opendir returns a pointer to a structure called DIR, analogous to FILE, which is used by readdir and closedir; this info is collected into a file called dirent.h

#define NAME_MAX 14 //longest filename component - sys dependent

typedef struct { //portable directory entry
  long ino; //inode number
  char name[NAME_MAX + 1]; //name + '\0' terminator
} Dirent;

typedef struct { //minimal DIR: no buffering, etc
  int fd; //file descriptor for the directory
  Dirent d; //the directory entry
} DIR;

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);

//the system call stat takes a filename and returns all of the information in the inode for that file, or -1 if there is a system error

char *name;
struct stat stbuf;
int stat(char *, struct stat *);

stat(name, &stbuf);

//fills the structure stbuf with the inode information for the file name; the structure describing the value returned by stat is in <sys/stat.h>, and looks like:

struct stat //inode information returned by stat
{
  dev_t  st_dev; //device of inode
  ino_t  st_ino; //inode number
  short  st_mode; //mode bits
  short  st_nlink; //number of links to the file
  short  st_uid; //owners user id group
  short st_gid; //owners group id
  dev_t st_rdev; //for special files
  off_t st_size; //file size in characters
  time_t st_atime; //time last accessed
  time_t st_mtime; //time last modified
  time_t st_ctime; //time originally created
};

//the types like dev_t and ino_t are defined in <sys/types.h>, which must also be included

//the st_mode entry contains a set of flags describing the file; the flag definitions are also included in <sys/types.h>, we need only the part that deals with the filetype

