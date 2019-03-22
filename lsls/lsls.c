#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  int len;
  struct dirent *pDirent;
  DIR *pDir;

  // Parse command line
  if (argc < 2) {
      printf ("./lsls <dirname>\n");
      return 1;
  }

  // Open directory
  pDir = opendir (argv[1]);
  if (pDir == NULL) {
      printf ("Cannot open directory '%s'\n", argv[1]);
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
      printf ("<DIR> %s\n", pDirent->d_name);
    } else {

      printf ("[%u] %s\n", pDirent->d_type,pDirent->d_name);
    }
  }

  // Close directory
  closedir (pDir);

  return 0;
}