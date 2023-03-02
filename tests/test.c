#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TPM_SAVE_AS
#include "../tpm.c"

#define WIDTH 500
#define HEIGHT 500
uint pixels[WIDTH * HEIGHT];

int test_fill_rect(TPM_Canvas* canvas);
int test_draw_rect(TPM_Canvas* canvas);

int main(int argc, char** argv) {
    TPM_Canvas canvas = TPM_init_canvas(pixels, WIDTH, HEIGHT);

    if (!test_fill_rect(&canvas)) return -1;
    if (!test_draw_rect(&canvas)) return -1;

    return 0;
}

int test_draw_rect(TPM_Canvas* canvas) 
{
    char *file = "tests/rect_draw.png";

    TPM_fill(canvas, TPM_RGBA(255, 255, 255, 255));

    TPM_draw_rect(canvas, 
            0, canvas->height,
            canvas->width/5 , -canvas->height/3,
            TPM_RGBA(100, 100, 100, 255));

     int rl = TPM_save_as_png(canvas->pixels, canvas->width, canvas->height, file);

    printf("Rectangle (draw): ");

    if (rl) printf("%s\n", "OK");
    else printf("%s\n", "\tFAILED");

    return rl;
}

int test_fill_rect(TPM_Canvas* canvas) 
{
    char *file = "tests/rect_fill.png";

    TPM_fill(canvas, TPM_RGBA(255, 255, 255, 255));

    TPM_fill_rect(canvas, 
            0, canvas->height,
            canvas->width/5, -canvas->height/2,
            TPM_RGBA(100, 100, 100, 255));

    int rl = TPM_save_as_png(canvas->pixels, canvas->width, canvas->height, file);

    printf("Rectangle (fill): ");

    if (rl) printf("%s\n", "OK");
    else printf("%s\n", "\tFAILED");

    return rl;
}
