#ifndef _DIRECTORY_H
#define _DIRECTORY_H

typedef struct directoryList *listPtr;
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
  int bootTrk;
  int blockNum;
};

struct directory {
  unsigned char userNum; // 0 or E5 Status Byte. Read
  char fileName[7];
  char fileType[2];
  unsigned char fileExtent;
  unsigned char reserve[1];
  unsigned char recordNum;
  char diskmap[15];
};

struct directoryList {
  dirPtr directory;
  listPtr next;
};

#endif
