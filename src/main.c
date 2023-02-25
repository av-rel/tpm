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
    char* file = "examples/white.png";

    Canvas canvas = tpm_canvas(pixels, WIDTH, HEIGHT);
    tpm_fill(&canvas, 0xFFFFFFFF); //AABBGGRR

    save_to_png(canvas, file);

    return 0;
}

