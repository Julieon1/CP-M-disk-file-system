#include <stdio.h>
#include <stdlib.h>

#include "directory.h"
#include "readPhysical.h"


void readPhysical(FILE* diskIn, int offset, bytePtr sector, int flag, bytePtr block ) {
  fseek(diskIn, offset, SEEK_SET);
  fread(sector, sizeof(sector), 1, diskIn);
}
