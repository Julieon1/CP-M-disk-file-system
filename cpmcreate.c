#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disk.h"
#include "directory.h"
#include "readFlag.h"

int main(int argc, char** argv) {


  int flag = readFlag(argc, argv); // 1 = floppy , 0 = hard disk
  bytePtr byte = malloc(1);
  byte = 0xe5;
  FILE *outfile;
	outfile = fopen(argv[2], "r+");

    for (i=0; i < (seclen * tracks[flag] * sectrk[flag]); i++ ){
      fwrite(byte, sizeof(byte), 1, outfile);
    }


  fclose(outfile);
}
