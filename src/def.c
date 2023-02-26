#ifndef _DEF_C_
#define _DEF_C_

#define ABS(n) (n < 0 ? -(n) : n)
#define SQR(n) (n*n)
#define MAX(a, b) ( a > b ? a : b)
#define MIN(a, b) ( a < b ? a : b)
#define SWAP_INT(a, b) { a += b; b = a - b; a -= b; }

double SQRT(double x) {
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
