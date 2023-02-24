#ifndef TPM
#define TPM

#include <stdlib.h>

#include "./tpm.h"

Image tpm_init_image(int width, int height)
{
    Image image; 
    image.data = malloc(width * height * sizeof(PIXEL));
    return image;
}

void tpm_set_pixel(Image* img, int x, int y, int r, int g, int b) 
{
    int index = y * img->width + x;
    img->data[index].r = r;
    img->data[index].g = g;
    img->data[index].b = b;
}

void tpm_dispose(Image* image)
{
    free(image->data);
}

#endif
