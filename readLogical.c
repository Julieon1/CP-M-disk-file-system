#include <stdio.h>
#include <stdlib.h>

#include "disk.h"
#include "directory.h"
#include "readLogical.h"
#include "readPhysical.h"

/*
  Reads a block using an allocation number
  The Allocation Number corresponds to an index of blocks
*/

void readLogical (FILE* diskIn, long alNum, int flag) {
  //int numSects = blocksize[flag] / seclen; // number of sectors in a block
  //int index = (alNum*blocksize[flag])/seclen; // first sector of allocation block  ex: blockLoc 3*1024 / 128
  
  bytePtr sector = (bytePtr)malloc(sizeof(seclen));
  trackIndex = (alNum*blocksize[flag])/(seclen*secttrk[flag]); // determines current track
  int lockDiff = (alNum*blocksize[flag])-(trackIndex*secttrk[flag]*seclen); // determines byte difference between block start and track start
  sectorIndex = lockDiff / seclen; // Determines index of sector within a track

  for (int i = 0 ; i < (blocksize[flag]/seclen) ; i++) {
    int sectorOffset = (trackIndex*secttrk[flag]*seclen)+(seclen*skew[flag][sectorIndex]); // determines current sector by number of bytes
/* Test Prints
    printf("%i", trackIndex);
    printf("%s", ": ");
    printf("%i", sectorOffset);
    printf("%s", ": ");
    printf("%i\n", skew[flag][sectorIndex]);
*/
    readPhysical(diskIn, sectorOffset, sector, flag); // reads a single sector
    sectorIndex++;

    if (flag == 0) {
      if (sectorIndex > 26)  {
        sectorIndex = 0;
        trackIndex++;
        printf("%s\n", "");
        printf("%s", "New Track");
        printf("%s\n", "");
      }
    }
  }

}
