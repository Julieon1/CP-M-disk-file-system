#include <stdio.h>
#include <stdlib.h>

#include "directory.h"
#include "readFlag.h"
#include "directoryList.h"

int main(int argc, char** argv) {
  int flag = readFlag(argc, argv); // 1=floppy 0=hard disk

  char* file = argv[2];
  char* dirEntry = argv[3];
  FILE* diskIn = fopen(file, "r"); // Opens Disk

  if (argc < 3) {
    printf("%s\n", "Use cpmdir -h for assistance");
  }
  else {
    if (argc == 3) {
      dirEntry = "ALL";
    }
    directoryList(diskIn, flag, dirEntry);
    //if (argc == 3) {

    //}
  }
  fclose(diskIn);
}
