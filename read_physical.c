#include <stdio.h>
#include <stdlib.h>

#include "disk.h"
#include "directory.h"

/*
  Iterates through disk for the directory
*/

void read_physical(FILE* fp, int offset, dirPtr* buffer_ptr ) {

  fseek(fp, offset, SEEK_SET);
  fread(buffer_ptr, sizeof(seclen), 1, fp);
}
