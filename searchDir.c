#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directory.h"
#include "disk.h"
#include "directoryList.h"
#include "readDirectory.h"
#include "append.h"

/*  if the data looking for is found, return 0 and listPtr is pointing to the node.
    if not found, returns -1.
*/

int searchDir(listPtr head, char fname[], char ftype[]){

  listPtr current = head;
  dirPtr d;
  boolean found = false;
  while (current->next != NULL){
    d = current->dir;
    if (d->fileName == fname && d->fileType == ftype[]){
      found = true;
      break;
    }
  }
  if (!found){
    printf("'%s' was not found on the disk.\n", fname);
    return -1;
  }
  printf("'%s' was  found on the disk.\n", fname);
  head = current;
  return 0;
}
