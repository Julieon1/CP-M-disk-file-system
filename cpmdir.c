#include <stdio.h>
#include <stdlib.h>

#include "directory.h"
//#include "disk.h"
#include "readFlag.h"
#include "readLogical.h"

int main(int argc, char** argv) {
  char* file = argv[2];
  unsigned char seclen[128];
  char *ptr;
  int blockNum[2] = {250, 2040};

  FILE* diskIn = fopen(file, "r"); // Opens Disk

  int flag = readFlag(argc, argv); // 1=floppy 0=hard disk
  bytePtr sector = (bytePtr)malloc(sizeof(seclen));

  if (argc < 4) {
    for (int i = 0 ; i < blockNum[flag] ; i++) {
      readLogical(diskIn, i, sector, flag);
    }
  }
  else {
    long allocationNum = strtol(argv[3], &ptr , 10);

    readLogical(diskIn, allocationNum, sector, flag);
  }

  //short int allocationMap[currentDisk->blockNum]; // Sector map of disk blocks

  //readDisk(diskIn, currentDisk, allocationMap, head); // Reads Disk and creates an allocation map
/*
  while (head) { // Frees Nodes in directory linked list
    listPtr node = head;
    head = head->next;
    free(node);
  }


  free(currentDisk);*/

  free(sector);
  fclose(diskIn);
}
