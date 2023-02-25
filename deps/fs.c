#ifndef FS_C
#define FS_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/tpm.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./stb_image_write.h"

int tpm_save_to_ppm(Canvas canvas, char* path)
{
    int rtn = 0;
    FILE* fp;
    if ((fp = fopen(path, "wb")) == NULL) {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        rtn = 1;
        goto dispose;
    }

    fprintf(fp, "%s\n%d %d\n%d\n", PPM_FORMAT, canvas.width, canvas.height, 255);

    int c;
    for (c = 0; c < canvas.width * canvas.height; c++){
        uint pixel = canvas.pixels[c];
        uint bytes[3] = {
            (pixel >> (8 * 0))&0xFF,
            (pixel >> (8 * 1))&0xFF,
            (pixel >> (8 * 2))&0xFF
        };
        fwrite(bytes, sizeof(bytes), 1, fp);
        if (ferror(fp)) {
            rtn = 1;
            goto dispose;
        }
    }

dispose:
    fclose(fp);
    return rtn;
}

int tpm_save_png(Canvas canvas, char* path){
    int rtn = 0;
    if (!stbi_write_png(path, canvas.width, canvas.height, 4, canvas.pixels, sizeof(uint) * canvas.width)) {
        fprintf(stderr, "ERROR: unable to write %s\n", path);
        rtn = 1;
    }
    return rtn;
}

#endif
