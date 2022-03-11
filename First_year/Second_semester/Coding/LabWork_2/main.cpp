#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class TimeDate {

private:
    struct time {
        short seconds;
        short minutes;
        short hours;
    };

    struct date {
        short days;
        short months;
        short years;
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


    size_t str_len() {
        const char *c_value = value.c_str();
        return strlen(c_value);
    }

    void dismemberment() {
        size_t dots = 0;
        string tmp;

        tmp.clear();

        for (size_t i = 0; i <= str_len(); i++) {
            if (dots <= 3) {
                if (value[i] == '.') {
                    dots++;
                } else {

                }
            } else {
                cout << "Error: invalid time or date format.";
                return;
            }
        }
    }

};

int main() {
    string str;
    str.clear();
    cout << str.empty();

    return 0;
}
