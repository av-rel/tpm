#ifndef TPM_H
#define TPM_H

//AABBGGRR format for pixel rgba value
// 0xFF000000 is blackt

typedef unsigned int uint;

typedef struct {
	uint r,g,b;
} RGB;

typedef struct {
	int x, y;
} Vec2;

typedef struct {
	uint *pixels, width, height;
} Canvas;

Canvas tpm_canvas(uint *pixels, uint width, uint height);
void tpm_fill_canvas(Canvas *canvas, uint color);
void tpm_draw_line(Canvas *canvas, uint x1, uint y1, uint x2, uint y2 , uint color);

#endif
