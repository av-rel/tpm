#ifndef TPM_C_
#define TPM_C_

#include "deps/m.c"

#define TPM_RGBA(r, g, b, a) \
    ( (((r) & 0xFF) << (8*0) ) | (((g) & 0xFF) << (8*1)) | (( (b) & 0xFF)<<(8*2)) | (((a)&0xFF)<<(8*3)) )

#define TPM_SWAP(T, a, b) { T t = a; a = b; b = t; }

#define TPM_sort_triangle_points(x1, y1, x2, y2, x3, y3) { \
    if (y1 > y2) { TPM_SWAP(int, x1, x2); TPM_SWAP(int, y1, y2); }  \
    if (y2 > y3) { TPM_SWAP(int, x2, x3); TPM_SWAP(int, y2, y3); }  \
    if (y1 > y2) { TPM_SWAP(int, x1, x2); TPM_SWAP(int, y1, y2); }  \
}

void TPM_fit_rect(int width, int height, int *x, int *y, int *w, int *h)
{
handle:
    if (*x < 0) { *w += *x; *x = 0; }
    else if (*x > width) { *x = width - *w; }
    if (*y < 0) { *h += *y; *y = 0; }
    else if (*y > height) { *y = height - *h; }

    if (*w < 0) { *w = TPM_M_abs(*w); *x -= *w; goto handle; }
    if (*h < 0) { *h = TPM_M_abs(*h); *y -= *h; goto handle; }
}

typedef unsigned int uint;

typedef struct {
    uint *pixels;
    int width, height;
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

uint* TPM_fill(TPM_Canvas *canvas, uint color)
{
    int c;
    for (c = 0; c < canvas->width * canvas->height; c++) {
        canvas->pixels[c] = color;
    }

    return canvas->pixels;
}

uint* TPM_fill_point(TPM_Canvas *canvas, uint x, uint y, uint color)
{
    canvas->pixels[y * canvas->width + x] = color;

    return canvas->pixels;
}

uint* TPM_draw_line(TPM_Canvas *canvas, int x1, int y1, int x2, int y2, uint color)
{
    int dy = y2 - y1, dx = x2 - x1;

    if (dx == 0 && dy == 0) {
        canvas->pixels[ y1 * canvas->width + x1] = color;
        goto end;
    }

    if (TPM_M_abs(dx) > TPM_M_abs(dy)) {
        if (x1 > x2) {
            TPM_SWAP(int, x1, x2);
            TPM_SWAP(int, y1, y2);
        }

        if (x1 > canvas->width || x2 < 0) goto end;

        if (x1 < 0) { x1 = 0; }
        if (x2 > canvas->width) { x2 = canvas->width; }
       
        int x;
        for (x = x1; x <= x2; ++x) {
            int y = dy * (x - x1)/dx + y1;
            if (y > 0 && y < canvas->height) {
                canvas->pixels[y * canvas->width + x] = color;
            }
        }
    } else {
        if (y1 > y2) {
            TPM_SWAP(int, x1, x2);
            TPM_SWAP(int, y1, y2);
        }

        if (y1 > canvas->height || y2 < 0) goto end;

        if (y1 < 0) { y1 = 0; }
        if (y2 > canvas->height) { y2 = canvas->height; }

        int y;
        for (y = y1; y <= y2; ++y) {
            int x = dx * (y - y1)/dy + x1;
            if (x > 0 && x < canvas->width) {
                canvas->pixels[y * canvas->width + x] = color;
            }
        }
    }

end:
    return canvas->pixels;
}

uint* TPM_fill_circle(TPM_Canvas *canvas, int cx, int cy, int radius, uint color)
{
    if (radius <= 0) goto end;

    int x, y;
    for (y = 0; y < canvas->height; y++)
        for (x = 0; x < canvas->width; x++) {
            int dx = x - cx;
            int dy = y - cy;
            /* x^2 + y^2 = r^2 */
            if (TPM_M_sqr(dx) + TPM_M_sqr(dy) <= TPM_M_sqr(radius)) {
                canvas->pixels[y * canvas->width + x] = color;
            }
        }
end:
    return canvas->pixels;
}

uint* TPM_draw_circle(TPM_Canvas *canvas, int cx, int cy, int radius, uint color)
{
    if (radius <= 0) goto end;

    int x, y;
    int r2 = TPM_M_sqr(radius);
    for (y = 0; y < canvas->height; y++) {
        for (x = 0; x < canvas->width; x++) {
            int dx = x - cx;
            int dy = y - cy;
            int d2 = TPM_M_sqr(dx) + TPM_M_sqr(dy);
            if (d2 > r2 - radius && d2 < r2 + radius) {
                canvas->pixels[y * canvas->width + x] = color;
            }
        }
    }
end:
    return canvas->pixels;
}

uint* TPM_fill_rect(TPM_Canvas *canvas, int x, int y, int w, int h, uint color)
{
    if ( w == 0 || h == 0 ) goto end;
    TPM_fit_rect(canvas->width, canvas->height, &x, &y, &w, &h);

    int sx = (x + w), sy = (y + h);
    if (sx > canvas->width) sx = canvas->width;
    if (sy > canvas->height) sy = canvas->height;

    int i, j;
    for (i = x; i < sx; i++) {
        for (j = y; j < sy; j++) {
            canvas->pixels[j * canvas->width + i] = color;
        }
    }

end:
    return canvas->pixels;
}

/*
 * TODO: donot draw the corners if the cordinates is supposed to be out of canvas
 * */
uint* TPM_draw_rect(TPM_Canvas *canvas, int x, int y, int w, int h, uint color) 
{
handler:
    if (w == 0 || h == 0) goto end;
    int x0 = x, y0 = y, w0 = w, h0 = h;

    TPM_fit_rect(canvas->width, canvas->height, &x, &y, &w, &h);
   
    int sx = (x + w), sy = (y + h);
    if (sx > canvas->width) sx = canvas->width;
    if (sy > canvas->height) sy = canvas->height;

    int i, j;
    for (i = x; i < sx; i++) {
        for (j = y; j < sy; j++) {
            if (i == x || (i+1) == sx || j == y || (j + 1) == sy) {
                canvas->pixels[j * canvas->width + i] = color;
            }
        }
    }

end:
    return canvas->pixels;
}

//TODO: only fill triangle if inside canvas | donot fill if got out of canvas
uint* TPM_fill_triangle(TPM_Canvas *canvas, int x1, int y1, int x2, int y2, int x3, int y3, uint color)
{
    /* 2A = x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) */
    TPM_sort_triangle_points(x1, y1, x2, y2, x3, y3);
    
    /* float m1 = (float)(x2 - x1) / (y2 - y1); */
    /* float m2 = (float)(x3 - x1) / (y3 - y1); */
    /* float m3 = (float)(x3 - x2) / (y3 - y2); */

    return canvas->pixels;
}

//TODO: implement draw triangle unfilled
uint* TPM_draw_triangle(TPM_Canvas *canvas, int x1, int y1, int x2, int y2, int x3, int y3, uint color) 
{
    return 0;
    TPM_sort_triangle_points(x1, y1, x2, y2, x3, y3)
    
    float m1 = (float)(x2 - x1) / (y2 - y1);
    float m2 = (float)(x3 - x1) / (y3 - y1);
    float m3 = (float)(x3 - x2) / (y3 - y2);
    
    int x, y;
    
    return canvas->pixels;
}

#endif

#ifdef TPM_SAVE_AS
#include "deps/fs.c"
#endif

