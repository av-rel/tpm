#include "../src/tpm.c"
#include "../deps/fs.c"

#define WIDTH 900
#define HEIGHT 600

uint pixels[WIDTH * HEIGHT];

int main(int argc, char** argv) {
    char* file = "./jpn_flag.png";

    Canvas canvas = tpm_canvas(pixels, WIDTH, HEIGHT);
    tpm_fill_canvas(&canvas, 0xFFFFFFFF);
    tpm_draw_circle(&canvas, canvas.width / 2, canvas.height / 2, (canvas.width + canvas.height) * 1/10, 0xFF000088);

    save_to_png(canvas, file);
    return 0;
}
