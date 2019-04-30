#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directory.h"
#include "disk.h"
#include "directoryList.h"

listPtr directoryList(FILE* diskIn, int flag, listPtr head) {
  int sectorOffset;
  dirPtr dir = (dirPtr)malloc(sizeof(struct directory));

  trackIndex = boottrk[flag];

  if (flag == 1) {
    sectorIndex = 0;
  }
  else if (flag == 0) {
    sectorIndex = 3;
  }

  for (int i = 0 ; i < maxdir[flag]/(seclen/32) ; i++) {
    if (flag == 0) {
      sectorOffset = (trackIndex*secttrk[flag]*seclen)+(seclen*skew[flag][sectorIndex]); // determines current sector by number of bytes
    }
    else if (flag == 1) {
      sectorOffset = (trackIndex*secttrk[flag]*seclen)+(seclen*sectorIndex);
    }

    fseek(diskIn, sectorOffset, SEEK_SET);
    //printf("%i\n", sectorOffset);
    for (int i = 0 ; i < 4 ; i++) {
      listPtr node = (listPtr)malloc(sizeof(node));
      fread(dir, 32, 1, diskIn);
      node->directory = dir;
      node->next = head;
      head = node;
    }
    sectorIndex++;

    if (flag == 0) {
      if (sectorIndex > 26)  {
        sectorIndex = 0;
        trackIndex++;
      }
    }
  }
  free(dir);
  return head;
}
