#define FLOPPY 0
#define HDISK 1
static char[2][26] skew = {1,7,13,19,25,5,11,17,23,3,9,15,21,2,8,14,20,26,6,12,18,24,4,10,16,22}
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};

int seclen = 128;
int tracks[2] = {77, 255}
int secttrk[2] = {26, 128};   // sector per track
int blocksize[2] = {1024, 2048};
int maxdir[2] = {64, 1024};
int skew[2] = {6,1};
int boottrk[2] = {2, 0};

int disk_type[2] = {FLOPPY, HDISK};
int current_track = 0;
int current_index = 0;
