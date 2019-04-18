#include <stdio.h>

#include "initializeDisk.h"
#include "directory.h"

/*  command line:
      cpmcopy -f/h fromDisk toDisk fileName1 fileName2 ...
*/

int main(int argc, char** argv) {

  if (argc<5){
    printf("Usage: ./cpmcopy -f/h fromDisk toDisk fileName1 fileName2 ...\n");
    return -1;
  }

  struct directory d;

  // search a file/files in fromDisk

  // get content

  // check space in toDisk

  // create a new file in toDisk and copy the content


}
