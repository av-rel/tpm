#ifndef TPM_C_
#define TPM_C_

#define TPM_M_PI 3.14159265359

#define TPM_RGBA(r, g, b, a) \
    ( (((r) & 0xFF) << (8*0) ) | (((g) & 0xFF) << (8*1)) | (( (b) & 0xFF)<<(8*2)) | (((a)&0xFF)<<(8*3)) )

#define TPM_M_ABS(n) (n < 0 ? -(n) : n)
#define TPM_M_SQR(n) (n*n)
#define TPM_M_MAX(a, b) (a > b ? a : b)
#define TPM_M_MIN(a, b) (a < b ? a : b)
#define TPM_SWAP(T, a, b) { T t = a; a = b; b = t; }

double TPM_M_SQRT(double x) {
    double guess = x / 2.0;
    double prev_guess;
    double error = 0.000001;

    do {
        prev_guess = guess;
        guess = (guess + x / guess) / 2.0;
    } while (prev_guess - guess > error || guess - prev_guess > error);

    return guess;
}

double TPM_M_POW(double x, int exp) {
    double res = 1;

    int i;
    if (exp < 0) return (1 / TPM_M_POW(x, TPM_M_ABS(exp)));
    else for (i = 0; i < exp; i++) res *= x;

    return res;
}

#define TPM_sort_vertices(x1, y1, x2, y2) { \
    if (y1 > y2) { TPM_SWAP(int, x1, x2); TPM_SWAP(int, y1, y2); } \
}

#define TPM_sort_triangle_points(x1, y1, x2, y2, x3, y3) { \
    TPM_sort_vertices(x1, y1, x2, y2);  \
    TPM_sort_vertices(x2, y2, x3, y3);  \
    TPM_sort_vertices(x1, y1, x2, y2);  \
}

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

uint* TPM_fill(TPM_Canvas *canvas, uint color)
{
    uint x, y;
    for (y = 0; y < canvas->width; y++) {
        for (x = 0; x < canvas->width; x++) {
            canvas->pixels[y * canvas->width + x] = color;
        }
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
    TPM_sort_vertices(x1, y1, x2, y2);

    uint x;
    for (x = x1; x <= x2; x++) {
        uint y = (int)((float)(y2 - y1) / (float)(x2 - x1) * (float)(x - x1) + (float)y1);
        canvas->pixels[y * canvas->width + x] = color;
    }

    return canvas->pixels;
}

uint* TPM_fill_circle(TPM_Canvas *canvas, int cx, int cy, uint radius, uint color)
{
    uint x, y;
    for (y = 0; y < canvas->height; y++)
        for (x = 0; x < canvas->width; x++) {
            int dx = x - cx;
            int dy = y - cy;
            /* x^2 + y^2 = r^2 */
            if (TPM_M_SQR(dx) + TPM_M_SQR(dy) <= TPM_M_SQR(radius)) {
                canvas->pixels[y * canvas->width + x] = color;
            }
        }

    return canvas->pixels;
}

uint* TPM_draw_circle(TPM_Canvas *canvas, int cx, int cy, uint radius, uint color)
{
    uint x, y;
    int r2 = TPM_M_SQR(radius);
    for (y = 0; y < canvas->height; y++) {
        for (x = 0; x < canvas->width; x++) {
            int dx = x - cx;
            int dy = y - cy;
            int d2 = TPM_M_SQR(dx) + TPM_M_SQR(dy);
            if (d2 > r2 - radius && d2 < r2 + radius) {
                canvas->pixels[y * canvas->width + x] = color;
            }
        }
    }

    return canvas->pixels;
}

uint* TPM_fill_rect(TPM_Canvas *canvas, int x, int y, int w, int h, uint color)
{
    uint i, j;
    for (i = x; i < (x + w); i++) {
        for (j = y; j < (y + h); j++) {
            canvas->pixels[j * canvas->width + i] = color;
        }
    }

    return canvas->pixels;
}

uint* TPM_draw_rect(TPM_Canvas *canvas, int x, int y, int w, int h, uint color) 
{
    if (w == 0 || h == 0) return canvas->pixels;

    return canvas->pixels;
}

//TODO: only fill triangle if inside canvas | donot fill if got out of canvas
uint* TPM_fill_triangle(TPM_Canvas *canvas, int x1, int y1, int x2, int y2, int x3, int y3, uint color)
{
    TPM_sort_triangle_points(x1, y1, x2, y2, x3, y3);
    
    float m1 = (float)(x2 - x1) / (y2 - y1);
    float m2 = (float)(x3 - x1) / (y3 - y1);
    float m3 = (float)(x3 - x2) / (y3 - y2);
    
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
    
    uint x, y;
    
    return canvas->pixels;
}

#endif
