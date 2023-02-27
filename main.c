#include "src/tpm.c"
#include "src/fs.c"

/* TODO: Usable as CLI */

#define WIDTH 512
#define HEIGHT 512

uint pixels[WIDTH * HEIGHT];

int main(void) {
    char* file = "bin/test.png";

    TPM_Canvas canvas = TPM_init_canvas(pixels, WIDTH, HEIGHT);
    TPM_fill(canvas.pixels, WIDTH, HEIGHT, 0xFFFFFFFF);

    TPM_draw_line(canvas.pixels, canvas.width, 0 , 0, canvas.width * 2, canvas.width * 2, 0xFF000000);

    TPM_save_as_png(canvas.pixels, canvas.width, canvas.height, file);

    return 0;
}

