#ifndef _DIRECTORY_H
#define _DIRECTORY_H

typedef struct disk *diskPtr;
typedef struct directory *dirPtr;

struct disk
{
  int secLength;
  int tracks;
  int sectrk;
  int offset;
  int skew;
  int maxDir;
  int blockSize;
};

struct directory {
  char userNum;
  char fileName[8];
  char fileType[3];
  char fileExtent;
  char reserve1;
  char reserve2;
  char recordNum;
  char diskmap[16];
};

#endif
