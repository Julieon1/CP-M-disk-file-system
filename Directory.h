#ifndef _DIRECTORY_H
#define _DIRECTORY_H

typedef struct Disk *diskPtr;
typedef struct Directory *dirPtr;

struct Disk
{
  int secLength;
  int tracks;
  int sectrk;
  int offset;
  int skew;
  int maxDir;
  int blockSize;
};

struct Directory {
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
