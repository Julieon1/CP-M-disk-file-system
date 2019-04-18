#include <stdio.h>
#include <stdlib.h>

#include "directory.h"
#include "readDir.h"

int readDir(dirPtr dp) {

	dData = (dirPtr)malloc(sizeof(struct directory));
	while(fread(dData, sizeof(struct directory),1,fin)) {
		printf("\n");
		// fwrite(dData, sizeof(struct directory),1,fout);
		// fwrite(pData, sizeof(struct paydata), 1, fout);
	}
}
