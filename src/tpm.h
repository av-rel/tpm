#ifndef TPM_H
#define TPM_H

#define APP_NAME "TPM"

typedef struct {
	int r, g, b;
} RGB;

typedef RGB PIXEL;

typedef struct {
	int width, height;
	PIXEL *data;
} Image;


Image tpm_init_image(int width, int height);
void tpm_set_pixel(Image *img, int x, int y, int r, int g, int b);
void tpm_dispose(Image* image);

#endif
