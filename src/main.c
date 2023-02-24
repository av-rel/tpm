#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>

#include "./tpm.h"
#include "./tpm.c"

#define W 100
#define H 200

int main(int argc, char** argv){
    int rtn = 0;
    const char* file = "bin/o.ppm";

    Image image = tpm_init_image(W, H);

    FILE* fp;
    if ((fp = fopen(file, "wb")) == NULL) {
        fprintf(stderr, "%s [ERROR]: Couldn't write to %s\n", APP_NAME, file);
        rtn = 1;
        goto dispose;
    }

    int x, y;
    for (y = 0; y < H; y++) {
        for (x = 0; x < W; x++) {
            tpm_set_pixel(&image, x, y, 0, 0, 0);
        }
    }

    fprintf(fp, "P3\n%d %d\n255\n", W, H);
    fwrite(image.data, sizeof(PIXEL), W * H, fp);

dispose:
    fclose(fp);
    tpm_dispose(&image);

    return 0;
}
