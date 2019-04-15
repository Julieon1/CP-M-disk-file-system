#include <stdio.h>

#include "readFlag.h"

int main(int argc, char* argv[]) {
  //char* file1 = argv[1];
  //FILE* diskIn;
  //char floppy;
  //char drive;
  int flag = readFlag(argc, argv);

  printf("%i\n", flag);
  /*
  diskIn = fopen(file1, "rb"); // Open and read file

  int getopt(int argc, char* const argv[], const char *optstring);




  dirPtr entry = malloc(sizeof(struct dirPtr));

  while(fread(entry, sizeof(struct dirPtr), 1, diskIn)) {


  }

  */
}
