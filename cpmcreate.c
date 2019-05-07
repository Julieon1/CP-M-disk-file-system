#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disk.h"
#include "directory.h"
#include "readFlag.h"

int main(int argc, char** argv) {
  FILE *outfile;
  int flag = readFlag(argc, argv); // 1 = floppy , 0 = hard disk
  bytePtr byte = (bytePtr)malloc(1);

	outfile = fopen(argv[2], "wb+");

  byte = strtol("11100010", NULL, 2);

  for (int i=0; i < (seclen * tracks[flag] * secttrk[flag]); i++ ){
    fwrite(&byte, 1, 1, outfile);
  }
  fclose(outfile);
}
