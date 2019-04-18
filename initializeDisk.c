#include <stdio.h>
#include <stdlib.h>

#include "Directory.h"
#include "initializeDisk.h"

/*
This function Initializes the disk information using the provided flag created by readFlag.c
If f == 1, then the disk is a floppy
If f == 0, then the disk is a hard disk
Allows us to keep all disk information in a single location, so that we aren't repeatedly creating
  and calling variables for the disk
*/


void initializeDisk(diskPtr currentDisk, int flag) {

  if (flag == 1) {
    currentDisk->secLength = 128;
    currentDisk->tracks = 77;
    currentDisk->sectrk = 26;
    currentDisk->offset = 2;
    currentDisk->skew = 6;
    currentDisk->maxDir = 64;
    currentDisk->blockSize = 1024;
    currentDisk->bootTrk = 2;
  }
  else if (flag == 0) {
    currentDisk->secLength = 128;
    currentDisk->tracks = 255;
    currentDisk->sectrk = 128;
    currentDisk->offset = 0;
    currentDisk->skew = 1;
    currentDisk->maxDir = 1024;
    currentDisk->blockSize = 2048;
    currentDisk->bootTrk = 0;
  }
}
