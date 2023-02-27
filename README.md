# TPM - The Pixel Manager

## Description

TPM is a pixel renderer to be formatted and saved to image format or also be used for rendering images in Canvas like SDL or HTML Canvas (using Wasm)

## Perks
- Pure c
- No standard library
- Can be used by any std version of c
- Able to draw different geometrical shapes

## Example
```c
#include "tpm/src/tpm.c"
#include "tpm/src/fs.c"

#define WIDTH 900
#define HEIGHT 600

uint pixels[WIDTH * HEIGHT];

int main(int argc, char** argv) {
    char* file = "./jpn_flag.png";

    TPM_Canvas canvas = TPM_init_canvas(pixels, WIDTH, HEIGHT);
    canvas.pixels = TPM_fill(canvas.pixels, canvas.width, canvas.height, 0xFFFFFFFF);
    canvas.pixels = TPM_fill_circle(canvas.pixels, canvas.width, canvas.height, canvas.width / 2, canvas.height / 2, (canvas.width + canvas.height) * 1/10, 0xFF000088);

    return TPM_save_as_png(canvas, file);;
}
```

![Japan Flag](./examples/jpn_flag.png)

---


```c
#include "tpm/src/tpm.c"
#include "tpm/src/fs.c"

#define WIDTH 960
#define HEIGHT 540

uint pixels[WIDTH * HEIGHT];

int main(int argc, char** argv) {
    char* file = "./eng_flag.png";

    TPM_Canvas canvas = TPM_init_canvas(pixels, WIDTH, HEIGHT);
    TPM_fill(canvas.pixels, canvas.width, canvas.height, 0xFFFFFFFF);

    //vertical rect
    uint ver_w = (canvas.width + canvas.height) / 15, ver_h = canvas.height;
    uint ver_x = canvas.width / 2 - ver_w / 2 , ver_y = 0;
    TPM_fill_rect(canvas.pixels, canvas.width, canvas.height, ver_x, ver_y, ver_w, ver_h, 0xFF000088);

    //horizontal rect
    uint hor_w = canvas.width, hor_h = (canvas.width + canvas.height) / 15;
    uint hor_x = 0, hor_y = canvas.height / 2 - hor_h / 2 ;
    TPM_fill_rect(canvas.pixels, canvas.width, canvas.height, hor_x, hor_y, hor_w, hor_h, 0xFF000088);
        
    return TPM_save_as_png(canvas, file);
}
```

![ENGLAND](./examples/eng_flag.png)

