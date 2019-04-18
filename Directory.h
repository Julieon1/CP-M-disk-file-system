#ifndef _DIRECTORY_H
#define _DIRECTORY_H

typedef struct Disk *diskPtr;
typedef struct Directory *dirPtr;
typedef struct directoryList *listPtr;

struct Disk // Structure that stores disk data, initialized in initializeDisk.c
{
  int secLength;
  int tracks;
  int sectrk;
  int offset;
  int skew;
  int maxDir;
  int blockSize;
  int bootTrk;
};

struct Directory { // Structure that contains Directory Data
  unsigned char userNum; // 0 or E5 Status Byte. Read
  char fileName[8];
  char fileType[3];
  unsigned char fileExtent;
  unsigned char reserve1;
  unsigned char reserve2;
  unsigned char recordNum;
  char diskmap[16];
};

struct directoryList {
  dirPtr* directory;
  listPtr* next;
};

#endif
