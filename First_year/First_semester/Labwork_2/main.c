#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, indexmax, indexmin;

    puts("Please, enter a number of array elements.");
    scanf("%d", &n);

    if (n < 1) {
        puts("Error: Incorrect number if array elements.");
        return 1;
    }

    float A[n];
    puts("");

    puts("Please, enter a number for each element of massive A");
    for (i = 0; i < n; i++)
        scanf("%f", &A[i]);

    // printf(A)
    float imax = A[0];
    indexmax = 0;
    for (i = 1; i < n; i++) {
        if (imax < A[i]) {
            imax = A[i];
            indexmax = i;
        }
    }

    float imin = A[0];
    indexmin = 0;
    for (i = 1; i < n; i++) {
        if (imin > A[i]) {
            imin = A[i];
            indexmin = i;
        }
    }

    if (indexmax != indexmin) {
        A[indexmax] = imin;
        A[indexmin] = imax;
    }

    for (i = 0; i < n; i++)
        printf("%f\n", A[i]);

    free(A);
    return 0;
}