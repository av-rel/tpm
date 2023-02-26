#include "tpm.c"
#include "../deps/fs.c"
#include "tpm.h"
#include <stdio.h>

#define WIDTH 960
#define HEIGHT 534

uint pixels[WIDTH * HEIGHT];

int main(int argc, char** argv) {
    char* file = "bin/test.png";

    TPM_Canvas canvas = tpm_canvas(pixels, WIDTH, HEIGHT);
    tpm_fill(canvas.pixels, WIDTH, HEIGHT, 0xFFFFFFFF);

    tpm_fill_triangle(canvas.pixels, WIDTH, HEIGHT, 0, 0, 100, 100, 500, 500, 0xFF000000);

    fs_save_as_png(canvas, file);

    return 0;
}
