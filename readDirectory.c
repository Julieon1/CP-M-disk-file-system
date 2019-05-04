#include <stdio.h>
#include <string.h>

#include "directory.h"
#include "readDirectory.h"

void readDirectory(dirPtr directory) {
  int len;
  printf("%-4X", directory->userNum);
  printf("%s", ": ");
  len = strlen(directory->fileName);
  if (directory->fileName[len-1] == '\n' ) {
      directory->fileName[len-1] = 0;
    }
  printf("%31s", directory->fileName);
  printf("%s", ".");
  len = strlen(directory->fileType);
  if (directory->fileType[len-1] == '\n' ) {
      directory->fileType[len-1] = 0;
    }
  printf("%-25s", directory->fileType);
  printf("%-5i", directory->fileExtent);
  printf("%-5i", directory->recordNum);
  printf("%s\n", directory->diskmap);
  printf("%s\n", "");
}
