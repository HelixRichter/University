#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main(int argc, char **argv) {
    SetConsoleOutputCP(CP_UTF8);

    if (argv[1] == NULL && argc == 1) {
        puts("Приветствую вас! Я - программа Косарева Алексея, студента группы К3-14Б.");
        puts("Используйте параметр -h или --help, чтобы получить подробную справку по программе.");
        puts("Запустите меня ещё раз через командную строку. Спасибо!");
    } else if (argv[2] == NULL && argc == 2) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            puts("Приветствую вас в подробном справочнике по этой программе.");
            puts("Моя задача - выполнять команды, введенные через параметры программы в командной строке. Вот вам несколько:");
            puts("  -h (--help) - выдает подробную справку по программе;");
            puts("  -t (--table) - выдает в табличном виде размеры всех простых типов языка;");
            puts("  -c (--calc) - арифметическое выражение, расчитывает простое арифметическое выражение вида: ЧИСЛО ОПЕРАЦИЯ ЧИСЛО;");
            puts("      -x (--hex) - выдаёт ответ из --calc в 16-ричном формате;");
            puts("      -o (--oct) - выдаёт ответ из --calc в 8-ричном формате.");
            puts("Запустите меня ещё раз через командную строку, но с использованием параметров, описанных выше. Спасибо!");
        } else if (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--table") == 0) {
            printf("Тип данных\t  Размер(байт)\n");
            printf("char\t\t\t%d\n", sizeof(char));
            printf("int\t\t\t%d\n", sizeof(int));
            printf("unsigned char\t\t%d\n", sizeof(unsigned char));
            printf("unsigned int\t\t%d\n", sizeof(unsigned int));
            printf("short int\t\t%d\n", sizeof(short int));
            printf("unsigned short\t\t%d\n", sizeof(unsigned short));
            printf("long int\t\t%d\n", sizeof(long int));
            printf("unsigned long int\t%d\n", sizeof(unsigned long int));
            printf("float\t\t\t%d\n", sizeof(float));
            printf("double\t\t\t%d\n", sizeof(double));
            printf("long double\t\t%d\n", sizeof(long double));
        } else
            printf("Я не поняла, что за параметр вы ввели. Может, ознакомившись со справкой через параметр -h или --help, вы снова попробуете?");
    } else if (argv[5] == NULL && argc == 5) {
        if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--calc") == 0) {
            if (strcmp(argv[3], "+") == 0) {
                printf("%f", atof(argv[2]) + atof(argv[4]));
            } else if (strcmp(argv[3], "-") == 0) {
                printf("%f", atof(argv[2]) - atof(argv[4]));
            } else if (strcmp(argv[3], "*") == 0) {
                printf("%f", atof(argv[2]) * atof(argv[4]));
            } else if (strcmp(argv[3], "/") == 0) {
                printf("%f", atof(argv[2]) / atof(argv[4]));
            } else
                printf("Я не поняла, что за параметр вы ввели. Может, ознакомившись со справкой через параметр -h или --help, вы снова попробуете?");
        } else
            printf("Я не поняла, что за параметр вы ввели. Может, ознакомившись со справкой через параметр -h или --help, вы снова попробуете?");
    } else if (argv[6] == NULL && argc == 6) {
        if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--calc") == 0) {
            if (strcmp(argv[2], "-x") == 0 || strcmp(argv[1], "--hex") == 0) {
                if (strcmp(argv[4], "+") == 0) {
                    printf("%fx", atof(argv[3]) + atof(argv[5]));
                } else if (strcmp(argv[4], "-") == 0) {
                    printf("%fx", atof(argv[3]) - atof(argv[5]));
                } else if (strcmp(argv[4], "*") == 0) {
                    printf("%fx", atof(argv[3]) * atof(argv[5]));
                } else if (strcmp(argv[4], "/") == 0) {
                    printf("%fx", atof(argv[3]) / atof(argv[5]));
                } else
                    printf("Я не поняла, что за параметр вы ввели. Может, ознакомившись со справкой через параметр -h или --help, вы снова попробуете?");
            } else if (strcmp(argv[2], "-o") == 0 || strcmp(argv[1], "--oct") == 0) {
                if (strcmp(argv[4], "+") == 0) {
                    printf("%fo", atof(argv[3]) + atof(argv[5]));
                } else if (strcmp(argv[4], "-") == 0) {
                    printf("%fo", atof(argv[3]) - atof(argv[5]));
                } else if (strcmp(argv[4], "*") == 0) {
                    printf("%fo", atof(argv[3]) * atof(argv[5]));
                } else if (strcmp(argv[4], "/") == 0) {
                    printf("%fo", atof(argv[3]) / atof(argv[5]));
                } else
                    printf("Я не поняла, что за параметр вы ввели. Может, ознакомившись со справкой через параметр -h или --help, вы снова попробуете?");
            } else
                printf("Я не поняла, что за параметр вы ввели. Может, ознакомившись со справкой через параметр -h или --help, вы снова попробуете?");
        } else
            printf("Я не поняла, что за параметр вы ввели. Может, ознакомившись со справкой через параметр -h или --help, вы снова попробуете?");
    } else
        printf("Я не поняла, что за параметр вы ввели. Может, ознакомившись со справкой через параметр -h или --help, вы снова попробуете?");

    return 0;
}