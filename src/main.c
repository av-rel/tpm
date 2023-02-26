#include "tpm.c"
#include "tpm.h"
#include "../deps/fs.c"

#define WIDTH 960
#define HEIGHT 540

uint pixels[WIDTH * HEIGHT];

int main(int argc, char** argv) {
    char* file = "bin/test.png";

    TPM_Canvas canvas = tpm_canvas(pixels, WIDTH, HEIGHT);
    tpm_fill(canvas.pixels, canvas.width, canvas.height, 0xFFFFFFFF);
        
    return fs_save_to_png(canvas, file);
}
