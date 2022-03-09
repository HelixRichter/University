#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ERR_BAD_ELEMENTS 1;
#define ERR_TOO_FEW_ELEMENTS 2;

double* simple_choice_sort(double*, int);
int compare(const void*, const void*);

int main() {
    int n;
    printf("Please, enter a number of array elements: ");
    scanf("%d", &n);

    if (n < 1) {
        puts("Error: Incorrect number of array elements.");
        return ERR_BAD_ELEMENTS
    } else if (n == 1) {
        puts("Error: There is nothing to sort in this array.");
        return ERR_TOO_FEW_ELEMENTS
    } else {
        double *arr = (double*) malloc(n * sizeof(double)),
                *arrcopy = (double*) malloc(n * sizeof(double));
        printf("Enter each array number: ");
        for (int i = 0; i < n; i++) {
            scanf("%lf", &arr[i]);
        }
        memmove(arrcopy, arr, n * sizeof(double));

        clock_t bubble_sort_time_start, bubble_sort_time_end;
        bubble_sort_time_start = clock();
        simple_choice_sort(arr, n);
        bubble_sort_time_end = clock();

        clock_t qsort_time_start, qsort_time_end;
        qsort_time_start = clock();
        qsort(arrcopy, n, sizeof(double), compare);
        qsort_time_end = clock();

        puts("");

        puts("Hey, I sorted it!");
        printf("Here is the array sorted by the bubble method: ");
        for (int i = 0; i < n; i++) {
            printf("%lf ", arr[i]);
        }
        printf("\n");
        printf("The time it took to use this method is %lf seconds.", ((double)bubble_sort_time_end - (double)bubble_sort_time_start) / CLOCKS_PER_SEC);

        puts("\n");

        puts("So, I sorted it by another method, the qsort function!");
        printf("Here is it. Trust me, it's sorted differently: ");
        for (int i = 0; i < n; i++) {
            printf("%lf ", arrcopy[i]);
        }
        printf("\n");
        printf("The time it took to use this method is %lf seconds.", ((double)qsort_time_end - (double)qsort_time_start) / CLOCKS_PER_SEC);

        free(arr);
        free(arrcopy);
        return 0;
    }
}


double* simple_choice_sort(double *arr, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            double val = arr[i];
            arr[i] = arr[min];
            arr[min] = val;
        }
    }

    return arr;
}


int compare(const void* first_value, const void* second_value) {
    if (*(double*)first_value > *(double*)second_value) {
        return 1;
    } else if (*(double*)first_value < *(double*)second_value) {
        return -1;
    } else {
        return 0;
    }
}
