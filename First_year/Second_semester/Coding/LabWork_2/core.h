#ifndef LABWORK_2_CORE_H
#define LABWORK_2_CORE_H

#include <cstring>
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
    TimeDate();
    explicit TimeDate(const string&);
    TimeDate(const TimeDate&);
    TimeDate(TimeDate&&) noexcept;

    inline static size_t type_string_len(const string& inputed_string) {
        const char *c_value = inputed_string.c_str();
        return strlen(c_value);
    }
    static bool date_check(bool str_status, date inputed_date) {
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
    static bool time_check(bool str_status, stime inputed_time) {
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

    inline bool input_type();
    void get_current_time_and_date();

    inline void print() const;
    [[nodiscard]] long long secs_to(bool) const;
    [[nodiscard]] long long days_to() const;

    inline void set_time_sec(short);
    inline void set_time_min(short);
    inline void set_time_hour(short);

    inline void add_time_sec(short);
    inline void add_time_min(short);
    inline void add_time_hour(short);

    inline void add_time_day(short);
    inline void add_time_month(short);
    inline void add_time_year(short);

    inline void set_time_day(short);
    inline void set_time_month(short);
    inline void set_time_year(int);

    [[nodiscard]] inline int get_time_sec() const;
    [[nodiscard]] inline int get_time_min() const;
    [[nodiscard]] inline int get_time_hour() const;

    [[nodiscard]] inline int get_time_day() const;
    [[nodiscard]] inline int get_time_month() const;
    [[nodiscard]] inline int get_time_year() const;

    inline stime get_time();
    inline date get_date();
};

#endif
