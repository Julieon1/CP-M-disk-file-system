#include <stdio.h>
#include <stdlib.h>

// #include "disk.h"
// #include "directory.h"
#include "read_physical.h"

void read_physical(FILE *fp, int offset, dirPtr buffer_ptr ) {

  fseek(fp, offset, SEEK_SET);
  fread(buffer_ptr, sizeof(seclen), 1, fp);
}
