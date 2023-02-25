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
    char* file = "examples/line.png";

    //init canvas
    Canvas canvas = tpm_canvas(pixels, WIDTH, HEIGHT);
    //fill canvas with white color
    tpm_fill_canvas(&canvas, 0xFFFFFFFF); //AABBGGRR
    //draw line
    tpm_draw_line(&canvas, 0, 0, canvas.height, canvas.height, 0xFF000000);

    save_to_png(canvas, file);

    return 0;
}

