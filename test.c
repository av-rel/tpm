#include "src/def.c"
#include "src/tpm.c"
#include "src/fs.c"

/* TODO: Usable as CLI */

#define WIDTH 512
#define HEIGHT 512

uint pixels[WIDTH * HEIGHT];

int main() {
    char* file = "bin/test.png";
    
    TPM_Canvas canvas = TPM_init_canvas(pixels, WIDTH, HEIGHT);
    TPM_fill(canvas.pixels, canvas.width, canvas.height, TPM_RGBA(255, 255, 255, 255));
    
    TPM_draw_line(canvas.pixels, canvas.width, canvas.height, -100, 0, 500, 500, TPM_RGBA(0, 0, 255, 255));

    TPM_save_as_png(canvas.pixels, canvas.width, canvas.height, file);

    return 0;
}
