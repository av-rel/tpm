#ifndef FS_C
#define FS_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/tpm.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./stb_image_write.h"


int fs_save_to_png(Canvas canvas, char* path)
{
    int rtn = 0;
    if (!stbi_write_png(path, canvas.width, canvas.height, 4, canvas.pixels, sizeof(uint) * canvas.width)) {
        fprintf(stderr, "ERROR: unable to write %s\n%s", path, strerror(errno));
        rtn = 1;
    }
    return rtn;
}

int fs_save_to_jpg(Canvas canvas, char* path)
{
    int rtn = 0;
    if (!stbi_write_jpg(path, canvas.width, canvas.height, 4, canvas.pixels, sizeof(uint) * canvas.width)) {
        fprintf(stderr, "ERROR: unable to write %s\n%s", path, strerror(errno));
        rtn = 1;
    }
    return rtn;
}

#endif
