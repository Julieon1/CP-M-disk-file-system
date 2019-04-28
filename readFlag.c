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
        printf("%s\n", "Format: cpm flag fileName...");
        printf("%s\n", "-f for Floppy Disk");
        printf("%s\n", "-d for Hard Disk");
        exit(-1);
      default:
        printf("%s\n", USAGE);
        exit(-1);
    }
  }
  return flag;
}
