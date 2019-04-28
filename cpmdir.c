#include <stdio.h>
#include <stdlib.h>

#include "directory.h"
//#include "disk.h"
#include "readFlag.h"
#include "readLogical.h"
#include "directoryList.h"

int main(int argc, char** argv) {
  int flag = readFlag(argc, argv); // 1=floppy 0=hard disk

  char* file = argv[2];
  char* dirEntry = argv[3];
  FILE* diskIn = fopen(file, "r"); // Opens Disk

  listPtr head = NULL;

  if (argc < 2) {
    printf("%s\n", "Use cpmdir -h for assistance");
  }
  else {
    directoryList(diskIn, flag, head);

    //if (argc == 3) {


    //}
  }




  while (head) {
    listPtr node = head;
    head = head->next;
    free(node);
  }
  free(head);
  fclose(diskIn);
}
