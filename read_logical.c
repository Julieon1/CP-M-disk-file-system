#include <stdio.h>
#include <stdlib.h>

#include "disk.h"
#include "directory.h"

/*
  allocation_num: how many blocks are we using?
*/

void read_logical (FILE* fp, int allocation_num, int allocation, dirPtr* buffer_ptr, char[] disk_type) {
    int num_physical = allocation / size[disk_type] / seclen;
    int sector = skew[disk_type][index];
        // when index hits 26, goes back to 1 but increment trancknum
    unsigned int offset = tracks[disk_type] * 26 * 128 + sector * 128;
}
