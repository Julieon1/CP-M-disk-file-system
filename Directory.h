#ifndef _DIRECTORY_H
#define _DIRECTORY_H

typedef struct Directory *dirPtr;

struct Directory {
  /*
  unsigned int userNum: 8;
  char fileName[8]; //
  char fileType[3];
  unsigned int fileExtent: 8;
  unsigned int reserve1: 8;
  unsigned int reserve2: 8;
  unsigned int recordNum: 8;
  char diskMap[16];
  */

  char userNum;
  char fileName[8];
  char fileType[3]
  char fileExtent;
  char reserve1;
  char reserve2;
  char recordNum;
  char diskmap[16];
}

#endif
