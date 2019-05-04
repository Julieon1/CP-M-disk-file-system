#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disk.h"
#include "directory.h"
#include "readLogical.h"
#include "readPhysical.h"

/*
  Reads a block using an allocation number
  The Allocation Number corresponds to an index of blocks
*/

void readLogical (FILE* diskIn, long alNum, int flag, bytePtr block) {
  int sectorOffset;
  bytePtr sector = (bytePtr)malloc(sizeof(seclen));

  trackIndex = ((alNum*blocksize[flag])/(seclen*secttrk[flag]))+boottrk[flag]; // determines current track
  int lockDiff = ((alNum*blocksize[flag])+(boottrk[flag]*secttrk[flag]*seclen))-(trackIndex*secttrk[flag]*seclen); // determines byte difference between block start and track start
  sectorIndex = lockDiff / seclen; // Determines index of sector within a track

  for (int i = 0 ; i < (blocksize[flag]/seclen) ; i++) {
    if (flag == 0) {
      sectorOffset = (trackIndex*secttrk[flag]*seclen)+(seclen*skew[flag][sectorIndex]); // determines current sector by number of bytes
    }
    else if (flag == 1) {
      sectorOffset = (trackIndex*secttrk[flag]*seclen)+(seclen*sectorIndex);
    }
/*
    printf("%i", trackIndex);
    printf("%s", ": ");
    printf("%i", sectorOffset);
    printf("%s", ": ");
    printf("%i\n", skew[flag][sectorIndex]);
*/
    fseek(diskIn, sectorOffset, SEEK_SET);
    fread(sector, sizeof(sector), 1, diskIn);

    strcat(block, sector);
    sectorIndex++;

    if (flag == 0) {
      if (sectorIndex > 26)  {
        sectorIndex = 0;
        trackIndex++;
        /*
        printf("%s\n", "");
        printf("%s", "New Track");
        printf("%s\n", "");
        */
      }
    }
  }

}
