#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directory.h"
#include "readFlag.h"
#include "directoryList.h"
#include "readDirectory.h"
#include "fileSearch.h"
#include "fileOutput.h"

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

    head = directoryList(diskIn, flag, head);

    if (argc == 3) { // If no directory file modifier is added, output all used directories
      listPtr current = head;
      while (current) {
        if (current->dir->userNum != 0xe5) {
          readDirectory(current->dir);
        }
        current = current->next;
      }
    }
    else {
      fileSearch(diskIn, head, dirEntry, flag); // Reads the Directory Entry Information
      fileOutput(diskIn, head, dirEntry, flag); // Reads the Blocks associated with the Directory of the file
    }
    while (head) {
      listPtr node = head;
      head = head->next;
      free(node);
    }
    fclose(diskIn);
  }
}
