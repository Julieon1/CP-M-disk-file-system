#ifndef _DIRECTORY_H
#define _DIRECTORY_H

typedef struct directoryList *listPtr;
typedef struct directory *dirPtr;

struct directory {
  unsigned char userNum; // 0 or E5 Status Byte. Read
  char fileName[8]; // 7?
  char fileType[3];
  unsigned char fileExtent;
  unsigned char reserve[1];
  unsigned char recordNum;
  char diskmap[16];
};

struct directoryList {
  dirPtr directory;
  listPtr next;
};

#endif
