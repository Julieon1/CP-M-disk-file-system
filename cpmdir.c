#include <stdio.h>
#include <stdlib.h>

#include "Directory.h"
#include "readFlag.h"
#include "readDisk.h"
#include "initializeDisk.h"

int main(int argc, char* argv[]) {
  diskPtr currentDisk = malloc(sizeof(struct Disk));
  int flag = readFlag(argc, argv); // 1=floppy 0=hard disk
  //unsigned char* allocationMap[(currentDisk->sectrk*currentDisk->tracks*currentDisk->secLength)/currentDisk->blockSize]; // Sector map of disk blocks
  initializeDisk(currentDisk, flag);
  readDisk(argc, argv, currentDisk);

  free(currentDisk);
}
