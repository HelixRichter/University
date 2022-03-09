#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, n;
    printf("Please, enter a number if array elements: ");
    scanf("%d",&n);

    if (n < 1) {
        puts("Error: Incorrect number of array elements!");
        return 1;
    } else {
        double A[n];

        puts("");
        puts("Please, enter a number for each element of array A.");
        for (i = 0; i < n; i++) {
            scanf("%lf", &A[i]);
        }

        puts("");
        double X;
        printf("Please, enter a number you wanna search: ");
        scanf("%lf", &X);
        int left_of_array = 0, middle_of_array, right_of_array = n - 1;
        while (left_of_array <= right_of_array) {
            middle_of_array = (left_of_array + right_of_array) / 2;

            if (X == A[middle_of_array]) {
                puts("I found it!");

                for (i = 0; i <= right_of_array; i++) {
                    if (X == A[i]) {
                        printf("It is in %dth place.", i + 1);
                        break;
                    }
                }

                return 0;
            } else if (X < A[middle_of_array]) {
                right_of_array = middle_of_array - 1;
            } else if (X > A[middle_of_array]) {
                left_of_array = middle_of_array + 1;
            }
        }

        puts("I didn't find it :(");

        return 0;
    }
}
