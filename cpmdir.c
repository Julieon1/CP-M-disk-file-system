#include <stdio.h>

#include "readFlag.h"
#include "readDisk.h"

int main(int argc, char* argv[]) {
  int flag = readFlag(argc, argv); // 1=floppy 0=hard disk

  readDisk(argc, argv, flag);

}
