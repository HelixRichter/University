#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

#include "format_string.h"
#include <stdlib.h>
#include <string.h>

char *FS_TIME;
char *FS_DATE;
char *FS_TIMEDATE;

void init_fs_lib(void) {
    set_fs_time("%h:%m:%s");
    printf("1\n");
    set_fs_date("%D.%M.%Y");
    printf("2\n");
    set_fs_time_date("%h:%m:%s%D.%M.%Y");
    printf("3\n");
}

void set_fs_time(const char *fs) {
    if (!check_fs_time(fs)) {
        printf("ACHTUNG!!!");
        return;
    }

    FS_TIME = (char *)malloc((strlen(fs) + TERMINATOR) * sizeof(char));
    strcpy(FS_TIME, fs);
}

void set_fs_date(const char *fs) {
    if (!check_fs_date(fs)) {
        return;
    }

    FS_DATE = (char *)malloc((strlen(fs) + TERMINATOR) * sizeof(char));
    strcpy(FS_DATE, fs);
}

void set_fs_time_date(const char *fs) {
    if (!check_fs_timedate(fs)) {
        printf("ACHTUNG\n");
        return;
    }

    FS_TIMEDATE = (char *)malloc((strlen(fs) + TERMINATOR) * sizeof(char));
    strcpy(FS_TIMEDATE, fs);
}

char *get_fs_time(void) {
    char *newline = (char *)malloc((strlen(FS_TIME) + TERMINATOR) * sizeof(char));
    strcpy(newline, FS_TIME);

    return newline;
}

char *get_fs_date(void) {
    char *newline = (char *)malloc((strlen(FS_DATE) + TERMINATOR) * sizeof(char));
    strcpy(newline, FS_DATE);

    return newline;
}

char *get_fs_timedate(void) {
    char *newline = (char *)malloc((strlen(FS_TIMEDATE) + TERMINATOR) * sizeof(char));
    strcpy(newline, FS_TIMEDATE);

    return newline;
}

int check_fs_time(const char *fs) {
    char F_SEC = 0;
    char F_MIN = 0;
    char F_HRS = 0;
    char F_ERR = 0;

    const char *car = fs;
    while (car && *car != '\0') {
        if (*car == '%') {
            car++;

            if (!car) {
                break;
            } else {
                switch (*car) {
                    case 's':
                        if (F_SEC) {
                            F_ERR = 1;
                        }

                        F_SEC = 1;
                        break;
                    case 'm':
                        if (F_MIN) {
                            F_ERR = 1;
                        }

                        F_MIN = 1;
                        break;
                    case 'h':
                        if (F_HRS) {
                            F_ERR = 1;
                        }

                        F_HRS = 1;
                        break;
                    case '%':
                        break;
                    default:
                        F_ERR = 1;
                }
            }
        }
        car++;
    }

    return (F_SEC & F_MIN & F_HRS & !(F_ERR));
}

int check_fs_date(const char *fs) {
    char F_YER = 0;
    char F_MON = 0;
    char F_DAY = 0;
    char F_ERR = 0;

    const char *car = fs;
    while (car && *car != '\0') {
        if (*car == '%') {
            car++;

            if (!car) {
                break;
            } else {
                switch (*car) {
                    case 'Y':
                        if (F_YER) {
                            F_ERR = 1;
                        }

                        F_YER = 1;
                        break;
                    case 'M':
                        if (F_MON) {
                            F_ERR = 1;
                        }

                        F_MON = 1;
                        break;
                    case 'D':
                        if (F_DAY) {
                            F_ERR = 1;
                        }

                        F_DAY = 1;
                        break;
                    case '%':
                        break;
                    default:
                        F_ERR = 1;
                }
            }
        }
        car++;
    }

    return (F_YER & F_MON & F_DAY & !(F_ERR));
}

int check_fs_timedate(const char *fs) {
    char F_YER = 0;
    char F_MON = 0;
    char F_DAY = 0;
    char F_SEC = 0;
    char F_MIN = 0;
    char F_HRS = 0;
    char F_ERR = 0;

    const char *car = fs;
    while (car) {
        if (*car == '\0') {
            break;
        }

        if (*car == '%') {
            car++;

            if (!car || *car == '\0') {
                F_ERR == 1;

                break;
            } else {
                switch (*car) {
                    case 'Y':
                        if (F_YER) {
                            F_ERR = 1;
                        }

                        F_YER = 1;
                        break;
                    case 'M':
                        if (F_MON) {
                            F_ERR = 1;
                        }

                        F_MON = 1;
                        break;
                    case 'D':
                        if (F_DAY) {
                            F_ERR = 1;
                        }

                        F_DAY = 1;
                        break;
                    case 's':
                        if (F_SEC) {
                            F_ERR = 1;
                        }

                        F_SEC = 1;
                        break;
                    case 'm':
                        if (F_MIN) {
                            F_ERR = 1;
                        }

                        F_MIN = 1;
                        break;
                    case 'h':
                        if (F_HRS) {
                            F_ERR = 1;
                        }

                        F_HRS = 1;
                        break;
                    case '%':
                        break;
                    default:
                        F_ERR = 1;
                }
            }
        }
        car++;
    }

    return (F_SEC & F_MIN & F_HRS & F_YER & F_MON & F_DAY & !(F_ERR));
}

Time *parse_time(const char *str) {
    Time *parsed = (Time *)malloc(sizeof(Time));
    char parse_entity;
    const char *car_str = str;
    char *car_fs = FS_TIME;

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

Date *parse_date(const char *str) {
    Date *parsed = (Date *)malloc(sizeof(Date));
    int parse_entity;
    const char *car_str = str;
    char *car_fs = FS_DATE;

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

timedate *parse_timedate(const char *str) {
    timedate *parsed = (timedate *)malloc(sizeof(timedate));
    parsed -> duration = (Time *)malloc(sizeof(Time));
    parsed -> period = (Date *)malloc(sizeof(Date));

    int parse_entity;
    const char *car_str = str;
    char *car_fs = FS_TIMEDATE;

    while (car_str && car_fs) {
        if (*car_str == '\0' && *car_fs == '\0') {
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

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9) {
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

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9) {
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

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9) {
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

                        if (symbol_1 < 0 || symbol_1 > 9 || symbol_2 < 0 || symbol_2 > 9) {
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