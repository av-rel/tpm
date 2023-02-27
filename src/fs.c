#ifndef FS_C_
#define FS_C_

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../deps/stb_image_write.h"

int TPM_save_as_png(unsigned int *pixels, unsigned int width, unsigned int height, char* path) 
{
    return stbi_write_png(path, width, height, 4, pixels, sizeof(unsigned int) * width);
}

int TPM_save_as_jpg(unsigned int *pixels, unsigned int width, unsigned int height, char* path) 
{
    return stbi_write_jpg(path, width, height, 4, pixels, sizeof(unsigned int) * width);
}

int TPM_save_as_bmp(unsigned int *pixels, unsigned int width, unsigned int height, char* path) 
{
    return stbi_write_bmp(path, width, height, 4, pixels);
}

#endif
