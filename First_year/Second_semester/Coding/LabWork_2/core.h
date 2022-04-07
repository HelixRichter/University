#ifndef LABWORK_2_CORE_H
#define LABWORK_2_CORE_H

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class TimeDate {
private:
    struct stime {
        int seconds;
        int minutes;
        int hours;
    };
    struct date {
        int days;
        int months;
        int years;
    };

    string value;

    string TIME;
    string DATE;
    string TIMEDATE;

    stime duration {};
    date period {};

public:
    [[maybe_unused]] TimeDate();
    [[maybe_unused]] explicit TimeDate(const string&);
    [[maybe_unused]] TimeDate(const TimeDate&);
    [[maybe_unused]] TimeDate(TimeDate&&) noexcept;

    [[maybe_unused]] inline static size_t type_string_len(const string& inputed_string) {
        const char *c_value = inputed_string.c_str();
        return strlen(c_value);
    }

    [[maybe_unused]] void format_str_init();
    [[maybe_unused]] string format_str_time_get();
    [[maybe_unused]] string format_str_date_get();
    [[maybe_unused]] string format_str_timedate_get();

    [[maybe_unused]] void parsing_time(const string &);
    [[maybe_unused]] void parsing_date(const string &);
    [[maybe_unused]] void parsing_timedate(const string &);

    [[maybe_unused]] void parsing_time();
    [[maybe_unused]] void parsing_date();
    [[maybe_unused]] void parsing_timedate();

    [[maybe_unused]] void print() const;
    [[maybe_unused]] void get_current_time_and_date();

    [[maybe_unused]] [[nodiscard]] bool check_time() const;
    [[maybe_unused]] [[nodiscard]] bool check_date() const;
    [[maybe_unused]] [[nodiscard]] bool check_tida() const;

    [[maybe_unused]] [[nodiscard]] long long secs_to() const;
    [[maybe_unused]] [[nodiscard]] long long days_to() const;

    [[maybe_unused]] void set_time_sec(short);
    [[maybe_unused]] void set_time_min(short);
    [[maybe_unused]] void set_time_hour(short);

    [[maybe_unused]] void set_time_day(short);
    [[maybe_unused]] void set_time_month(short);
    [[maybe_unused]] void set_time_year(int);

    [[maybe_unused]] void add_time_sec(short);
    [[maybe_unused]] void add_time_min(short);
    [[maybe_unused]] void add_time_hour(short);

    [[maybe_unused]] void add_time_day(short);
    [[maybe_unused]] void add_time_month(short);
    [[maybe_unused]] void add_time_year(short);

    [[maybe_unused]] [[nodiscard]] int get_time_sec() const;
    [[maybe_unused]] [[nodiscard]] int get_time_min() const;
    [[maybe_unused]] [[nodiscard]] int get_time_hour() const;

    [[maybe_unused]] [[nodiscard]] int get_time_day() const;
    [[maybe_unused]] [[nodiscard]] int get_time_month() const;
    [[maybe_unused]] [[nodiscard]] int get_time_year() const;

    [[maybe_unused]] stime get_time();
    [[maybe_unused]] date get_date();
};

#endif
