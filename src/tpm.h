#ifndef _TPM_H_
#define _TPM_H_

typedef unsigned int uint;

typedef struct {
	uint *pixels, width, height;
} TPM_Canvas;

TPM_Canvas TPM_init_canvas(uint *pixels, uint canvas_width, uint canvas_height);

uint* TPM_fill(uint *pixels, uint width, uint height, uint color);
uint* TPM_fill_point(uint* pixels, uint canvas_width, uint canvas_height, int x, int y, uint color);
uint* TPM_fill_circle(uint *pixels, uint canvas_width, uint canvas_height, int cx, int cy, uint radius, uint color);
uint* TPM_fill_rect(uint *pixels, uint canvas_width, uint canvas_height, int x, int y, uint width, uint height, uint color);
uint* TPM_fill_triangle(uint* pixels, uint canvas_width, uint canvas_height, int x1, int y1, int x2, int y2, int x3, int y3, uint color);

uint* TPM_draw_line(uint *pixels, uint canvas_width, uint height, int x1, int y1, int x2, int y2 , uint color);
uint* TPM_draw_circle(uint *pixels, uint canvas_width, uint canvas_height, int cx, int cy, uint radius, uint color);
uint* TPM_draw_rect(uint *pixels, uint canvas_width, uint canvas_height, int x, int y, uint width, uint height, uint color);
uint* TPM_draw_triangle(uint* pixels, uint canvas_width, uint canvas_height, int x1, int y1, int x2, int y2, int x3, int y3, uint color);

#endif
