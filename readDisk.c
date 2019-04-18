#include <stdio.h>
#include <stdlib.h>

#include "directory.h"
#include "readDisk.h"

/*
  Iterates through disk for the directory

*/

void readDisk(FILE* diskIn, diskPtr currentDisk, short int* allocationMap) {
  int allocationTracker = 0;
  int currentSector = 0;
  unsigned char sectorSize[currentDisk->secLength];
  unsigned char* sector = malloc(sizeof(sectorSize));

  for (int t = 1 ; t < currentDisk->tracks ; t++) { // Current Track
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

      fseek(diskIn, t*(secLoc*currentDisk->secLength), SEEK_SET); // Seeks record at specific track and sector
      fread(sector, sizeof(sectorSize), 1, diskIn); // Reads sought sector into sector

      /*
      Determined by the first byte of the first sector.
      Should block usage be determined by directory entries?
      */

      if (currentSector % 4 == 0) { // Determines current Block and marks locations in AllocationMap
        if (t < currentDisk->bootTrk) { // If the current block is within the boot track range, mark as used
          allocationMap[allocationTracker] = 1;
        }
        else if (sector[0] == 0xe5) { // Determines if the block is empty by looking at the first byte in the first sector of the block
          allocationMap[allocationTracker] = 0;
        }
        else { // 1 is used, 0 is not
          allocationMap[allocationTracker] = 1;
        }
        //printf("%i\n", allocationMap[allocationTracker]);
        allocationTracker++;
        //printf("%i\n", allocationTracker);
      }
      currentSector++;

      //printf("%i", t);
      //printf("%s", ": ");
      //printf("%i\n", secLoc);
      printf("%x\n", sector[0]);
      secLoc += currentDisk->skew;
    }
  }
  free(sector);
}
