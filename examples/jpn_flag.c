#include "../tpm.c"
#include "../deps/fs.c"

#define WIDTH 900
#define HEIGHT 600

uint pixels[WIDTH * HEIGHT];

int main(int argc, char** argv) {
    char* file = "./jpn_flag.png";
    
    TPM_Canvas canvas = TPM_init_canvas(pixels, WIDTH, HEIGHT);
    canvas.pixels = TPM_fill(&canvas, 0xFFFFFFFF);
    canvas.pixels = TPM_fill_circle(&canvas, canvas.width / 2, canvas.height / 2, (canvas.width + canvas.height) * 1/10, 0xFF000088);

    return TPM_save_as_png(canvas.pixels, canvas.width, canvas.height, file);
;
}
