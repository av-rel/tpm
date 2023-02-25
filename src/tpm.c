#ifndef TPM_C
#define TPM_C

#include "tpm.h"
#include "def.h"

Canvas tpm_canvas(uint *pixels, uint width, uint height) 
{
    Canvas canvas = {
        .pixels = pixels,
        .width  = width,
        .height = height
    };
    return canvas;
}

void tpm_fill_canvas(Canvas *canvas, uint color)
{
    uint x, y;
    for (y = 0; y < canvas->height; y++)
        for (x = 0; x < canvas->width; ++x)
            canvas->pixels[(y) * canvas->width + (x)] = color;
}

void tpm_draw_line(Canvas *canvas, uint x1, uint y1, uint x2, uint y2 , uint color)
{
    uint x, y;
    for (x = x1; x <= x2; ++x) {
        uint index = y * canvas->width + x;
        y = (int)((float)(y2 - y1) / (float)(x2 - x1) * (float)(x - x1) + (float)y1);
        canvas->pixels[index] = color;
    }
}

#endif
