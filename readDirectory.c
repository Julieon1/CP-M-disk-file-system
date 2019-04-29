#include <stdio.h>

#include "directory.h"
#include "readDirectory.h"

void readDirectory(dirPtr directory) {
  printf("%X", directory->userNum);
  printf("%s", ": ");
  printf("%s", directory->fileName);
  printf("%s", ".");
  printf("%s", directory->fileType);
  printf("%s", " --- ");
  printf("%i", directory->fileExtent);
  printf("%s", " --- ");
  printf("%i\n", directory->recordNum);
  printf("%s\n", directory->diskmap);
}
