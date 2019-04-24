# include "disk.h"
# include "directory.h"
# include "writeBlock.h"

int readBlock(FILE* fp, unsigned char *bufferPtr, unsigned int offset, int disk_type){

  fseek(bufferPtr, offset, SEEK_SET);
  fwrite(bufferPtr, sizeof(seclen), 1, fp);

  return 0;
}
