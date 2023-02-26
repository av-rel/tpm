#include "tpm.c"
#include "../deps/fs.c"
#include "tpm.h"
#include <stdio.h>

#define WIDTH 256
#define HEIGHT 256

uint pixels[WIDTH * HEIGHT];

int main(int argc, char** argv) {
    char* file = "bin/test.png";

    TPM_Canvas canvas = TPM_init_canvas(pixels, WIDTH, HEIGHT);
    TPM_fill(canvas.pixels, WIDTH, HEIGHT, 0xFFFFFFFF);

    int c;
    for (c = 0; c <= 100; c++) {
        TPM_fill_point(canvas.pixels, canvas.width, canvas.height, 100, c, 0xFF0000FF);
    }

    fs_save_as_png(canvas, file);

    return 0;
}
