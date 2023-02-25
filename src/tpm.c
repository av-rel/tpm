#ifndef TPM_C
#define TPM_C

#include "tpm.h"

Canvas tpm_canvas(uint *pixels, uint width, uint height) 
{
    Canvas canvas = {
        .pixels = pixels,
        .width  = width,
        .height = height
    };
    return canvas;
}

void tpm_fill(Canvas *canvas, uint color)
{
    uint x, y;
    for (y = 0; y < canvas->height; y++)
        for (x = 0; x < canvas->width; ++x)
            canvas->pixels[(y) * canvas->width + (x)] = color;
}

void tpm_draw_line(Canvas *canvas, uint x1, uint y1, uint x2, uint y2 , uint color)
{

}

#endif
