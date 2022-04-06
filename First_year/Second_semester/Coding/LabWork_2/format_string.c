#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

#include "format_string.h"
#include <stdlib.h>
#include <string.h>

char *FS_TIME;
char *FS_DATE;
char *FS_TIMEDATE;

Time *parse_time(const char *str, const char *format_string) {
    Time *parsed = (Time *) malloc(sizeof(Time));
    char parse_entity;
    const char *car_str = str;
    char *car_fs = format_string;

    while (car_str && car_fs) {
        if (*car_str == '\0' && *car_fs == '\0') {
            break;
        }

        if (*car_fs != '%') {
            if (*car_str != *car_fs) {

                parsed -> seconds = 0;
                parsed -> minutes = 0;
                parsed -> hours = 0;

                break;
            }
        } else {
            car_fs++;

            switch(*car_fs) {
                case '%':
                    if (*car_str != *car_fs) {
                        parsed -> seconds = 0;
                        parsed -> minutes = 0;
                        parsed -> hours = 0;
                    }

                    break;

                case 'h' : {
                    if ((car_str) && (car_str + 1)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9) {
                            parsed -> hours = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 10 + symbol_2;
                        parsed -> hours = parse_entity;
                    } else {
                        parsed -> hours = 0;

                        break;
                    }

                    break;
                }

                case 'm' : {
                    if ((car_str) && (car_str + 1)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9) {
                            parsed -> minutes = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 10 + symbol_2;
                        parsed -> minutes = parse_entity;
                    } else {
                        parsed -> minutes = 0;

                        break;
                    }

                    break;
                }

                case 's' : {
                    if ((car_str) && (car_str + 1)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9) {
                            parsed -> seconds = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 10 + symbol_2;
                        parsed -> seconds = parse_entity;
                    } else {
                        parsed -> seconds = 0;

                        break;
                    }

                    break;
                }

                default:
                    exit(1);
            }
        }

        car_str++;
        car_fs++;
    }

    return parsed;
}

Date *parse_date(const char *str, const char *format_string) {
    Date *parsed = (Date *)malloc(sizeof(Date));
    int parse_entity;
    const char *car_str = str;
    char *car_fs = format_string;

    while (car_str && car_fs) {
        if (*car_str == '\0' && *car_fs == '\0') {
            break;
        }

        if (*car_fs != '%') {
            if (*car_str != *car_fs) {

                parsed -> days = 0;
                parsed -> month = 0;
                parsed -> years = 0;

                break;
            }
        } else {
            car_fs++;

            switch(*car_fs) {
                case '%':
                    if (*car_str != *car_fs) {

                        parsed -> days = 0;
                        parsed -> month = 0;
                        parsed -> years = 0;
                    }

                    break;

                case 'D' : {
                    if ((car_str) && (car_str + 1)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9) {
                            parsed -> days = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 10 + symbol_2;
                        parsed -> days = parse_entity;
                    } else {
                        parsed -> days = 0;

                        break;
                    }

                    break;
                }

                case 'M' : {
                    if ((car_str) && (car_str + 1)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9) {
                            parsed -> month = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 10 + symbol_2;
                        parsed -> month = parse_entity;
                    } else {
                        parsed -> month = 0;

                        break;
                    }

                    break;
                }

                case 'Y' : {
                    if ((car_str) && (car_str + 1) && (car_str + 2) && (car_str + 3)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str++) - '0';
                        char symbol_3 = *(car_str++) - '0';
                        char symbol_4 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9 ||
                            symbol_3 < 0 || symbol_3 > 9 || symbol_4 < 0 || symbol_4 > 9) {
                            parsed -> years = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 1000 + symbol_2 * 100 + symbol_3 * 10 + symbol_4;
                        parsed -> years = parse_entity;
                    } else {
                        parsed -> years = 0;

                        break;
                    }

                    break;
                }

                default:
                    exit(1);
            }
        }

        car_str++;
        car_fs++;
    }

    return parsed;
}

