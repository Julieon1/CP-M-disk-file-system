#include <stdio.h>

/*  command line:
      cpmcreate ____.disk
*/

int main(int argc, char** argv) {

  FILE *outfile;
	outfile = fopen(argv[1], "wb");
  

  fclose(outfile);
}
