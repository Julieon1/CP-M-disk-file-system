#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disk.h"
#include "directory.h"
#include "fileOutput.h"
#include "readDirectory.h"
#include "readLogical.h"

/*

*/
void fileOutput(FILE* diskIn, listPtr head, char* dirEntry, int flag) {
  //int currentEntry = currentNum;

  bytePtr block = malloc(blocksize[flag]);

  listPtr current = head;
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
      if (match == 1) { // If every chracter matched up, read the directory
        readDirectory(current->dir);
        for (int m = 0 ; m < 16 ; m++) {
          char alC = current->dir->diskmap[m];
          int alNum = alC - '0';
          readLogical(diskIn, alNum, flag, block);
          for (int n = 0 ; n < 1024 ; n++) {
            printf("%X", block[n]);
            if ((n+1)%128 == 0) {
              printf("%s\n", "");
            }
          }
          printf("%s\n", "");
        }
        printf("%s\n", "");
      }
    }
    current = current->next;
  }
}
