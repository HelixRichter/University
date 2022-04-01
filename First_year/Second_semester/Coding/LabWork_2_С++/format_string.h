#ifndef LABWORK_2_FORMAT_STRING_H
#define LABWORK_2_FORMAT_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TERMINATOR 1
#define TIME_DEFAULT "%h:%m:%s"
#define DATE_DEFAULT "%D.%M.%Y"
#define TIMEDATE_DEFAULT "%h:%m:%s %D.%M.%Y"

typedef struct libtime {
    char hours;
    char minutes;
    char seconds;
} Time;

typedef struct libdate {
    int years;
    char month;
    char days;
} Date;

typedef struct libtimedate {
    Time *duration;
    Date *period;
} timedate;

void init_fs_lib(void);

void set_fs_time(const char *);
void set_fs_date(const char *);
void set_fs_time_date(const char *);

char *get_fs_time(void);
char *get_fs_date(void);
char *get_fs_timedate(void);

int check_fs_time(const char *);
int check_fs_date(const char *);
int check_fs_timedate(const char *);

Time *parse_time(const char *);
Date *parse_date(const char *);
timedate *parse_timedate(const char *);

#endif