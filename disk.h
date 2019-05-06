#ifndef _DISK_H_
#define _DISK_H_

#define FLOPPY 0
#define HDISK 1

static char skew[2][26] = {
  {1,7,13,19,25,5,11,17,23,3,9,15,21,2,8,14,20,26,6,12,18,24,4,10,16,22},
  {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26}
};

static int seclen = 128;
static int tracks[2] = {78, 1024};
static int secttrk[2] = {26, 32};   // sector per track
static int blocksize[2] = {1024, 2048};
static int maxdir[2] = {64, 256};
// int skew[2] = {6,1};
static int boottrk[2] = {2, 0};

//static int disk_type[2] = {FLOPPY, HDISK};
int trackIndex;
int sectorIndex;

#endif
