#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directory.h"
#include "disk.h"
#include "directoryList.h"
#include "readDirectory.h"
#include "append.h"

void copyFromDisk(char file[], FILE* dp, int flag, listPtr head) {

  FILE *fp;
  if ((fp = fopen(file, "r+")) == NULL) {
    printf("Unable to open the file %s\n", argv[i]);
    return -1;
  }

/* convert filename and filetype to hex values */
  char *token = strtok(file, ".");
  char *fname = token;
  printf("%s\n", fname);

  token = strtok(NULL, ".");
  char *type = token;
  printf("%s\n", type);

  char filehex[100];
  for (int a=0, b=0; a<strlen(fname); ++a, b+=2){
    sprintf(filehex + b, "%02x", fname[a] & 0xff);
  }
  printf("'%s' in hex is %s.\n", fname, filehex);

  char typehex[100];
  for (int a=0, b=0; a<strlen(type); ++a, b+=2){
    sprintf(typehex + b, "%02x", type[a] & 0xff);
  }
  printf("'%s' in hex is %s.\n", type, typehex);

/* search in directory */
  searchDir();
  for (int i=0; i<16; i++){
    if (head->dir->diskmap[i] != 0xe5){
      //
    }
  }


  fclose(fp);
}
