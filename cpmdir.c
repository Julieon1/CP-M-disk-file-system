#include <stdio.h>
#include <stdlib.h>

#include "directory.h"
#include "readFlag.h"
#include "directoryList.h"
#include "readDirectory.h"


int main(int argc, char** argv) {
  int flag = readFlag(argc, argv); // 1=floppy 0=hard disk

  char* file = argv[2];
  char* dirEntry = argv[3];
  FILE* diskIn = fopen(file, "r"); // Opens Disk

  listPtr head = NULL;

  if (argc < 3) {
    printf("%s\n", "Use cpmdir -h for assistance");
  }
  else if (diskIn == NULL) {
    printf("%s\n", "No Such Disk Found");
  }
  else {
    if (argc == 3) {
      dirEntry = "ALL";
    }

    head = directoryList(diskIn, flag, head);

    listPtr current = head;
    while (current) {
      readDirectory(current->dir);
      current = current->next;
    }


    while (head) {
      listPtr node = head;
      head = head->next;
      free(node);
    }
    fclose(diskIn);
  }
}
