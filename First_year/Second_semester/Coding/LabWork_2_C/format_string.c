#include "format_string.h"
#include <stdlib.h>
#include <string.h>

char *FS_TIME;
char *FS_DATE;
char *FS_TIMEDATE;

void init_fs_lib(void) {
    set_fs_time("%h:%m:%s");
    set_fs_date("%D.%M.%Y");
    set_fs_timedate("%h:%m:%s %D.%M.%Y");
}

void set_fs_time(char *fs) {
    FS_TIME = (char*)malloc((strlen(fs) + TERMINATOR) * sizeof(char));
    strcpy(FS_TIME, fs);
}

void set_fs_date(char *fs) {
    FS_DATE = (char*)malloc((strlen(fs) + TERMINATOR) * sizeof(char));
    strcpy(FS_DATE, fs);
}

void set_fs_time_date(char *fs) {
    FS_TIMEDATE = (char*)malloc((strlen(fs) + TERMINATOR) * sizeof(char));
    strcpy(FS_TIMEDATE, fs);
}

char *get_fs_time(void) {
    char *newline = (char*)malloc((strlen(FS_TIME) + TERMINATOR) *
                                  sizeof(char));
    strcpy(newline, FS_TIME);
    return newline;
}

char *get_fs_date(void) {
    char *newline = (char*)malloc((strlen(FS_DATE) + TERMINATOR) *
                                  sizeof(char));
    strcpy(newline, FS_DATE);
    return newline;
}

char *get_fs_timedate(void) {
    char *newline = (char*)malloc((strlen(FS_TIMEDATE) + TERMINATOR) *
                                  sizeof(char));
    strcpy(newline, FS_TIMEDATE);
    return newline;
}

int check_fs_time(char *fs) {
    char F_SEC = 0;
    char F_MIN = 0;
    char F_HRS = 0;
    char F_ERR = 0;

    char *car = fs;
    while (car) {
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

int check_fs_date(char *fs) {
    char F_YER = 0;
    char F_MON = 0;
    char F_DAY = 0;
    char F_ERR = 0;

    char *car = fs;
    while (car) {
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

int check_fs_timedate(char *fs) {
    char F_YER = 0;
    char F_MON = 0;
    char F_DAY = 0;
    char F_SEC = 0;
    char F_MIN = 0;
    char F_HRS = 0;
    char F_ERR = 0;

    char *car = fs;
    while (car) {
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

// <WORK IN PROGRESS>

Time *parse_time(char *str) {
    Time *parsed = (Time *)malloc(sizeof(Time));
    int parse_entity;
    char *car_str = str;
    char *car_fs = FS_TIME;

    while (car_str && car_fs) {
        if (car_fs != '%') {
            if (car_str != car_fs) {

                parsed -> seconds = 0;
                parsed -> minutes = 0;
                parsed -> hours = 0;

                break;
            }
        } else {
            car_fs++;

            switch(*car_fs) {
                case '%':
                    if (car_str != car_fs) {
                        // ERR = 1!!!
                    }

                    break;

                case 'h' : {
                    if ((car_str + 1) && (car_str + 2)) {
                        char symbol_1 = *(car_str++) - '0';
                        char symbol_2 = *(car_str) - '0';

                        // ARE THEY NUMBERS?

                        parse_entity = symbol_1 * 10 + symbol_2;
                        parsed -> hours = parse_entity;
                        parse_entity = 0;
                    } else {
                        parsed -> seconds = 0;
                        parsed -> minutes = 0;
                        parsed -> hours = 0;

                        break;
                    }
                }

                case 'm' : {
                    // ANALOGY
                }

                case 's' : {
                    // ANALOGY
                }
            }
        }

        car_str++;
        car_fs++;
    }

    return parsed;
}

Date *parse_date(char *str) {
}

TimeDate *parse_timedate(char *str) {
}
