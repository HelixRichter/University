#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class TimeDate {

private:
    struct time {
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
    time duration {};
    date period {};

public:
    TimeDate() {
        duration.seconds = 0;
        duration.minutes = 0;
        duration.hours = 0;

        period.days = 0;
        period.months = 0;
        period.years = 0;

        value.clear();
    };

    [[maybe_unused]] explicit TimeDate(const string& str_value) {
        value.assign(str_value);
    };

    [[maybe_unused]] TimeDate(const TimeDate & object) { // Doesn't work as it should.
        duration.seconds = object.duration.seconds;
        duration.minutes = object.duration.minutes;
        duration.hours = object.duration.hours;

        period.days = object.period.days;
        period.months = object.period.months;
        period.years = object.period.years;
    };                                                   //


    [[maybe_unused]] inline size_t str_len() {
        const char *c_value = value.c_str();
        return strlen(c_value);
    }

    [[maybe_unused]] void dismemberment() {
        short dots = 0;
        short colons = 0;
        short parameter = 0; // 0 - hour/day, 1 - min/month, 2 - sec/year

        string tmp;
        tmp.clear();

        for (size_t i = 0; i <= str_len(); i++) {
            if (dots < 3 and colons < 3) {
                if (value[i] != '.' and value[i] != ':' and value[i] != '\0') {
                    tmp += value[i];
                } else {
                    if (parameter == 0) {
                        if (value[i] == ':') {
                            duration.hours = stoi(tmp);
                            dots++;
                        } else {
                            period.days = stoi(tmp);
                            colons++;
                        }

                        tmp.clear();
                        parameter++;
                    } else if (parameter == 1) {
                        if (value[i] == ':') {
                            duration.minutes = stoi(tmp);
                            dots++;
                        } else {
                            period.months = stoi(tmp);
                            colons++;
                        }

                        tmp.clear();
                        parameter++;
                    } else {
                        if (dots != 0 and colons == 0) {
                            duration.seconds = stoi(tmp);
                        } else if (colons != 0 and dots == 0) {
                            period.years = stoi(tmp);
                        }

                        tmp.clear();
                    }
                }
            }
        }
    }

    [[maybe_unused]] static void date_check() {

    }

    [[maybe_unused]] inline void print(bool is_time) const {
        if (is_time) {
            cout << duration.hours << ':' << duration.minutes << ':' << duration.seconds << endl;
        } else {
            cout << period.days << '.' << period.months << '.' << period.years << endl;
        }
    }


    [[maybe_unused]] inline void set_time_sec(short seconds) {
        duration.seconds = seconds;
    }

    [[maybe_unused]] inline void set_time_min(short minutes) {
        duration.minutes = minutes;
    }

    [[maybe_unused]] inline void set_time_hour(short hours) {
        duration.hours = hours;
    }


    [[maybe_unused]] inline void set_time_day(short days) {
        period.days = days;
    }

    [[maybe_unused]] inline void set_time_month(short months) {
        period.months = months;
    }

    [[maybe_unused]] inline void set_time_year(int years) {
        period.years = years;
    }


    [[maybe_unused]] [[nodiscard]] inline int get_time_sec() const {
        return duration.seconds;
    }

    [[maybe_unused]] [[nodiscard]] inline int get_time_min() const {
        return duration.minutes;
    }

    [[maybe_unused]] [[nodiscard]] inline int get_time_hour() const {
        return duration.hours;
    }


    [[maybe_unused]] [[nodiscard]] inline int get_time_day() const {
        return period.days;
    }

    [[maybe_unused]] [[nodiscard]] inline int get_time_month() const {
        return period.months;
    }

    [[maybe_unused]] [[nodiscard]] inline int get_time_year() const {
        return period.years;
    }


    [[maybe_unused]] inline time get_time() {
        return duration;
    }

    [[maybe_unused]] inline date get_date() {
        return period;
    }

};

int main() {
    TimeDate obj {"12.65.23"};
    obj.dismemberment();
    obj.print(false);

    return 0;
}
