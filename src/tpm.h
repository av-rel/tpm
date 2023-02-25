#ifndef TPM_H
#define TPM_H

#define PPM_FORMAT "P3"

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

#endif
