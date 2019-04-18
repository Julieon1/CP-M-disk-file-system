#include <stdio.h>
#include <stdlib.h>

#include "directory.h"
#include "initializeDisk.h"

void initializeDisk(diskPtr currentDisk, int flag) {

  if (flag == 1) {  // 8 inch floppy
    currentDisk->secLength = 128;
    currentDisk->tracks = 77;
    currentDisk->sectrk = 26;
    currentDisk->offset = 2;  // boot tracks
    currentDisk->skew = 6;
    currentDisk->maxDir = 64;
    currentDisk->blockSize = 1024;
  }
  
  else if (flag == 0) {   // 4 Meg hard drive
    currentDisk->secLength = 128;
    currentDisk->tracks = 255;
    currentDisk->sectrk = 128;
    currentDisk->offset = 0;
    currentDisk->skew = 1;
    currentDisk->maxDir = 1024;
    currentDisk->blockSize = 2048;
  }
}
