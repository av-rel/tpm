#ifndef TPM_C
#define TPM_C

#include "tpm.h"
#include "def.h"

TPM_Canvas tpm_canvas(uint *pixels, uint width, uint height) 
{
    TPM_Canvas canvas = {
        .pixels = pixels,
        .width  = width,
        .height = height
    };
    return canvas;
}

uint* tpm_fill(uint *pixels, uint width, uint height, uint color)
{
    uint x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            pixels[y * width + x] = color;
        }
    }
    return pixels;
}

uint* tpm_draw_line(uint *pixels, uint canvas_width, uint height, uint x1, uint y1, uint x2, uint y2 , uint color)
{
    uint x, y;
    for (x = x1; x <= x2; x++) {
        uint index = y * canvas_width + x;
        y = (int)((float)(y2 - y1) / (float)(x2 - x1) * (float)(x - x1) + (float)y1);
        pixels[index] = color;
    }
    return pixels;
}

uint* tpm_fill_circle(uint *pixels, uint canvas_width, uint canvas_height, int cx, int cy, uint radius, uint color)
{
    uint x, y;
    for (y = 0; y < canvas_height; y++)
        for (x = 0; x < canvas_width; x++) {
            int dx = x - cx;
            int dy = y - cy;
            int distance_sqr = SQR(dx) + SQR(dy);
            if (distance_sqr <= SQR(radius)) {
                pixels[y * canvas_width + x] = color;
            }
        }
    return pixels;
}

/* uint* tpm_draw_circle(uint *pixels, uint canvas_width, uint canvas_height, int cx, int cy, uint radius, uint color) */
/* { */
/*     uint i, j; */
/*     for (i = 0; i < canvas_width; i++) { */
/*         for (j = 0; j < canvas_height; j++) { */
/*             int dx = i - cx; */
/*             int dy = j - cy; */
/*             //Able to root without stdlib for empty circle drawing */
/*             int distance_root = sqrt(SQR(dx) + SQR(dy)); */
/*             if (distance_root == radius) { */
/*                 pixels[j * canvas_width + i] = color; */
/*             } */
/*         } */
/*     } */
/*     return pixels; */
/* } */

uint* tpm_fill_rect(uint *pixels, uint canvas_width, uint canvas_height, int x, int y, uint width, uint height, uint color)
{
    uint i, j;
    for (i = x; i < (x + width); i++) {
        for (j = y; j < (y + height); j++) {
            pixels[j * canvas_width + i] = color;
        }
    }
    return pixels;
}

uint* tpm_draw_rect(uint *pixels, uint canvas_width, uint canvas_height, int x, int y, uint width, uint height, uint color) 
{
    uint i, j;
    
    // Draw the top and bottom edges of the rectangle
    for (i = x; i < x + width; i++) {
        pixels[y * canvas_width + i] = color;
        pixels[(y + height - 1) * canvas_width + i] = color;
    }

    // Draw the left and right edges of the rectangle
    for (j = y; j < y + height; j++) {
        pixels[j * canvas_width + x] = color;
        pixels[j * canvas_width + (x + width - 1)] = color;
    }
    return pixels;
}

#endif
