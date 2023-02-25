#ifndef TPM_H
#define TPM_H

#define APP_NAME "TPM"

typedef struct {
	int r, g, b;
} RGB;

typedef RGB Pixel;

typedef struct {
	int width, height;
	Pixel data[];
} Image;


Image tpm_init_image(int width, int height);
void tpm_set_pixel(Image *img, int x, int y, int r, int g, int b);

#endif
