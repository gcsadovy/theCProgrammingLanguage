// the main routine deals with commandline arguments, it hands each argument to the function fsize

#include <stdio.h>
#include <string.h>
#include "syscalls.h"
#include <fcntl.h>  //flags for read and write
#include <sys/type.h>  //typedefs
#include <sys/stat.h> //structure returned by stat

void fsize(char *);

//print file name/s
main(int argc, char **argv)
{
  if (argc == 1) //default: current directory
    fsize(".");
  else
    while (--argc > 0)
      fsize(*++argv);
  return 0;
}

//the function fsize prints the size of the file; if the file is a directory however, fsize first calls dirwalk to handle all of the files in it; the flag names S_IFMT and S_IFDR are used to decide if the file is a directory; ()s matter because the precedence of & is lower than that of ==

int stat(char *, struct stat *);
void dirwalk(char *, void (*fcn) (char *));

//fsize: print the name of the file name
void fsize(char *name)
{
  struct stat stbuf;

  if (stat(name, &strbuf) == -1) {
    fprintf(stderr, "fsize: can't access %s\n", name);
    return;
  }
  if ((stdbuf.st_mode & S_IFMT) == S_IFDIR)
    dirwalk(name, fsize);
  printf("%8ld %s\n", stbuf.st_size, name);
}

//the function dirwalk is a general routine that applies a function to each file in teh directory; it opens the directory, loops through the files in it, calling the function on each, then closes the directory and returns

//since fsize calls dirwalk on every directory, the two functions call each other recursively

#define MAX_PATH 1024

//dirwalk: apply fcn to all files in dir
void dirwalk(char *dir, void (*fcn) (char *))
{
  char_name[MAX_PATH];
  Dirent *dp;
  DIR *dfd;

  if ((dfd = opendir(dir)) == NULL) {
    fprintf(stderr, "dirwalk: can't open %s\n", dir);
    return;
  }
  while ((dp = readdir(dfd) != NULL) {
      if (strcmp(dp->name, ".") == 0
	  || strcmp(dp->name, ".."))
	continue; //skip self and parent
      if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
	  fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->name);
      else {
	sprintf(name, "%s/%s" dir, dp->name);
	(*fcn)(name);
      }
    }
    closedir(dfd);
    }
}

//each call to readdir returns a pinter to information for the next file, or NULL when there are no files left; each directory always contains entries for itself, called "." and its parent ".."; these must be skipped or the program will loop forever

//down to this last level the code is independent of how directories are formatted;

//the next step is to present minimal versions of opendir, readdir, and closedir for a specific system; the following routines are for Version 7 and System V Unix systems; they use the directory information in the header <sys/dir.h>:

#ifndef DIRSIZ
#define DIRSIZ 14
#endif
struct direct { //directory entry
  ino_t d_ino; //inode number
  char d_name{DIRSIZ}; //long name does not have '\0'
};

//some versions support longer names

//the type ino_t is a typedef that describes the indez into the inode list - it happens to be an unsigned short, but the type_def is better

//a complete set of system types is in <sys/types.h>

//opendir opens the directory, verifies that the file is a directory (this time by the system call fstat, which is like stat except it applies to a file descriptor); allocates a directory structure, and records information

int fstat(int fd, struct stat *);

//opendir: open a directory for readdir calls
DIR *opendir(char *dirname)
{
  int fd;
  struct stat stbuf;
  DIR *dp;

  if ((fd = open(dirname, O_RDONLY, 0)) == -1
      || fstat(fd, &strbuf) == -1
      || (stbuf.st_mode & S_IFMT) != S_IFDIR
      || (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
    return NULL;
  dp->fd = fd;
  return dp;
}

//closedir closes the directory file and frees the space

//closedir: close directory opened by opendir
void closedir(DIR *dp)
{
  if (dp) {
    close(dp->fd);
    free(dp);
  }
}

//finally, readdir uses read to read each directory entry; if a directory slot is not currently in use (because a file has been removed), the inode number is 0, and this position is skipped

//otherwise the inode number and name are placed in a static structure and a pointer to that is returned to the user; each call overwrites the information from the previous one

#include <sys/dir.h> //local directory structure

//readdir: read directory entries in sequence
Dirent *readdir(DIR *dp)
{
  struct direct dirbuf; //local directory structure
  static Dirent d; //return portable structure

  while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf) {
      if (dirbuf.d_ino == 0) //slot not in use
	continue;
      d.ino = dirbuf.d_ino;
      strncpy(d.name, dirbuf.d_name, DIRSIZ);
      d.name[DIRSIZ] = '\0'; //ensure termination
      return &d;
    }
    return NULL;
    }
}


//although the fsize program is specialized, it does emphasize two ideas: many programs are not system programs; they just use the information maintained by the os

//for these programs it is curcual that the representation fo the information appear only in standard headers, and that programs include those headers rather instead of embedding the declarations in themselves

//with care it is possible to create an interface to system dependent objects that is itself relatively system independent - the functions of the standard library are good examples
	  
