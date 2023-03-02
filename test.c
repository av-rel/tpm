#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dirent.h>

#define TPM_SAVE_AS
#include "./tpm.c"

#define WIDTH 500
#define HEIGHT 500
uint pixels[WIDTH * HEIGHT];

int test_fill_rect(TPM_Canvas* canvas);
int test_draw_rect(TPM_Canvas* canvas);
int test_draw_line(TPM_Canvas* canvas);
int test_draw_circle(TPM_Canvas* canvas);
int test_fill_circle(TPM_Canvas* canvas);
int test_fill_triangle(TPM_Canvas*canvas);
int test_draw_triangle(TPM_Canvas* canvas);

int main(int argc, char** argv) {
    if (mkdir("bin") == -1) {}

    TPM_Canvas canvas = TPM_init_canvas(pixels, WIDTH, HEIGHT);

    if (!test_fill_rect(&canvas)) return -1;
    if (!test_draw_rect(&canvas)) return -1;
    if (!test_draw_line(&canvas)) return -1;
    if (!test_draw_circle(&canvas)) return -1;
    if (!test_fill_circle(&canvas)) return -1;
    if (!test_draw_triangle(&canvas)) return -1;
    if (!test_fill_triangle(&canvas)) return -1;

    return 0;
}

int test_draw_triangle(TPM_Canvas* canvas) {
    char *file = "bin/triangle_draw.png";

    TPM_fill(canvas, TPM_RGBA(255, 255, 255, 255));

    TPM_draw_triangle(canvas,
            0, 100,
            canvas->width/4, canvas->height/4,
            canvas->width/2, canvas->height/3,
            TPM_RGBA(100, 100, 100, 255));

    int rl = TPM_save_as_png(canvas->pixels, canvas->width, canvas->height, file);

    printf("Triangle (draw): ");

    if (rl) printf("%s\n", "OK");
    else printf("%s\n", "\tFAILED");

    return rl;
}

int test_draw_line(TPM_Canvas* canvas) {
    char *file = "bin/line_draw.png";

    TPM_fill(canvas, TPM_RGBA(255, 255, 255, 255));

    TPM_draw_line(canvas, 
            canvas->width/2, canvas->height/2,
            canvas->width, canvas->height * 4,
            TPM_RGBA(100, 100, 100, 255));

    int rl = TPM_save_as_png(canvas->pixels, canvas->width, canvas->height, file);

    printf("Line (draw): ");

    if (rl) printf("%s\n", "OK");
    else printf("%s\n", "\tFAILED");

    return rl;
}

int test_fill_circle(TPM_Canvas* canvas) {
    char *file = "bin/circle_fill.png";

    TPM_fill(canvas, TPM_RGBA(255, 255, 255, 255));

    int radius = 50;
    TPM_fill_circle(canvas,
            0, 0,
            radius,
            TPM_RGBA(255, 100, 100, 255));

     int rl = TPM_save_as_png(canvas->pixels, 
             canvas->width,
             canvas->height,
             file);

    printf("Circle (fill): ");

    if (rl) printf("%s\n", "OK");
    else printf("%s\n", "\tFAILED");

    return rl;

}



int test_draw_circle(TPM_Canvas* canvas) {
    char *file = "bin/circle_draw.png";

    TPM_fill(canvas, TPM_RGBA(255, 255, 255, 255));

    int radius = 50;
    TPM_draw_circle(canvas,
            0, 0,
            radius,
            TPM_RGBA(255, 100, 100, 255));

     int rl = TPM_save_as_png(canvas->pixels, 
             canvas->width,
             canvas->height,
             file);

    printf("Circle (draw): ");

    if (rl) printf("%s\n", "OK");
    else printf("%s\n", "\tFAILED");

    return rl;

}

int test_draw_rect(TPM_Canvas* canvas) 
{
    char *file = "bin/rect_draw.png";

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
    char *file = "bin/rect_fill.png";

    TPM_fill(canvas, TPM_RGBA(255, 255, 255, 255));

    TPM_fill_rect(canvas, 
            0, canvas->height,
            canvas->width/5, -canvas->height/2,
            TPM_RGBA(100, 100, 100, 255)); 
    
    int rl = TPM_save_as_png(canvas->pixels, canvas->width, canvas->height, file);
    printf("Rectangle (fill): ");

    if (rl) printf("%s\n", "OK");
    else printf("%s\n", "\tfailed");

    return rl;
}

int test_fill_triangle(TPM_Canvas* canvas){
    char *file = "bin/triangle_fill.png";

    TPM_fill(canvas, TPM_RGBA(255, 255, 255, 255));

    TPM_fill_triangle(canvas,
            0, 0,
            canvas->width, 0,
            canvas->width/2, canvas->height/2,
            TPM_RGBA(100, 100, 100, 255)
            );

    int rl = TPM_save_as_png(canvas->pixels, canvas->width, canvas->height, file);

    printf("Triangle (fill): ");

    if (rl) printf("%s\n", "OK");
    else printf("%s\n", "\tFAILED");

    return rl;

}

