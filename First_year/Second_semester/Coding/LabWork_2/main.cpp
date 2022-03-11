#include <iostream>
#include <string>

using namespace std;

class TimeDate {

private:
    struct time {
        short int seconds;
        short int minutes;
        short int hours;
    };

    struct date {
        short int days;
        short int months;
        short int years;
    };

public:
    TimeDate() = default;
    TimeDate(string value) {

    }

};

int main() {

    return 0;
}
