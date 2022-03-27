#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TERMINATOR 1
#define TIME_DEFAULT "%h:%m:%s"
#define DATE_DEFAULT "%D.%M.%Y"
#define TIMEDATE_DEFAULT "%h:%m:%s %D.%M.%Y"

struct time {
	char hours;
	char minutes;
	char seconds;
};

typedef struct time Time;

struct date {
	int years;
	char month;
	char days;
};

typedef struct date Date;

struct timedate {
	struct time;
	struct date;
};

typedef struct timedate TimeDate;

void init_fs_lib(void);

void set_fs_time(char*);
void set_fs_date(char*);
void set_fs_timedate(char*);

char *get_fs_time(void);
char *get_fs_date(void);
char *get_fs_timedate(void);

int check_fs_time(char*);
int check_fs_date(char*);
int check_fs_timedate(char*);

Time *parse_time(char*);
Date *parse_date(char*);
TimeDate *parse_timedate(char*);
