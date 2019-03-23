#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *pDir;

  char *path;

  // Parse command line
  if (argc < 2) {
    path = "./";
  } else {
    path = argv[1];
  }

  // Open directory
  pDir = opendir (path);
  if (pDir == NULL) {
      printf ("Cannot open directory '%s'\n", path);
      return 1;
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL) {
    // struct dirent {
    //   ino_t          d_ino;       /* inode number */
    //   off_t          d_off;       /* offset to the next dirent */
    //   unsigned short d_reclen;    /* length of this record */
    //   unsigned char  d_type;      /* type of file; not supported
    //                                 by all file system types */
    //   char           d_name[256]; /* filename */
    // };

    if (pDirent->d_type == 4) {
      printf ("%12s   %s\n","DIR", pDirent->d_name);
    } else {
      struct stat buf;
      int pl = strlen(path);
      int fl = strlen(pDirent->d_name);
      char np[pl + fl];

      strcpy(np, path);
      if (strcmp( &path[pl-1], "/") != 0) {
        strcat(np, "/");
      }
      strcat(np, pDirent->d_name);

      stat(np, &buf);
      printf("%12lld   %s\n", buf.st_size, pDirent->d_name);
    }
  }

  // Close directory
  closedir (pDir);

  return 0;
}