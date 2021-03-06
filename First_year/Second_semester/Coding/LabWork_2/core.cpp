#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>

#include "core.h"

extern "C" {
#include "format_string.h"
}

using namespace std;

TimeDate::TimeDate() {
    duration.seconds = 0;
    duration.minutes = 0;
    duration.hours = 0;

    period.days = 0;
    period.months = 0;
    period.years = 0;

    value.clear();
}
[[maybe_unused]] TimeDate::TimeDate(const string &str_value) {
    value.assign(str_value);

    duration.seconds = 0;
    duration.minutes = 0;
    duration.hours = 0;

    period.days = 0;
    period.months = 0;
    period.years = 0;
}
[[maybe_unused]] TimeDate::TimeDate(const TimeDate &object) {
    duration.seconds = object.duration.seconds;
    duration.minutes = object.duration.minutes;
    duration.hours = object.duration.hours;

    period.days = object.period.days;
    period.months = object.period.months;
    period.years = object.period.years;

    value.assign(object.value);
}
[[maybe_unused]] TimeDate::TimeDate(TimeDate &&object) noexcept {
    duration.seconds = object.duration.seconds;
    duration.minutes = object.duration.minutes;
    duration.hours = object.duration.hours;

    period.days = object.period.days;
    period.months = object.period.months;
    period.years = object.period.years;

    value.assign(object.value);

    object.duration.seconds = 0;
    object.duration.minutes = 0;
    object.duration.hours = 0;

    object.period.days = 0;
    object.period.months = 0;
    object.period.years = 0;

    object.value.clear();
}

[[maybe_unused]] [[maybe_unused]] void TimeDate::get_current_time_and_date() {
    struct tm *result;
    time_t current_sec;

    time(&current_sec);
    result = localtime(&current_sec);

    duration.seconds = result -> tm_sec;
    duration.minutes = result -> tm_min;
    duration.hours = result   -> tm_hour;

    period.days = result      -> tm_mday;
    period.months = result    -> tm_mon +  1;
    period.years = result     -> tm_year + 1900;
}

[[maybe_unused]] void TimeDate::format_str_init() {
    ifstream cfg;
    cfg.open ("config", ios::in);

    if (!cfg) {
        cfg.close();
        cerr << "ERROR: Can't find or access CFG file." << endl;
        exit(1);
    }

    string inputed;
    while (getline(cfg, inputed)) {
        if (!inputed.compare(0, 6, "TIME {") and inputed.back() == '}') {
            string sub = inputed.substr(6, inputed.size() - 7);
            TIME = sub;
        } else if (!inputed.compare(0, 6, "DATE {") and inputed.back() == '}') {
            string sub = inputed.substr(6, inputed.size() - 7);
            DATE = sub;
        } else if (!inputed.compare(0, 6, "TIDA {") and inputed.back() == '}') {
            string sub = inputed.substr(6, inputed.size() - 7);
            TIMEDATE = sub;
        } else {
            cfg.close();
            cerr << "ERROR: CFG file is wrong." << endl;
            exit(1);
        }
    }
}

[[maybe_unused]] bool TimeDate::check_time() const {
    if (duration.seconds > 59) {
        return false;
    }

    if (duration.minutes > 59) {
        return false;
    }

    if (duration.hours > 23) {
        return false;
    }

    return true;
}

[[maybe_unused]] bool TimeDate::check_date() const {
    char months[12] = {31, 28, 31, 30,
                       31, 30, 31, 31,
                       30, 31, 30, 31};

    if (period.months > 12) {
        return false;
    }

    if (period.days > months[period.months - 1] && period.months != 0) {
        return false;
    }

    return true;
}

[[maybe_unused]] bool TimeDate::check_tida() const {
    if (duration.seconds > 59) {
        return false;
    }

    if (duration.minutes > 59) {
        return false;
    }

    if (duration.hours > 23) {
        return false;
    }

    char months[12] {31, 28, 31, 30,
                     31, 30, 31, 31,
                     30, 31, 30, 31};

    if (period.months > 12) {
        return false;
    }

    if (period.days > months[period.months + 1]) {
        return false;
    }

    return true;
}

[[maybe_unused]] [[nodiscard]] long long TimeDate::secs_to() const {
    long long result;
    long long inputed_time;
    time_t current_sec;

    time(&current_sec);

    char months[12] = {31, 28, 31, 30,
                       31, 30, 31, 31,
                       30, 31, 30, 31};

    int month_summ = 0;
    for (int i = 0; i < period.months; i++) {
        month_summ += int(months[i]);
    }

    inputed_time = (period.years - 1) * 31536000 + month_summ * 86400
                   + (period.days - 1) * 86400 + (duration.hours - 1) * 3600
                   + (duration.minutes - 1) * 60 + duration.seconds;    // 1 month (30.44 days) = 2629743 seconds;
    result = inputed_time - current_sec;

    if (result < 0) {
        return (result * -1);
    }

    return result;
}

[[maybe_unused]] [[nodiscard]] long long TimeDate::days_to() const {
    long long result;
    long long inputed_days;
    long long current_days;
    time_t current_sec;

    time(&current_sec);

    char months[12] = {31, 28, 31, 30,
                       31, 30, 31, 31,
                       30, 31, 30, 31};

    int month_summ = 0;
    for (int i = 0; i < period.months; i++) {
        month_summ += int(months[i]);
    }

    inputed_days = (period.years - 1) * 365 + month_summ + period.days;
    current_days = current_sec / 86400;
    result = inputed_days - current_days;

    if (result < 0) {
        return (result * -1);
    }

    return result;
}

