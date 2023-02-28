#ifndef DEF_C_
#define DEF_C_

#define TPM_M_PI 3.14159265359

#define TPM_RGBA(r, g, b, a) \
    ( (((r) & 0xFF) << (8*0) ) | (((g) & 0xFF) << (8*1)) | (( (b) & 0xFF)<<(8*2)) | (((a)&0xFF)<<(8*3)) )

#define TPM_M_ABS(n) (n < 0 ? -(n) : n)
#define TPM_M_SQR(n) (n*n)
#define TPM_M_MAX(a, b) (a > b ? a : b)
#define TPM_M_MIN(a, b) (a < b ? a : b)
#define TPM_SWAP(T, a, b) { T t = a; a = b; b = t; }

double TPM_M_SQRT(double x) {
    double guess = x / 2.0;
    double prev_guess;
    double error = 0.000001;

    do {
        prev_guess = guess;
        guess = (guess + x / guess) / 2.0;
    } while (prev_guess - guess > error || guess - prev_guess > error);

    return guess;
}

double TPM_M_POW(double x, int exp) {
	double res = 1;

	int i;
	for (i = 0; i < exp; i++) res *= x;

	return res;
}

#define TPM_sort_vertices(x1, y1, x2, y2) { \
    if (y1 > y2) { TPM_SWAP(int, x1, x2); TPM_SWAP(int, y1, y2); } \
}

#define TPM_sort_triangle_points(x1, y1, x2, y2, x3, y3) { \
    TPM_sort_vertices(x1, y1, x2, y2);  \
    TPM_sort_vertices(x2, y2, x3, y3);  \
    TPM_sort_vertices(x1, y1, x2, y2);  \
}

#endif
