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

    [[maybe_unused]] TimeDate(const TimeDate & copied_value) {

    };


    [[maybe_unused]] size_t str_len() {
        const char *c_value = value.c_str();
        return strlen(c_value);
    }

    [[maybe_unused]] void dismemberment() {
        short dots = 0;
        short parameter = 0; // 0 - sec/day, 1 - min/month, 2 - hour/year

        string tmp;
        tmp.clear();

        for (size_t i = 0; i <= str_len(); i++) {
            if (dots < 3) {
                if (value[i] != '.') {
                    tmp += value[i];
                } else {
                    if (!parameter) {
                        duration.hours = stoi(tmp);
                        tmp.clear();

                        parameter++;
                    } else if (parameter == 1) {
                        duration.minutes = stoi(tmp);
                        tmp.clear();

                        parameter++;
                    } else if (parameter == 2) {
                        duration.seconds = stoi(tmp);
                        tmp.clear();
                    }
                }
            } else {
                cout << "Error: invalid time or date format.";
                tmp.clear();

                return;
            }
        }
    }

    [[maybe_unused]] void print(bool is_time) const {
        if (is_time) {
            cout << duration.seconds << '.' << duration.minutes << '.' << duration.hours << endl;
        } else {
            cout << period.days << '.' << period.months << '.' << period.years << endl;
        }
    }

};

int main() {
    string rmp;
    rmp.clear();

    rmp += '1';
    rmp += '2';

    int val = stoi(rmp);
    cout << val;

    return 0;
}
