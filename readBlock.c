# include "disk.h"
# include "directory.h"
# include "readBlock.h"

int readBlock(FILE* fp, unsigned char *bufferPtr, unsigned int offset, int disk_type){

  fseek(bufferPtr, offset, SEEK_SET);
  fread(bufferPtr, sizeof(seclen), 1, fp);

  return 0;
}
