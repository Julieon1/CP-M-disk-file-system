#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "readFlag.h"

int readFlag(int argc, char* argv[]) {
  int flag, opt;

  while ((opt = getopt(argc, argv, "fd")) != -1) {
    switch (opt) {
      case 'f':
        flag = 1;
        break;
      case 'd':
        flag = 0;
        break;
      default:
        printf("Usage %s [-fd] filename(s) \n", argv[0]);
        exit(-1);
    }
  }
  return flag;
}