timedate *parse_timedate(const char *str, const char *format_string) {
    timedate *parsed = (timedate *)malloc(sizeof(timedate));
    parsed -> duration = (Time *)malloc(sizeof(Time));
    parsed -> period = (Date *)malloc(sizeof(Date));

    int parse_entity;
    const char *car_str = str;
    char *car_fs = format_string;

    while ((car_str && car_fs) && (*car_str != '\0' && *car_fs != '\0')) {
        printf("%d %d\n", *car_str, *car_fs);
        if (*car_str == ' ' && *car_fs == ' ') {
            car_str++;
            car_fs++;

            continue;
        } else if (*car_str == ' ' ^ *car_fs == ' ') {
            break;
        }

        if (*car_fs != '%') {
            if (*car_str != *car_fs) {

                parsed -> duration -> seconds = 0;
                parsed -> duration -> minutes = 0;
                parsed -> duration -> hours = 0;

                parsed -> period -> days = 0;
                parsed -> period -> month = 0;
                parsed -> period -> years = 0;

                break;
            }
        } else {
            car_fs++;

            switch(*car_fs) {
                case '%':
                    if (*car_str != *car_fs) {

                        parsed -> duration -> seconds = 0;
                        parsed -> duration -> minutes = 0;
                        parsed -> duration -> hours = 0;

                        parsed -> period -> days = 0;
                        parsed -> period -> month = 0;
                        parsed -> period -> years = 0;

                    }

                    break;

                case 'h' : {
                    if ((car_str) && (car_str + 1)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 2 || symbol_2 < 0 || symbol_2 > 9) {
                            parsed -> duration -> hours = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 10 + symbol_2;
                        parsed -> duration -> hours = parse_entity;
                    } else {
                        parsed -> duration -> hours = 0;

                        break;
                    }

                    break;
                }

                case 'm' : {
                    if ((car_str) && (car_str + 1)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 5 || symbol_2 < 0 || symbol_2 > 9) {
                            parsed -> duration -> minutes = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 10 + symbol_2;
                        parsed -> duration -> minutes = parse_entity;
                    } else {
                        parsed -> duration -> minutes = 0;

                        break;
                    }

                    break;
                }

                case 's' : {
                    if ((car_str) && (car_str + 1)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 5 || symbol_2 < 0 || symbol_2 > 9) {
                            parsed -> duration -> seconds = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 10 + symbol_2;
                        parsed -> duration -> seconds = parse_entity;
                    } else {
                        parsed -> duration -> seconds = 0;

                        break;
                    }

                    break;
                }

                case 'D' : {
                    if ((car_str) && (car_str + 1)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9) {
                            parsed -> period -> days = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 10 + symbol_2;
                        parsed -> period -> days = parse_entity;
                    } else {
                        parsed -> period -> days = 0;

                        break;
                    }

                    break;
                }

                case 'M' : {
                    if ((car_str) && (car_str + 1)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 1 || symbol_2 < 0 || symbol_2 > 9) {
                            parsed -> period -> month = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 10 + symbol_2;
                        parsed -> period -> month = parse_entity;
                    } else {
                        parsed -> period -> month = 0;

                        break;
                    }

                    break;
                }

                case 'Y' : {
                    if ((car_str) && (car_str + 1) && (car_str + 2) && (car_str + 3)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str++) - '0';
                        char symbol_3 = *(car_str++) - '0';
                        char symbol_4 = *(car_str) - '0';

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9 ||
                            symbol_3 < 0 || symbol_3 > 9 || symbol_4 < 0 || symbol_4 > 9) {
                            parsed -> period -> years = 0;

                            break;
                        }

                        parse_entity = symbol_1 * 1000 + symbol_2 * 100 + symbol_3 * 10 + symbol_4;
                        parsed -> period -> years = parse_entity;
                    } else {
                        parsed -> period -> years = 0;

                        break;
                    }

                    break;
                }
            }
        }

        car_str++;
        car_fs++;
    }

    return parsed;
}