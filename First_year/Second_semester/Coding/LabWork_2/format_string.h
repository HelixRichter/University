#ifndef LABWORK_2_FORMAT_STRING_H
#define LABWORK_2_FORMAT_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TERMINATOR 1

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

Time *parse_time(const char *, const char *);
Date *parse_date(const char *, const char *);
timedate *parse_timedate(const char *, const char *);

#endif