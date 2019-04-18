#include <stdio.h>
#include <stdlib.h>

#include "Directory.h"
#include "readDisk.h"

/*
  Iterates through disk for the directory

*/

void readDisk(int argc, char* argv[], diskPtr currentDisk) {
  FILE* diskIn;
  //char sectorSize[currentDisk->secLength];

  diskIn = fopen(argv[2], "rb"); // Open and read file
  //char* sector = malloc(sizeof(sectorSize));

  for (int t = (currentDisk->bootTrk+1) ; t < currentDisk->tracks ; t++) { // Current Track
    int secLoc = 0;
    for (int s = 0 ; s < currentDisk->sectrk ; s++) { // Current Sector Adjusting for Skew
      if (secLoc > currentDisk->sectrk) { // Loops back if current sector location is greater than the sectrk
        secLoc -= currentDisk->sectrk;
      }

      if (secLoc == 0) { // Makes the first sector in the track location to be 1
        secLoc = 1;
      }
      else if (secLoc == 1){ // Changes Loop to start at 2 if the sector location returns to 1
        secLoc = 2;
      }

      //fseek(diskIn, t*(secLoc*currentDisk->secLength), SEEK_SET);
      //fread(sector, sizeof(sectorSize), 1, diskIn);

      printf("%i", t);
      printf("%s", ": ");
      printf("%i\n", secLoc);
      //printf("%s\n", sector);
      secLoc += currentDisk->skew;
    }
  }
  fclose(diskIn);
  //free(sector);
}
