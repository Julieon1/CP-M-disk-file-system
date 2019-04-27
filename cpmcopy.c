#include <stdio.h>

#include "initializeDisk.h"
#include "directory.h"

#define USAGE "Usage: ./cpmcopy [-fd] [-io] diskname filename(s)"

int main(int argc, char** argv[]) {
  int diskTypeFlag, inoutFlag;  // diskTypeFlag: 0=floppy, 1=hard disk
                                // inoutFlag: 0=in (local to disk), 1=out (disk to local)

  while ((opt = getopt(argc, argv, "fdio")) != -1) {
    switch (opt) {
      case 'f':
        diskTypeFlag = 0;
        break;
      case 'd':
        diskTypeFlag = 1;
        break;
      case 'i':
        inoutFlag = 0;
      case 'o':
        inoutFlag = 1;
      default:
        printf("%s\n", usage);
        exit(-1);
    }
  }

  FILE* diskIn, diskOut;
  if ((diskIn = fopen(argv[2], "r")) == NULL) {
		printf("Unable to open the disk %s\n", argv[2]);
		return -1;
	}
  if ((diskOut = fopen(argv[3], "r+")) == NULL) {
		printf("Unable to open the disk %s\n", argv[3]);
		return -1;
  }

  FILE *fp;


  struct directory d;

  // search a file/files in fromDisk

  // get content

  // check space in toDisk

  // create a new file in toDisk and copy the content


}
