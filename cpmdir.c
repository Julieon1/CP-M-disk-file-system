#include <stdio.h>
#include <stdlib.h>

#include "directory.h"
#include "readFlag.h"
#include "readDisk.h"
#include "initializeDisk.h"

int main(int argc, char* argv[]) {
  char* file1 = argv[2];
  FILE* diskIn;
  diskPtr currentDisk = malloc(sizeof(struct disk)); // Allocates space for disk information structure
  int flag = readFlag(argc, argv); // 1=floppy 0=hard disk
  initializeDisk(currentDisk, flag); // Determines Disk Information using flag input
  short int allocationMap[currentDisk->blockNum]; // Sector map of disk blocks

  diskIn = fopen(file1, "rb"); // Opens disk

  readDisk(diskIn, currentDisk, allocationMap); // Reads Disk and creates an allocation map




  fclose(diskIn);
  free(currentDisk);
}
