#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "code.h"

int main(int argc, char **argv) {
    setlocale(LC_ALL, "Rus");

    if (argv[1] == NULL && argc == 1) {
        char path[256];
        puts("Hello there! Please, enter the absolute path to the .txt file (You can also specify a relative one): ");
        gets(path);

        allletcount(path);
    } else if (argc == 2 && argv[2] == NULL) {
        if (strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "--word") == 0) {
            char path[256];
            puts("Hello there! Please, enter the absolute path to the .txt file (You can also specify a relative one): ");
            gets(path);

            wcount(path);
        } else if (strcmp(argv[1], "--en") == 0) {
            char path[256];
            puts("Hello there! Please, enter the absolute path to the .txt file (You can also specify a relative one): ");
            gets(path);

            engletcount(path);
        } else if (strcmp(argv[1], "--ru") == 0) {
            char path[256];
            puts("Hello there! Please, enter the absolute path to the .txt file (You can also specify a relative one): ");
            gets(path);

            rusletcount(path);
        } else if (strcmp(argv[1], "--all") == 0) {
            char path[256];
            puts("Hello there! Please, enter the absolute path to the .txt file (You can also specify a relative one): ");
            gets(path);

            allletcount(path);
        }
    } else if (argc == 3 && argv[3] == NULL) {
        if (strcmp(argv[1], "--en") == 0 && strcmp(argv[2], "--ir") == 0) {
            char path[256];
            puts("Hello there! Please, enter the absolute path to the .txt file (You can also specify a relative one): ");
            gets(path);

            engallcount(path);
        } else if (strcmp(argv[1], "--ru") == 0 && strcmp(argv[2], "--ir") == 0) {
            char path[256];
            puts("Hello there! Please, enter the absolute path to the .txt file (You can also specify a relative one): ");
            gets(path);

            rusallcount(path);
        }
    }

    return 0;
}