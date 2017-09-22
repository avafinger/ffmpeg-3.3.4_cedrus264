/*
 * 
 *  Copyright (C) 2016 the contributors
 *
 *  Testing Cedrus mem allocation
 *
 *  Build: gcc test_cedrus.c -o test_cedrus -O3
 *
 *
*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/ioctl.h>

#include "ve.h"

#define CLEAR(x) memset (&(x), 0, szof (x))
#define ALIGN_4K(x) (((x) + (4095)) & ~(4095))
#define ALIGN_16B(x) (((x) + (15)) & ~(15))



int width = 1920;
int height = 1080;
int sz;

int main(int argc, char *argv[])
{
    int rc;
    struct ve_mem *data;

    rc = ve_open();
    if (!rc) {
        printf("cedrus not available\n");
        return -1;
    }
    sz = width * height * 3 / 2;
    // sz = 3133440;
    // ion = cedrus_get_ion_mem(cedrus);
    printf("size: %d\nwidth: %d\nheight: %d\n", sz, width, height);
    data = ve_malloc(sz);
    if (data) {
        ve_free(data);
    } else {
        printf("** Error allocating sz: %d\n", sz);
    }
    ve_close();
    return 0;
}
