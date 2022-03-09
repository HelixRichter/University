#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-err34-c"

#include <stdio.h>
#include <stdlib.h>

#define TOO_LOW_NUMBERS 1;
#define BAD_FILE_OPEN 2;

/*
 * Дано N целых чисел. Требуется выбрать из них 3 таких числа, произведение
 * которых максимально.
 *
 * Формат входных данных: Во входном файле записано сначала число N -
 * количество чисел в последовательности (3 <= N <= 10^6). Далее записана сама
 * последовательность: N целых чисел, по модулю не превышающих 30000.
 *
 * Формат выходных данных: В выходной файл выведите три искомых числа в любом
 * порядке. Если существует несколько различных троек чисел, дающих максимальное
 * произведение, то выведите любую из них.
*/

int compare(const void *, const void *);

int main() {
    FILE *f = fopen("input.txt", "r");
    if (f == NULL) {
        perror("Error: ");
        return BAD_FILE_OPEN
    }

    int amount_of_numbers = 0;
    fscanf(f, "%d", &amount_of_numbers);
    if (amount_of_numbers < 3) {
        puts("Error: Too law amount of numbers.");
        return TOO_LOW_NUMBERS
    }

    int current_number = 0;
    int *numbers = (int *)malloc(amount_of_numbers * sizeof(int));
    for (int i = 1; i <= amount_of_numbers; i++) {
        fscanf(f, "%d", &current_number);
        numbers[i - 1] = current_number;
    }
    qsort(numbers, amount_of_numbers, sizeof(int), compare);

    fclose(f);

    f = fopen("output.txt", "w+");
    int first_max_number = numbers[amount_of_numbers - 1], second_max_number = numbers[amount_of_numbers - 2],
        third_max_number = numbers[amount_of_numbers - 3], first_min_number = numbers[0],
        second_min_number = numbers[1];
    if (first_max_number * second_max_number * third_max_number >
        first_min_number * second_min_number * first_max_number) {
        fprintf(f, "%d %d %d", first_max_number, second_max_number, third_max_number);
    } else if (first_max_number * second_max_number * third_max_number <
               first_min_number * second_min_number * first_max_number) {
        fprintf(f, "%d %d %d", first_min_number, second_min_number, first_max_number);
    } else {
        int fortune = rand() % 10;
        if (fortune > 0) {
            fprintf(f, "%d %d %d", first_max_number, second_max_number, third_max_number);
        } else {
            fprintf(f, "%d %d %d", first_min_number, second_min_number, first_max_number);
        }
    }

    fclose(f);
    return 0;
}


int compare(const void *x, const void *y) {
    return ( *(int*)x - *(int*)y );
}
