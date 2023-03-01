#ifndef TPM_C_
#define TPM_C_

#include "def.c"

typedef unsigned int uint;

typedef struct {
    uint *pixels, width, height;
} TPM_Canvas;

TPM_Canvas TPM_init_canvas(uint *pixels, uint width, uint height) 
{
    TPM_Canvas canvas = {
        .pixels = pixels,
        .width  = width,
        .height = height
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

uint* TPM_fill_point(uint* pixels, uint width, uint height, uint x, uint y, uint color)
{
    pixels[y * width + x] = color;

    return pixels;
}

uint* TPM_draw_line(uint *pixels, uint width, uint height, int x1, int y1, int x2, int y2, uint color)
{
    TPM_sort_vertices(x1, y1, x2, y2);

    if (x1 > width) x1 = width;
    if (x2 > width) x2 = width;
    if (y1 > height) y1 = height;
    if (y2 > height) y2 = height;

    uint x;
    for (x = x1; x <= x2; x++) {
        uint y = (int)((float)(y2 - y1) / (float)(x2 - x1) * (float)(x - x1) + (float)y1);
        pixels[y * width + x] = color;
    }

    return pixels;
}

uint* TPM_fill_circle(uint *pixels, uint width, uint height, int cx, int cy, uint radius, uint color)
{
    uint x, y;
    for (y = 0; y < height; y++)
        for (x = 0; x < width; x++) {
            int dx = x - cx;
            int dy = y - cy;
            if (TPM_M_SQR(dx) + TPM_M_SQR(dy) <= TPM_M_SQR(radius)) {
                pixels[y * width + x] = color;
            }
        }

    return pixels;
}

uint* TPM_draw_circle(uint *pixels, uint width, uint height, int cx, int cy, uint radius, uint color)
{
    uint x, y;
    int r2 = TPM_M_SQR(radius);
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int dx = x - cx;
            int dy = y - cy;
            int d2 = TPM_M_SQR(dx) + TPM_M_SQR(dy);
            if (d2 > r2 - radius && d2 < r2 + radius) {
                pixels[y * width + x] = color;
            }
        }
    }

    return pixels;
}

uint* TPM_fill_rect(uint *pixels, uint width, uint height, int x, int y, int w, int h, uint color)
{
    if (w == 0 || h == 0) return pixels;

handler:
    if (x < 0) { w += x; x = 0; }
    if (y < 0) { h += y; y = 0; }
    if (w < 0) { w = TPM_M_ABS(w); x -= w; goto handler; }
    if (h < 0) { h = TPM_M_ABS(h); y -= h; goto handler; }

    uint i, j;
    for (i = x; i < (x + w); i++) {
        for (j = y; j < (y + h); j++) {
            pixels[j * width + i] = color;
        }
    }

    return pixels;
}

uint* TPM_draw_rect(uint *pixels, uint width, uint height, int x, int y, int w, int h, uint color) 
{
    uint i, j;

    for (i = x; i < x + w; i++) {
        pixels[y * width + i] = color;
        pixels[(y + h - 1) * width + i] = color;
    }

    for (j = y; j < y + h; j++) {
        pixels[j * width + x] = color;
        pixels[j * width + (x + w - 1)] = color;
    }

    return pixels;
}

//TODO: only fill triangle if inside canvas | donot fill if got out of canvas
uint* TPM_fill_triangle(uint* pixels, uint width, uint height, int x1, int y1, int x2, int y2, int x3, int y3, uint color)
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
            pixels[y * width + x]  = color;
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
uint* TPM_draw_triangle(uint* pixels, uint width, uint height, int x1, int y1, int x2, int y2, int x3, int y3, uint color) 
{
    return 0;
    TPM_sort_triangle_points(x1, y1, x2, y2, x3, y3)
    
    float m1 = (float)(x2 - x1) / (y2 - y1);
    float m2 = (float)(x3 - x1) / (y3 - y1);
    float m3 = (float)(x3 - x2) / (y3 - y2);
    
    uint x, y;
    
    return pixels;
}

#endif
