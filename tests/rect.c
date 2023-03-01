#include <stdio.h>
#include "../tpm.c"
#include "../deps/fs.c"

int test_rect(TPM_Canvas* canvas) {
    char *file = "tests/rect.png";

    TPM_fill(canvas, TPM_RGBA(255, 255, 255, 255));

    TPM_fill_rect(canvas,
       -100, -100, 200, 50 ,
        TPM_RGBA(255, 0, 0, 255));

    return !TPM_save_as_png(canvas->pixels, canvas->width, canvas->height, file);
;
}
