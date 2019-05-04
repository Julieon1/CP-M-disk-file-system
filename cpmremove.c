#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directory.h"
#include "readFlag.h"
#include "directoryList.h"
#include "removeDirectory.h"


int main(int argc, char** argv) {
  int flag = readFlag(argc, argv); // 1=floppy 0=hard disk

  char* file = argv[2];
  char* dirEntry = argv[3];
  FILE* diskIn = fopen(file, "r+"); // Opens Disk

  listPtr head = NULL;

  if (argc < 4) {
    printf("%s\n", "Use cpmremove -h for assistance");
  }
  else if (diskIn == NULL) {
    printf("%s\n", "No Such Disk Found");
  }
  else {

    head = directoryList(diskIn, flag, head);
    removeDirectory(diskIn, head, dirEntry, flag);

    while (head) {
      listPtr node = head;
      head = head->next;
      free(node);
    }
    fclose(diskIn);
  }
}
