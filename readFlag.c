#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "readFlag.h"

#define USAGE "Usage %s [-fdh] filename(s)"

int readFlag(int argc, char* argv[]) {
  int flag, opt;

  while ((opt = getopt(argc, argv, "fdh")) != -1) {
    switch (opt) {
      case 'f':
        flag = 0;
        break;
      case 'd':
        flag = 1;
        break;
      case 'h':
        printf("%s\n", "Format: cpm flag diskName...");
        printf("%s\n", "-f for Floppy Disk");
        printf("%s\n", "-d for Hard Disk");
        printf("%s\n", "The diskName should include its extension");
        printf("%s\n", "Ending at disk name will output all used directories when using cpmdir");
        printf("%s\n", "Adding a file extension (i.e: '.txt') after the diskName will modify all directories with that fileType when using cpmremove and cpmdir");
        printf("%s\n", "Adding an entire file name after the diskName will modify that specific directory when when using cpmremove and cpmdir");
        exit(-1);
      default:
        printf("%s\n", USAGE);
        exit(-1);
    }
  }
  return flag;
}
