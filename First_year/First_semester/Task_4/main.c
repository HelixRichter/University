#include <stdio.h>
#include <stdlib.h>

int NOD(int, int);

int main() {
    FILE *f;
    f = fopen("task.txt", "r");
    if (f == NULL) {
        puts("Oops, something went wrong...");
        exit(1);
    }

    int n1 = 0, n2 = 0;
    fscanf(f, "%d %d", &n1, &n2);
    fclose(f);

    int nod = NOD(abs(n1), abs(n2));
    printf("Answer is %d/%d.", n1 / nod, n2 / nod);

    return 0;
}

int NOD(int n1, int n2) {
    if (n1 == n2) {
        return n2;
    }
    return NOD(((n1 < n2) ? (n1) : (n2)), abs(n1 - n2));
}

// Задача 132: Сокращение дроби
// Реализован алгоритм Евклида.
// Он заключается в эффективном нахождении наибольшего общего делителя двух целых чисел.