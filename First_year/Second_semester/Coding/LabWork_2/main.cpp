#include <iostream>
#include <algorithm>
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


    [[maybe_unused]] inline static size_t type_string_len(string inputed_string) {
        const char *c_value = inputed_string.c_str();
        return strlen(c_value);
    }

    [[maybe_unused]] void dismemberment() {
        short parameter = 0; // 0 - hour/day, 1 - min/month, 2 - sec/year

        string tmp;
        tmp.clear();

        for (size_t i = 0; i <= type_string_len(value); i++) {
            if (value[i] != '.' and value[i] != ':' and value[i] != '\0') {
                tmp += value[i];
            } else {
                if (parameter == 0) {
                    if (value[i] == ':') {
                        duration.hours = stoi(tmp);
                    } else {
                        period.days = stoi(tmp);
                    }

                    tmp.clear();
                    parameter++;
                } else if (parameter == 1) {
                    if (value[i] == ':') {
                        duration.minutes = stoi(tmp);
                    } else {
                        period.months = stoi(tmp);
                    }

                    tmp.clear();
                    parameter++;
                } else {
                    if (value[i] == ':') {
                        duration.seconds = stoi(tmp);
                    } else {
                        period.years = stoi(tmp);
                    }

                    tmp.clear();
                }
            }
        }
    }

   [[maybe_unused]] static bool str_check(string inputed_string) {
       bool err = false;

       if (count(inputed_string.begin(), inputed_string.end(), ':') != 0
           and count(inputed_string.begin(), inputed_string.end(), '.') != 0) {
               cout << "Incorrect dot/colon input!" << endl;
               err = true;
           }

       for (size_t i = 0; i < type_string_len(inputed_string); i++) {
           if (inputed_string[i] < 48 or inputed_string[i] > 57) {
               cout << "Incorrect numbers input!" << endl;
               err = true;
           }
       }

       if (count(inputed_string.begin(), inputed_string.end(), '.') != 2
           or count(inputed_string.begin(), inputed_string.end(), ':') != 2) {
               cout << "Incorrect dot/colon number!" << endl;
               err = true;
           }

       return err;
   }

    [[maybe_unused]] static bool date_check(date inputed_date) {
        bool err = false;
        char month[12] = {0};

        month[0] = 31;
        month[1] = 28;
        month[2] = 31;
        month[3] = 30;
        month[4] = 31;
        month[5] = 30;
        month[6] = 31;
        month[7] = 31;
        month[8] = 30;
        month[9] = 31;
        month[10] = 30;
        month[11] = 31;

        if (inputed_date.months <= 0 or inputed_date.days > 12) {
            cout << "Incorrect month input!" << endl;
            err = true;
        } else {
            if (short(month[inputed_date.months - 1]) < inputed_date.days) {
                cout << "Incorrect maximum days in inputed month!" << endl;
                err = true;
            }
        }

        if (inputed_date.days <= 0 or inputed_date.days > 31) {
            cout << "Incorrect day input!" << endl;
            err = true;
        }



        if (inputed_date.years <= 0) {
            cout << "Incorrect year input!" << endl;
            err = true;
        }

        return err;
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
