#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disk.h"
#include "directory.h"
#include "removeDirectory.h"
#include "readDirectory.h"

/*
  Locates the specified file in the directory listPtr
  Marks specified directory with e5 in the directory listPtr
  Copies all directories in the directory list, into the disk

*/
void removeDirectory(FILE* diskIn, listPtr head, char* dirEntry, int flag) {
  listPtr current = head;
  printf("%s\n", "REMOVED");

  if (dirEntry[0] == '.') { // Removes all files of input extension fileType
    while (current) {
      int match = 1;
      if (current->dir->userNum != 0xe5) {
        for (int i = 0 ; i < strlen(dirEntry) ; i++) {
          if (dirEntry[i+1] != current->dir->fileType[i]) {
            match = 0;
          }
        }
        if (match == 1) {
          current->dir->userNum = 0xe5;
          readDirectory(current->dir);
        }
      }
      current = current->next;
    }
  }
  else { // Reads directory entry name, searches, and Removes the directory
    while (current) {
      int match = 1; // Does the file name and directory name match?
      int extCheck = 0; // Are we comparing the filename or the fileType?
      int loc = 0; // Current location index within the fileType
      if (current->dir->userNum != 0xe5) { // Checks for empty directory
        for (int i = 0 ; i < strlen(dirEntry) ; i++) { // Iterates through characters in the argument
          if (dirEntry[i] == '.') { // Checks for file extension
            extCheck = 1;
          }
          else if (extCheck == 0) { // Are we looking at the fileName or Extension? 0 = fileName, 1 = fileType
            if (dirEntry[i] != current->dir->fileName[i] && dirEntry[i] != '\n') { // Are the current chars equal? FileName
              match = 0;
            }
          }
          else {
            if (dirEntry[i] != current->dir->fileType[loc] && dirEntry[i] != '\n') {// Are the current chars equal? FileType
              match = 0;
              loc++; // Seperate iterator for fileType that starts after the '.'
            }
          }
        }
        if (match == 1) { // If every chracter matched up, remove the directory
          current->dir->userNum = 0xe5;
          readDirectory(current->dir);
        }
      }
      current = current->next;
    }
  }

/*
  Writes Updated directories to the disk usinfg the sector offset

*/
  int sectorOffset;
  trackIndex = boottrk[flag]; // determines current track

  if (flag == 1) {
    sectorIndex = 0;
  }
  else if (flag == 0) {
    sectorIndex = 3;
  }

  listPtr current2 = head;
  while (current2) {
    if (flag == 0) {
      sectorOffset = (trackIndex*secttrk[flag]*seclen)+(seclen*skew[flag][sectorIndex]); // determines current sector by number of bytes
    }
    else if (flag == 1) {
      sectorOffset = (trackIndex*secttrk[flag]*seclen)+(seclen*sectorIndex);
    }

    fseek(diskIn, sectorOffset, SEEK_SET);

    for (int m = 0 ; m < 4 ; m++) {
      fwrite(current2->dir, sizeof(struct directory), 1, diskIn);
      current2 = current2->next;
    }
  }

}