[[maybe_unused]] void TimeDate::print() const {
    cout << duration.hours << ':' << duration.minutes << ':' << duration.seconds << endl;
    cout << period.days << '.' << period.months << '.' << period.years << endl;
}

[[maybe_unused]] void TimeDate::parsing_time(const string &inputed) {
    Time *tmp;
    tmp = parse_time(inputed.c_str(), TIME.c_str());

    duration.seconds = (int)(unsigned char)(tmp -> seconds);
    duration.minutes = (int)(unsigned char)(tmp -> minutes);
    duration.hours = (int)(unsigned char)(tmp -> hours);
}

[[maybe_unused]] void TimeDate::parsing_time() {
    Time *tmp;
    tmp = parse_time(value.c_str(), TIME.c_str());

    duration.seconds = (int)(unsigned char)(tmp -> seconds);
    duration.minutes = (int)(unsigned char)(tmp -> minutes);
    duration.hours = (int)(unsigned char)(tmp -> hours);
}

[[maybe_unused]] void TimeDate::parsing_date(const string &inputed) {
    Date *tmp;
    tmp = parse_date(inputed.c_str(), DATE.c_str());

    period.days = (int)(unsigned char)(tmp -> days);
    period.months = (int)(unsigned char)(tmp -> month);
    period.years = (int)(tmp -> years);
}

[[maybe_unused]] void TimeDate::parsing_date() {
    Date *tmp;
    tmp = parse_date(value.c_str(), DATE.c_str());

    period.days = (int)(unsigned char)(tmp -> days);
    period.months = (int)(unsigned char)(tmp -> month);
    period.years = (int)(tmp -> years);
}

[[maybe_unused]] void TimeDate::parsing_timedate(const string &inputed) {
    timedate *tmp;
    tmp = parse_timedate(inputed.c_str(), TIMEDATE.c_str());

    duration.seconds = (int)(unsigned char)(tmp -> duration -> seconds);
    duration.minutes = (int)(unsigned char)(tmp -> duration -> minutes);
    duration.hours = (int)(unsigned char)(tmp -> duration -> hours);

    period.days = (int)(unsigned char)(tmp -> period -> days);
    period.months = (int)(unsigned char)(tmp -> period -> month);
    period.years = (int)(tmp -> period -> years);
}

[[maybe_unused]] void TimeDate::parsing_timedate() {
    timedate *tmp;
    tmp = parse_timedate(value.c_str(), TIMEDATE.c_str());

    duration.seconds = (int)(unsigned char)(tmp -> duration -> seconds);
    duration.minutes = (int)(unsigned char)(tmp -> duration -> minutes);
    duration.hours = (int)(unsigned char)(tmp -> duration -> hours);

    period.days = (int)(unsigned char)(tmp -> period -> days);
    period.months = (int)(unsigned char)(tmp -> period -> month);
    period.years = (int)(tmp -> period -> years);
}

[[maybe_unused]] void TimeDate::set_time_sec(short seconds) {
    duration.seconds = seconds;
}

[[maybe_unused]] void TimeDate::set_time_min(short minutes) {
    duration.minutes = minutes;
}

[[maybe_unused]] void TimeDate::set_time_hour(short hours) {
    duration.hours = hours;
}

[[maybe_unused]] string TimeDate::format_str_time_get() {
    return TIME;
}

[[maybe_unused]] string TimeDate::format_str_date_get() {
    return DATE;
}

[[maybe_unused]] string TimeDate::format_str_timedate_get() {
    return TIMEDATE;
}

[[maybe_unused]] void TimeDate::add_time_sec(short seconds) {
    duration.seconds += seconds;
}

[[maybe_unused]] void TimeDate::add_time_min(short minutes) {
    duration.minutes += minutes;
}

[[maybe_unused]] void TimeDate::add_time_hour(short hours) {
    duration.hours += hours;
}


[[maybe_unused]] void TimeDate::add_time_day(short days) {
    period.days += days;
}

[[maybe_unused]] void TimeDate::add_time_month(short months) {
    period.months += months;
}

[[maybe_unused]] void TimeDate::add_time_year(short years) {
    period.years += years;
}


[[maybe_unused]] void TimeDate::set_time_day(short days) {
    period.days = days;
}

[[maybe_unused]] void TimeDate::set_time_month(short months) {
    period.months = months;
}

[[maybe_unused]] void TimeDate::set_time_year(int years) {
    period.years = years;
}


[[maybe_unused]] [[nodiscard]] int TimeDate::get_time_sec() const {
    return duration.seconds;
}

[[maybe_unused]] [[nodiscard]] int TimeDate::get_time_min() const {
    return duration.minutes;
}

[[maybe_unused]] [[nodiscard]] int TimeDate::get_time_hour() const {
    return duration.hours;
}


[[maybe_unused]] [[nodiscard]] int TimeDate::get_time_day() const {
    return period.days;
}

[[maybe_unused]] [[nodiscard]] int TimeDate::get_time_month() const {
    return period.months;
}

[[maybe_unused]] [[nodiscard]] int TimeDate::get_time_year() const {
    return period.years;
}


[[maybe_unused]] TimeDate::stime TimeDate::get_time() {
    return duration;
}

[[maybe_unused]] TimeDate::date TimeDate::get_date() {
    return period;
}
