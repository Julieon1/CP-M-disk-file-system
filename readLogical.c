#include <stdio.h>
#include <stdlib.h>

#include "disk.h"
#include "directory.h"
#include "readLogical.h"
#include "readPhysical.h"

/*
  Reads a block using an allocation number
*/

void readLogical (FILE* diskIn, long alNum, bytePtr sector, int flag) {
  //int numSects = blocksize[flag] / seclen; // number of sectors in a block
  //int index = (alNum*blocksize[flag])/seclen; // first sector of allocation block  ex: blockLoc 3*1024 / 128

  int trackOffset = (alNum*blocksize[flag])/(seclen*secttrk[flag]); // determines current track
  int lockDiff = (alNum*blocksize[flag])-(trackOffset*secttrk[flag]*seclen); // determines byte difference between block start and track start
  int sectorIndex = lockDiff / seclen; // Determines index of sector within a track

  for (int i = 0 ; i < (blocksize[flag]/seclen) ; i++) {
    int sectorOffset = (trackOffset*secttrk[flag]*seclen)+(seclen*skew[flag][sectorIndex]); // determines current sector by number of bytes
    /*
    printf("%i", trackOffset);
    printf("%s", ": ");
    printf("%i", sectorOffset);
    printf("%s", ": ");
    printf("%i\n", skew[flag][sectorIndex]);
    */
    readPhysical(diskIn, sectorOffset, sector, flag); // reads a single sector
    sectorIndex++;

    if (flag == 0) {
      if (sectorIndex > 26)  {
        sectorIndex = 1;
      }
    }
  }

}
