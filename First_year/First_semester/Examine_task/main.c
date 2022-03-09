#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

double *input_array(int);
void output_array(const double *, int);

int main() {
    int n = 0;
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    double *arr = input_array(n);
    puts("Your array is:");
    output_array(arr, n);

    int index_min = 0, index_max = 0;
    double min = 1, max = -DBL_MAX;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i * n + j > i * n + i) {
                if (*(arr + i * n + j) > 0) {
                    double val = 0, frac;
                    frac = modf(*(arr + i * n + j), &val);

                    if (frac < 0) {
                        frac *= -1;
                    }

                    if (min > frac) {
                        min = frac;
                        index_min = i * n + j;
                    }
                }
            } else if (i * n + j < i * n + i) {
                if (*(arr + i * n + j) < 0) {

                    if (*(arr + i * n + j) > max) {
                        max = *(arr + i * n + j);
                        index_max = i * n + j;
                    }

                }
            }
        }
    }

    double val;
    val = arr[index_min];
    arr[index_min] = arr[index_max];
    arr[index_max] = val;

    puts("After some actions, the final array is:");
    output_array(arr, n);

    puts("Changed elements: ");
    printf("Positive element with minimum fractional part: %lf\n", arr[index_max]);
    printf("Maximum negative element: %lf", arr[index_min]);
    return 0;
}


double *input_array(int amount) {
    double *array = (double *)malloc(amount * amount * sizeof(double));
    printf("Enter each array element: ");
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < amount; j++) {
            scanf("%lf", (array + i * amount + j));
        }
    }

    return array;
}


void output_array(const double *array, int amount) {
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < amount; j++) {
            printf("%7lf ", *(array + i * amount + j));
        }
        printf("\n");
    }

    printf("\n");
}