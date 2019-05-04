#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    else{
      if (dirEntry[0] == '.') { // Output all files of input extension fileType
        listPtr current = head;
        while (current) {
          int match = 1;
          if (current->dir->userNum != 0xe5) {
            for (int i = 0 ; i < strlen(dirEntry) ; i++) {
              if (dirEntry[i+1] != current->dir->fileType[i]) {
                match = 0;
              }
            }
            if (match == 1) {
              readDirectory(current->dir);
            }
          }
          current = current->next;
        }
      }
      else { // Reads directory entry name, searches, and outputs the directory
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
            }
          }
          current = current->next;
        }
      }
    }

    while (head) {
      listPtr node = head;
      head = head->next;
      free(node);
    }
    fclose(diskIn);
  }
}
