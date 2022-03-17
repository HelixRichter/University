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

    [[maybe_unused]] TimeDate(const TimeDate& object) {
        duration.seconds = object.duration.seconds;
        duration.minutes = object.duration.minutes;
        duration.hours = object.duration.hours;

        period.days = object.period.days;
        period.months = object.period.months;
        period.years = object.period.years;

        value.assign(object.value);
    };


    [[maybe_unused]] inline static size_t type_string_len(const string& inputed_string) {
        const char *c_value = inputed_string.c_str();
        return strlen(c_value);
    }

    [[maybe_unused]] void dismemberment(bool str_status) {
        if (str_status) {
            cout << "ERR: I can't handle incorrect string!" << endl;
            return;
        }

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
           cout << "ERR: dots and colons can't be together!" << endl;
           err = true;
       } else if (count(inputed_string.begin(), inputed_string.end(), '.') != 2
                  and count(inputed_string.begin(), inputed_string.end(), ':') == 0) {
           cout << "ERR: Incorrect dot number!" << endl;
           err = true;
       } else if (count(inputed_string.begin(), inputed_string.end(), '.') == 0
                  and count(inputed_string.begin(), inputed_string.end(), ':') != 2) {
           cout << "ERR: Incorrect colon number!" << endl;
           err = true;
       }

       for (size_t i = 0; i < type_string_len(inputed_string); i++) {
           if (inputed_string[i] < '0' or inputed_string[i] > '9') {
               if (inputed_string[i] == '.' or inputed_string[i] == ':') {
                   continue;
               } else {
                   cout << "ERR: incorrect number/symbol input: " << inputed_string[i] << endl;
                   err = true;

                   break;
               }
           }
       }

       return err;
   }

    [[maybe_unused]] static bool date_check(date inputed_date) {
        bool err = false;

        if (inputed_date.months <= 0 or inputed_date.days > 12) {
            cout << "ERR: Incorrect month input!" << endl;
            err = true;
        } else {
            char month[12] = {31, 28, 31, 30, 31, 30, 31,
                              31, 30, 31, 30,31};
            if (short(month[inputed_date.months - 1]) < inputed_date.days) {
                cout << "ERR: Incorrect maximum days in inputed month!" << endl;
                err = true;
            }
        }

        if (inputed_date.years <= 0) {
            cout << "ERR: Incorrect year input!" << endl;
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
    string input_value = "12.65.23";
    TimeDate obj1 {input_value};
    obj1.dismemberment(false);
    TimeDate obj2 = obj1;

    cout << obj2.get_time_day() << endl;

    return 0;
}
