#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NO_X "Answer doesn't exist."
#define ALL_X "All answers exist."

int x_divider(int, int, int, int);
void divide_polynomials(double, double, double, double, double, FILE*);

int main(void) {
    FILE *f;
    f = fopen("input.txt", "r");
    if (!f) {
        perror("Something went wrong with file opening:");
    }

    int a, b, c, d;
    fscanf(f, "%d %d %d %d", &a, &b, &c, &d);
    fclose(f);

    f = fopen("output.txt", "w+");

    if (!a && !b && !c && d) {
        if (d) {
            fprintf(f, "%s", NO_X);
        } else {
            fprintf(f, "%s", ALL_X);
        }
    } else if (!a && !b && c && d) {
        fprintf(f, "1 %lf", ((-1.0) * d / c));
    } else if (!a && b && c && d) {
        double discr = b * b - 4 * a * c;
        if (!discr) {
            double x = (-1.0) * b / (2 * a);
            fprintf(f, "1 %lf", x);
        } else if (discr > 0) {
            double x1 = (-b - sqrt(discr)) / (2 * a);
            double x2 = (-b + sqrt(discr)) / (2 * a);
            fprintf(f, "2 %lf %lf", x1, x2);
        } else {
            fprintf(f, "%s", NO_X);
        }
    }  else if (a && b && !c && !d) {
        fprintf(f, "2 %d %lf", 0, (-1.0) * b / a);
    } else if (a && b && c && !d) {
        double discr = b * b - 4 * a * c;
        if (!discr) {
            double x = (-1.0) * b / (2 * a);
            fprintf(f, "1 %lf", x);
        } else if (discr > 0) {
            double x1 = (-b - sqrt(discr)) / (2 * a);
            double x2 = (-b + sqrt(discr)) / (2 * a);
            fprintf(f, "3 0 %lf %lf", x1, x2);
        } else {
            fprintf(f, "1 0");
        }
    } else if ((a && !b && !c && !d) || (!a && b && !c && !d) || (!a && !b && c && !d) || (a && !b && c && !d)) {
        fprintf(f, "1 0");
    } else if (a && !b && !c && d) {
        fprintf(f, "1 %lf", cbrt((-1.0) * d / a));
    } else if (!a && b && !c && d) {
        if (abs((int)b) != b && abs((int)d) == d || abs((int)b) == b && abs((int)d) != d) {
            fprintf(f, "2 %lf -%lf", sqrt((double)d / -b), sqrt((double)d / -b));
        } else {
            fprintf(f, "%s", NO_X);
        }
    } else if (!a && b && c && !d) {
        fprintf(f, "2 0 %lf", (-1.0 * c / b));
    } else if (a && !b && c && d) {
        fprintf(f, "-1");
    } else if (a && b && !c && d) {
        fprintf(f, "-1");
    }
    else {
        int divider = x_divider(a, b, c, d);
        if (!divider) {
            fprintf(f, "%s", NO_X);
        } else {
            divide_polynomials((double)a, (double)b, (double)c, (double)d, (double)divider, f);
        }
    }

    fclose(f);
    return 0;
}


int x_divider(int a, int b, int c, int d) {
    int d1 = abs(d);
    for (int i = 1; i <= d1; i++) {
        if (!(d % i)) {
            int k = i;
            if (k * k * k * a + k * k * b + k * c + d == 0) {
                return k;
            }

            k = -i;
            if (k * k * k * a + k * k * b + k * c + d == 0) {
                return k;
            }
        }
    }

    return 0;
}


void divide_polynomials(double a, double b, double c, double d, double divider, FILE *f) {
    double arr[4];
    arr[0] = a * 1.0;
    arr[1] = b * 1.0;
    arr[2] = c * 1.0;
    arr[3] = d * 1.0;

    for (int i = 0; i < 3; i++) {
        double cf = -arr[i];
        arr[i + 1] -= 1.0 * divider * cf;
    }

    a = arr[0];
    b = arr[1];
    c = arr[2];
    d = arr[3];

    double discr = b * b - 4.0 * a * c;
    if (!discr) {
        double x = (-1.0) * b / (2 * a);
        fprintf(f, "3 %lf %lf %lf", divider, x, x);
    } else if (discr > 0) {
        double x1 = (-b - sqrt(discr)) / (2.0 * a);
        double x2 = (-b + sqrt(discr)) / (2.0 * a);
        fprintf(f, "3 %lf %lf %lf", divider, x1, x2);
    } else {
        fprintf(f, "1 %lf", divider);
    }
}