#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include <malloc.h>

#define ERR_BAD_ELEMENTS 1;
#define ERR_TOO_FEW_ELEMENTS 2;

double* bubble_sort(double*, int);

int main() {
    int n;
    printf("Enter the number of array elements: ");
    scanf("%d", &n);

    if (n < 1) {
        puts("Error: Incorrect number of array elements.");
        return ERR_BAD_ELEMENTS;
    } else if (n == 1) {
        puts("Error: There is nothing to sort in this array.");
        return ERR_TOO_FEW_ELEMENTS;
    } else {

        double *arr = (double *) malloc(n * sizeof(double));
        printf("Enter the number of each array element: ");
        for (int i = 0; i < n; i++) {
            scanf("%lf", &arr[i]);
        }

        bubble_sort(arr, n);

        puts("I sorted it!");
        printf("Here it is: ");
        for (int i = 0; i < n; i++) {
            printf("%lf ", arr[i]);
        }

        free(arr);
        return 0;
    }
}


double* bubble_sort(double *arr, int n) {
    double val;
    int checkpoint = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                val = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = val;
                checkpoint++;
            }
        }
        if (checkpoint == 0) {
            break;
        } else {
            checkpoint = 0;
            continue;
        }
    }

    return arr;
}
