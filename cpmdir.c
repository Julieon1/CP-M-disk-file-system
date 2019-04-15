#include <stdio.h>

#include "Directory.h"

int main(int argc, char** argv) {
  char* file1 = argv[1];
  FILE* diskIn;
  char floppy;
  char drive;
  int flag = 0;

  while ((opt = getopt(argc, argv, "fd")) != -1) {
    switch (opt) {
    case 'f':
      flag = 1;
      break;
    default:
      printf("Usage %s [-fd] filename(s) \n", argv[0]);
      exit(-1);
    }


  diskIn = fopen(file1, "rb"); // Open and read file

  int getopt(int argc, char* const argv[], const char *optstring);




  dirPtr entry = malloc(sizeof(struct dirPtr));

  while(fread(entry, sizeof(struct dirPtr), 1, diskIn)) {


  }


}
