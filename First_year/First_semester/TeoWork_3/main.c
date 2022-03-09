#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
    int i, n;
    printf("Please, enter a number of array elements: ");
    scanf("%d", &n);

    if (n < 1) {
        puts("Error: Incorrect number of array elements!");
        return 1;
    } else {
        double A[n];

        puts("");
        printf("Please, enter a number for each element of massive A:\n");
        for (i = 0; i < n; i++) {
            scanf("%lf", &A[i]);
        }

        bool checkpoint = false;
        int place_in_array = 0;
        double X;

        puts("");
        printf("Please, enter a number you search: ");
        scanf("%lf", &X);

        for (i = 0; i < n; i++) {
            if (X == A[i]) {
                checkpoint = true;
                place_in_array = i;
                break;
            }
        }

        if (checkpoint == true) {
            puts("I found it!");
            printf("It is in %dth place.", place_in_array + 1);
        } else {
            puts("I didn't find it :(");
            puts("Check the correctness of the entered number.");
        }

        return 0;
    }
}