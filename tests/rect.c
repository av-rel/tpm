#include <stdio.h>
#include "../src/tpm.c"
#include "../src/fs.c"

int test_rect(TPM_Canvas* canvas) {
    char *file = "tests/rect.png";

    TPM_fill(canvas->pixels, canvas->width, canvas->height,
            TPM_RGBA(255, 255, 255, 255));

    TPM_fill_rect(canvas->pixels, canvas->width, canvas->height,
            canvas->width/2, canvas->height/2, 50, 50 ,
        TPM_RGBA(255, 0, 0, 255));

    return !TPM_save_as_png(canvas->pixels, canvas->width, canvas->height, file);
;
}
