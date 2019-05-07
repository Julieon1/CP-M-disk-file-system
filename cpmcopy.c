#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "directory.h"
#include "disk.h"
#include "directoryList.h"

#define USAGE "Usage: ./cpmcopy [-fd] [-io] diskname filename(s)"

// copy file(s) from/to floppy/hard disk.

int main(int argc, char *argv[]) {
  int diskTypeFlag, inoutFlag;  // inoutFlag: 0=in (local to disk), 1=out (disk to local)
  int opt;

  while ((opt = getopt(argc, argv, "fdio")) != -1) {
    switch (opt) {
      case 'f':
        diskTypeFlag = FLOPPY;
        break;
      case 'd':
        diskTypeFlag = HDISK;
        break;
      case 'i':
        inoutFlag = 0;
        break;
      case 'o':
        inoutFlag = 1;
        break;
      default:
        printf("%s\n", USAGE);
        exit(-1);
    }
  }

  FILE* dp;
  if ((dp = fopen(argv[3], "r+")) == NULL) {
		printf("Unable to open the disk %s\n", argv[3]);
		return -1;
	}

  listPtr head = directoryList(dp,diskTypeFlag);

  for (int i=4; i<argc; i++){
    if (inoutFlag==0){
      copyFromDisk(argv[i], dp, diskTypeFlag);
    }
    else{
      //
    }


  }
  // struct directory d;

  // search a file/files in fromDisk

  // get content

  // check space in toDisk

  // create a new file in toDisk and copy the content

  // fclose(fp);
  fclose(dp);

}
