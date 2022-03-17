#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"

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
    stime duration {};
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

    [[maybe_unused]] TimeDate(TimeDate&& object) noexcept {
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

    [[maybe_unused]] inline static size_t type_string_len(const string& inputed_string) {
        const char *c_value = inputed_string.c_str();
        return strlen(c_value);
    }

    [[maybe_unused]] void dismemberment() {
        bool string_status = str_check(value);

        if (string_status) {
            cout << "ERR: I will not handle incorrect input!" << endl;
            return;
        }

        short parameter = 0; // 0 - hour/day, 1 - min/month, 2 - sec/year
        short dots = 0;
        short colons = 0;
        char firstly = 0; // -1 - time, 1 - date
        char already_entered = 0; // -1 - time, 1 - date

        string tmp;
        tmp.clear();

        for (size_t i = 0; i <= type_string_len(value); i++) {
            if (value[i] != '.' and value[i] != ':' and value[i] != '\0' and value[i] != ' ') {
                tmp += value[i];
            } else {
                if (parameter == 0) {
                    if (value[i] == ':') {
                        duration.hours = stoi(tmp);
                        colons++;

                        if (firstly == 0) {
                            firstly = -1;
                        }
//                        cout << "WE GOT PARAMETER 0, VALUE ':' FIRSTLY IS " << short(firstly) << ", AND TMP IS " << tmp << endl;
                    } else {
                        period.days = stoi(tmp);
                        dots++;

                        if (firstly == 0) {
                            firstly = 1;
                        }
//                        cout << "WE GOT PARAMETER 0, VALUE '.' FIRSTLY IS " << short(firstly) << ", AND TMP IS " << tmp << endl;
                    }

                    tmp.clear();
                    parameter++;
                } else if (parameter == 1) {
                    if (value[i] == ':') {
                        duration.minutes = stoi(tmp);

                        colons++;
//                        cout << "WE GOT PARAMETER 1, VALUE ':' FIRSTLY IS " << short(firstly) << short(firstly) << ", AND TMP IS " << tmp << endl;
                    } else {
                        period.months = stoi(tmp);

                        dots++;
//                        cout << "WE GOT PARAMETER 1, VALUE '.' FIRSTLY IS " << short(firstly) << ", AND TMP IS " << tmp << endl;
                    }

                    tmp.clear();
                    parameter++;
                } else {
                    if (value[i] == ' ') {
                        if (colons != 0 and dots == 0) {
                            duration.seconds = stoi(tmp);
                            already_entered = -1;

//                            cout << "WE GOT PARAMETER 2 WITH ' ', VALUE ' ' FIRSTLY IS " << short(firstly) << ", AND TMP IS " << tmp << endl;
                        } else if (colons == 0 and dots != 0) {
                            period.years = stoi(tmp);
                            already_entered = 1;

//                            cout << "WE GOT PARAMETER 2 WITH ':', VALUE ' ' FIRSTLY IS " << short(firstly) << ", AND TMP IS " << tmp << endl;
                        }

                        parameter = 0;
                        tmp.clear();
                    } else if (value[i] == '\0') {
//                        cout << "WE GOT PARAMETER 2 WITH TERMINATOR, FIRSTLY IS " << short(firstly) << ", AND TMP IS " << tmp << endl;
                        if (firstly == -1) {
                            if (already_entered == -1) {
                                period.years = stoi(tmp);
                            } else if (already_entered == 1) {
                                duration.seconds = stoi(tmp);
                            }
                        } else if (firstly == 1) {
                            if (already_entered == 1) {
                                duration.seconds = stoi(tmp);
                            } else if (already_entered == -1) {
                                period.years = stoi(tmp);
                            }
                        }

                        parameter = 0;
                        tmp.clear();
                    }
                }
            }
        }

        bool date_status = date_check(string_status, period);
        bool time_status = time_check(string_status, duration);

        if (time_status) {
            cout << "The time statements have been reset." << endl;

            duration.seconds = 0;
            duration.minutes = 0;
            duration.hours = 0;
        }

        if (date_status) {
            cout << "The date statements have been reset." << endl;
            period.days = 0;
            period.months = 0;
            period.years = 0;
        }
    }

    [[maybe_unused]] static bool str_check(string inputed_string) {
       bool err = false;

       if (count(inputed_string.begin(), inputed_string.end(), ':') != 0
           and count(inputed_string.begin(), inputed_string.end(), '.') != 0
           and count(inputed_string.begin(), inputed_string.end(), ' ') == 0) {
           cout << "ERR: dots and colons can't be together!" << endl;
           err = true;
       } else if (count(inputed_string.begin(), inputed_string.end(), ':') != 0
                  and count(inputed_string.begin(), inputed_string.end(), '.') != 0
                  and count(inputed_string.begin(), inputed_string.end(), ' ') != 0) {
           if (count(inputed_string.begin(), inputed_string.end(), '.') != 2) {
               cout << "ERR: Incorrect dot number! It should be 2, but I see " <<
                    count(inputed_string.begin(), inputed_string.end(), '.') << "." << endl;
               err = true;
           }

           if (count(inputed_string.begin(), inputed_string.end(), ':') != 2) {
               cout << "ERR: Incorrect colon number! It should be 2, but I see " <<
                    count(inputed_string.begin(), inputed_string.end(), ':') << "." << endl;
               err = true;
           }

           if (count(inputed_string.begin(), inputed_string.end(), ' ') != 1) {
               cout << "ERR: Incorrect space number! It should be 1, but I see " <<
                    count(inputed_string.begin(), inputed_string.end(), ' ') << "." << endl;
           }
       } else if (count(inputed_string.begin(), inputed_string.end(), ':') != 0
                  and count(inputed_string.begin(), inputed_string.end(), '.') == 0
                  and count(inputed_string.begin(), inputed_string.end(), ' ') == 0) {
           if (count(inputed_string.begin(), inputed_string.end(), ':') != 2) {
               cout << "ERR: Incorrect colon number! It should be 2, but I see " <<
                    count(inputed_string.begin(), inputed_string.end(), ':') << "." << endl;
               err = true;
           }
       } else if (count(inputed_string.begin(), inputed_string.end(), ':') == 0
                  and count(inputed_string.begin(), inputed_string.end(), '.') != 0
                  and count(inputed_string.begin(), inputed_string.end(), ' ') == 0) {
           if (count(inputed_string.begin(), inputed_string.end(), '.') != 2) {
               cout << "ERR: Incorrect colon number! It should be 2, but I see " <<
                    count(inputed_string.begin(), inputed_string.end(), '.') << "." << endl;
               err = true;
           }
       } else if (count(inputed_string.begin(), inputed_string.end(), ':') == 0
                  and count(inputed_string.begin(), inputed_string.end(), '.') == 0
                  and count(inputed_string.begin(), inputed_string.end(), ' ') != 0) {
           cout << "ERR: I don't see any symbols, except spaces!" << endl;
           err = true;
       } else if (count(inputed_string.begin(), inputed_string.end(), ':') == 0
                  and count(inputed_string.begin(), inputed_string.end(), '.') == 0
                  and count(inputed_string.begin(), inputed_string.end(), ' ') == 0) {
           cout << "ERR: I don't see any symbols!" << endl;
           err = true;
       }

       for (size_t i = 0; i < type_string_len(inputed_string); i++) {
           if (inputed_string[i] < '0' or inputed_string[i] > '9') {
               if (inputed_string[i] == '.' or inputed_string[i] == ':' or inputed_string[i] == ' ') {
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

    [[maybe_unused]] static bool date_check(bool str_status, date inputed_date) {
        if (str_status) {
            cout << "ERR: I can't handle incorrect string!" << endl;
            return -1;
        }

        if (inputed_date.days == 0 and inputed_date.months == 0 and inputed_date.years == 0) {
            cout << "I don't see any date. I will assume that you have not entered anything." << endl;
            return false;
        }

        bool err = false;

        if (inputed_date.months <= 0 or inputed_date.months > 12) {
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
            cout << "ERR: Incorrect year input! It can't be less then 0 inclusively, but I see " << inputed_date.years << endl;
            err = true;
        }

        return err;
    }

    [[maybe_unused]] static bool time_check(bool str_status, stime inputed_time) {
        if (str_status) {
            cout << "ERR: I can't handle incorrect string!" << endl;
            return -1;
        }

        if (inputed_time.seconds == 0 and inputed_time.minutes == 0 and inputed_time.hours == 0) {
            cout << "I don't see any time. I will assume that you have not entered anything." << endl;
            return false;
        }

        bool err = false;

        if (inputed_time.seconds <= 0 or inputed_time.seconds > 59) {
            cout << "ERR: Incorrect seconds input! It can't be less then 0 inclusively and more then 59." << endl;
            err = true;
        }

        if (inputed_time.minutes <= 0 or inputed_time.minutes > 59) {
            cout << "ERR: Incorrect minutes input! It can't be less then 0 inclusively and more then 59." << endl;
            err = true;
        }

        if (inputed_time.hours < 0 or inputed_time.hours > 23) {
            cout << "ERR: Incorrect hours input! It can't be less then 0 and more then 23." << endl;
            err = true;
        }

        return err;
    }

    [[maybe_unused]] inline bool input_type() {
        if (count(value.begin(), value.end(), '.')) {
            return false;
        } else if (count(value.begin(), value.end(), ':')) {
            return true;
        } else {
            cout << "ERR: Unreadable input!" << endl;
            return -1;
        }
    }

    [[maybe_unused]] void get_current_time_and_date() {
        struct tm *result;
        time_t current_sec;

        time(&current_sec);
        result = localtime(&current_sec);

        duration.seconds = result -> tm_sec;
        duration.minutes = result -> tm_min;
        duration.hours = result -> tm_hour;

        period.days = result -> tm_mday;
        period.months = result -> tm_mon;
        period.years = result -> tm_year;
    }

    [[maybe_unused]] [[nodiscard]] long long secs_to(bool time_status) const {
        if (time_status) {
            cout << "ERR: I can't handle incorrect input!" << endl;
            return -1;
        }

        long long result;
        long long inputed_time;
        time_t current_sec;

        time(&current_sec);
        inputed_time = (period.years - 1) * 31536000 + (period.months - 1) * 2629743
                        + (period.days - 1) * 86400 + (duration.hours - 1) * 3600
                        + (duration.minutes - 1) * 60 + duration.seconds;    // 1 month (30.44 days) = 2629743 seconds;
        result = inputed_time - current_sec;


        if (result < 0) {
            return (result * -1);
        }

        return result;
    }

    [[maybe_unused]] [[nodiscard]] long long days_to() const {
        long long result;
        long long inputed_days;
        long long current_days;
        time_t current_sec;

        time(&current_sec);
        inputed_days = (period.years - 1) * 365 + (period.months - 1) * 30 + period.days;
        current_days = current_sec / 86400;
        result = inputed_days - current_days;


        if (result < 0) {
            return (result * -1);
        }

        return result;
    }

    [[maybe_unused]] inline void print() const {
        cout << duration.hours << ':' << duration.minutes << ':' << duration.seconds << endl;
        cout << period.days << '.' << period.months << '.' << period.years << endl;
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


    [[maybe_unused]] inline void add_time_sec(short seconds) {
        duration.seconds += seconds;
    }

    [[maybe_unused]] inline void add_time_min(short minutes) {
        duration.minutes += minutes;
    }

    [[maybe_unused]] inline void add_time_hour(short hours) {
        duration.hours += hours;
    }


    [[maybe_unused]] inline void add_time_day(short days) {
        period.days += days;
    }

    [[maybe_unused]] inline void add_time_month(short months) {
        period.months += months;
    }

    [[maybe_unused]] inline void add_time_year(short years) {
        period.years += years;
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


    [[maybe_unused]] inline stime get_time() {
        return duration;
    }

    [[maybe_unused]] inline date get_date() {
        return period;
    }

};

int main() {
    string input_value = "21:58:4 10.8.1957";
    TimeDate obj1 {input_value};

    obj1.dismemberment();
    obj1.print();

    return 0;
}