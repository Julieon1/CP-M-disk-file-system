#include <stdio.h>
#include <stdlib.h>

#include "readDisk.h"
#include "Directory.h"
#include "initializeDisk.h"

void readDisk(int argc, char* argv[], int flag) {
  FILE* diskIn;
  diskPtr currentDisk = malloc(sizeof(struct Disk));
  //char* sector = char[128];

  initializeDisk(currentDisk, flag); // Determines Data sizes from flag

  diskIn = fopen(argv[2], "rb"); // Open and read file

  fseek(diskIn, sizeof(char[2048]), SEEK_SET);



  //sector = malloc(sizeof(sector));

  free(currentDisk);
}
