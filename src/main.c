#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>

#include "tpm.c"
#include "tpm.h"
#include "../deps/fs.c"

#define WIDTH 512
#define HEIGHT 512

uint pixels[WIDTH * HEIGHT];

int main(int argc, char** argv) {
    int rtn = 0;
    char* file = "res.png";

    Canvas canvas = tpm_canvas(pixels, WIDTH, HEIGHT);
    tpm_fill(&canvas, 0xFFFFFFFF);

    rtn = tpm_save_png(canvas, file);

dispose:
    return rtn;
}

