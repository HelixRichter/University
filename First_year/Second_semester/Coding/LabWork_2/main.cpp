#include <iostream>
#include "core.h"

using namespace std;

int main() {
    TimeDate obj;
    obj.format_str_init();

    string str;
    getline(cin, str);

    auto timedate1 = obj.parsing_timedate(str);
    cout << timedate1.hours << endl;
    cout << timedate1.minutes << endl;
    cout << timedate1.days << endl;
    cout << timedate1.months << endl;

    return 0;
}
