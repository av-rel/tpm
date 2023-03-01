#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/tpm.c"

#include "./line.c"
#include "./rect.c"
#include "./tri.c"
#include "./circle.c"

#define WIDTH 512
#define HEIGHT 512

uint pixels[WIDTH * HEIGHT];

int main(int argc, char** argv) {
    int ret;

    if (argc < 2) {
        printf("%s%s", "Available tests:\n" , "1. line\n2. rect\n3. tri\n4. circle\n");
        return 1;
    };

    TPM_Canvas canvas = TPM_init_canvas(pixels, WIDTH, HEIGHT);

    int i, j;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "line") == 0) ret = test_line(&canvas);
        else if (strcmp(argv[i], "rect") == 0) ret = test_rect(&canvas);
        else if (strcmp(argv[i], "tri") == 0) ret = test_tri(&canvas);
        else if (strcmp(argv[i], "circle") == 0) ret = test_circle(&canvas);
        else {
            printf("%s `%s` %s", "Test not recognized:", argv[i], "Failed\n");
            return -1;
        }
    }

    return ret;
}

