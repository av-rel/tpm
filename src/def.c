#ifndef DEF_C_
#define DEF_C_

#define TPM_PI 3.14159265359

#define TPM_ABS(n) (n < 0 ? -(n) : n)
#define TPM_SQR(n) (n*n)
#define TPM_MAX(a, b) (a > b ? a : b)
#define TPM_MIN(a, b) (a < b ? a : b)
#define TPM_SWAP(T, a, b) { T t = a; a = b; b = t; }

double TPM_SQRT(double x) {
    double guess = x / 2.0;
    double prev_guess;
    double error = 0.000001;

    do {
        prev_guess = guess;
        guess = (guess + x / guess) / 2.0;
    } while (prev_guess - guess > error || guess - prev_guess > error);

    return guess;
}

#endif
