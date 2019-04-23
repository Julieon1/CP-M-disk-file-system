#include <stdio.h>
#include <stdlib.h>

#include "directory.h"
#include "readFlag.h"
#include "initializeDisk.h"
#include "readDisk.h"

#define USAGE "Usage %s [-fd] filename(s)"

int main(int argc, char** argv[]) {
  char* file = argv[2];
  FILE* diskIn = fopen(file, "r"); // Opens Disk

  listPtr head = NULL;

  diskPtr currentDisk = malloc(sizeof(struct disk)); // Allocates space for disk information structure

  int flag = readFlag(argc, argv, USAGE); // 1=floppy 0=hard disk
  initializeDisk(currentDisk, flag); // Determines Disk Information using flag input

  short int allocationMap[currentDisk->blockNum]; // Sector map of disk blocks

  readDisk(diskIn, currentDisk, allocationMap, head); // Reads Disk and creates an allocation map

  while (head) { // Frees Nodes in directory linked list
    listPtr node = head;
    head = head->next;
    free(node);
  }


  free(currentDisk);
  fclose(diskIn);
}
