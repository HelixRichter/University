#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDEX 1
#define MIN_N_PRIME 1

int *Eratosthene(int);

int main() {
    FILE *f;
    f = fopen("task.txt", "r");

    if (f == NULL) {
        perror("Oops, something went wrong");
        exit(1);
    }
    int n = 0;
    fscanf(f, "%d", &n);
    fclose(f);

    int *arr = Eratosthene(n);

    f = fopen("output.txt", "w+");
    if (f == NULL) {
        perror("Oops, something went wrong");
        exit(1);
    }

    // Алгоритм для чётных чисел
    if (!(n % 2)) {
        free(arr);
        fprintf(f, "%d %d", n / 2, n / 2);
        fclose(f);
        return 0;
    }

    // Алгоритм для нечётных чисел
    int m = n - 1; // Перестраховаться от простых чисел
    while (m) {
        if (!arr[m] && !(n % m)) {
            fprintf(f, "%d %d", m, n - m);
            fclose(f);
            free(arr);
            return 0;
        }
        m--;
    }

    // Алгоритм для изгоев (простых чисел)
    fprintf(f, "%d %d", MIN_N_PRIME, n - MIN_N_PRIME);
    fclose(f);
    free(arr);
    return 0;
}

int *Eratosthene(int n) {
    int *arr = (int*)malloc((n + INDEX) * sizeof(int)); // Выделение (n + INDEX) * sizeof(int) байтов памяти под массив
    memset(arr, 0, ((n + INDEX) * sizeof(int))); // Зануление (n + INDEX) * sizeof(int) байтов массива
    // memset() работает быстрее цикла, обнуляющего каждый ЭЛЕМЕНТ массива

    int i = 2;
    *arr = 1;
    *(arr + 1) = 1;

    while (i <= n) {
        if (!*(arr + i)) {
            int j = i + i;

            while (j <= n) {
                *(arr + j) = 1;
                j += i;
            }
        }

        i++;
    }
    return arr;
}