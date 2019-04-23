#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "readFlag.h"

int readFlag(int argc, char argv[], char usage[]) {
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
        printf("%s\n", usage);
        exit(-1);
    }
  }
  return flag;
}
