#ifndef TPM_H
#define TPM_H

//AABBGGRR format for pixel rgba value
// 0xFF000000 is black

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
void tpm_fill(Canvas *canvas, uint color);

#endif
