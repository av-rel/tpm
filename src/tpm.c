#ifndef TPM_C_
#define TPM_C_

#include "def.c"

typedef unsigned int uint;

typedef struct {
    uint *pixels, width, height;
} TPM_Canvas;

TPM_Canvas TPM_init_canvas(uint *pixels, uint canvas_width, uint canvas_height);

uint* TPM_fill(uint *pixels, uint width, uint height, uint color);
uint* TPM_fill_point(uint* pixels, uint stride, uint x, uint y, uint color);
uint* TPM_fill_circle(uint *pixels, uint canvas_width, uint canvas_height, uint cx, uint cy, uint radius, uint color);
uint* TPM_fill_rect(uint *pixels, uint canvas_width, uint canvas_height, uint x, uint y, uint width, uint height, uint color);
uint* TPM_fill_triangle(uint* pixels, uint canvas_width, uint canvas_height, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint color);

uint* TPM_draw_line(uint *pixels, uint canvas_width, uint height, uint x1, uint y1, uint x2, uint y2 , uint color);
uint* TPM_draw_circle(uint *pixels, uint canvas_width, uint canvas_height, uint cx, uint cy, uint radius, uint color);
uint* TPM_draw_rect(uint *pixels, uint canvas_width, uint canvas_height, uint x, uint y, uint width, uint height, uint color);
uint* TPM_draw_triangle(uint* pixels, uint canvas_width, uint canvas_height, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint color);

TPM_Canvas TPM_init_canvas(uint *pixels, uint canvas_width, uint canvas_height) 
{
    TPM_Canvas canvas = {
        .pixels = pixels,
        .width  = canvas_width,
        .height = canvas_height
    };

    return canvas;
}

uint* TPM_fill(uint *pixels, uint width, uint height, uint color)
{
    uint x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            pixels[y * width + x] = color;
        }
    }

    return pixels;
}

uint* TPM_fill_point(uint* pixels, uint stride, uint x, uint y, uint color)
{
    pixels[y * stride + x] = color;

    return pixels;
}

uint* TPM_draw_line(uint *pixels, uint canvas_width, uint height, uint x1, uint y1, uint x2, uint y2 , uint color)
{
    uint x, y;
    for (x = x1; x <= x2; x++) {
        y = (int)((float)(y2 - y1) / (float)(x2 - x1) * (float)(x - x1) + (float)y1);
        pixels[y * canvas_width + x] = color;
    }

    return pixels;
}

uint* TPM_fill_circle(uint *pixels, uint canvas_width, uint canvas_height, uint cx, uint cy, uint radius, uint color)
{
    uint x, y;
    for (y = 0; y < canvas_height; y++)
        for (x = 0; x < canvas_width; x++) {
            int dx = x - cx;
            int dy = y - cy;
            if (TPM_SQR(dx) + TPM_SQR(dy) <= TPM_SQR(radius)) {
                pixels[y * canvas_width + x] = color;
            }
        }

    return pixels;
}

uint* TPM_draw_circle(uint *pixels, uint canvas_width, uint canvas_height, uint cx, uint cy, uint radius, uint color)
{
    uint x, y;
    int r2 = TPM_SQR(radius);
    for (y = 0; y < canvas_height; y++) {
        for (x = 0; x < canvas_width; x++) {
            int dx = x - cx;
            int dy = y - cy;
            int d2 = TPM_SQR(dx) + TPM_SQR(dy);
            if (d2 > r2 - radius && d2 < r2 + radius) {
                pixels[y * canvas_width + x] = color;
            }
        }
    }

    return pixels;
}

uint* TPM_fill_rect(uint *pixels, uint canvas_width, uint canvas_height, uint x, uint y, uint width, uint height, uint color)
{
    uint i, j;
    for (i = x; i < (x + width); i++) {
        for (j = y; j < (y + height); j++) {
            pixels[j * canvas_width + i] = color;
        }
    }

    return pixels;
}

uint* TPM_draw_rect(uint *pixels, uint canvas_width, uint canvas_height, uint x, uint y, uint width, uint height, uint color) 
{
    uint i, j;

    for (i = x; i < x + width; i++) {
        pixels[y * canvas_width + i] = color;
        pixels[(y + height - 1) * canvas_width + i] = color;
    }

    for (j = y; j < y + height; j++) {
        pixels[j * canvas_width + x] = color;
        pixels[j * canvas_width + (x + width - 1)] = color;
    }

    return pixels;
}

//TODO: only fill triangle if inside canvas | donot fill if got out of canvas
uint* TPM_fill_triangle(uint* pixels, uint canvas_width, uint canvas_height, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint color)
{
    TPM_sort_triangle_points(x1, y1, x2, y2, x3, y3);
    
    float m1 = (float)(x2 - x1) / (y2 - y1);
    float m2 = (float)(x3 - x1) / (y3 - y1);
    float m3 = (float)(x3 - x2) / (y3 - y2);
    
    float xl = x1;
    float xr = x1;
    
    uint x, y;
    for (y = y1; y <= y3; y++) {
        for (x = (int)xl; x <= (int)xr; x++) {
            pixels[y * canvas_width + x]  = color;
        }
        if (y < y2) {
            xl += m1;
            xr += m2;
        } else {
            xl += m3;
            xr += m2;
        }
        xr += m3;
    }
    
    return pixels;
}

//TODO: implement draw triangle unfilled
uint* TPM_draw_triangle(uint* pixels, uint canvas_width, uint canvas_height, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint color) 
{
    return 0;
    TPM_sort_triangle_points(x1, y1, x2, y2, x3, y3);
    
    float m1 = (float)(x2 - x1) / (y2 - y1);
    float m2 = (float)(x3 - x1) / (y3 - y1);
    float m3 = (float)(x3 - x2) / (y3 - y2);
    
    uint x, y;
    
    return pixels;
}

#endif
