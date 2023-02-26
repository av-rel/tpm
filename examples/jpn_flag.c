#include "../src/tpm.c"
#include "../deps/fs.c"

#define WIDTH 900
#define HEIGHT 600

uint pixels[WIDTH * HEIGHT];

int main(int argc, char** argv) {
    char* file = "./jpn_flag.png";
    
    TPM_Canvas canvas = tpm_canvas(pixels, WIDTH, HEIGHT);
    canvas.pixels = tpm_fill(canvas.pixels, canvas.width, canvas.height, 0xFFFFFFFF);
    canvas.pixels = tpm_fill_circle(canvas.pixels, canvas.width, canvas.height, canvas.width / 2, canvas.height / 2, (canvas.width + canvas.height) * 1/10, 0xFF000088);

    fs_save_to_png(canvas, file);

    return 0;
}
