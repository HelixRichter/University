#include <iostream>
#include "core.h"

using namespace std;

int main() {
    TimeDate obj;
    obj.format_str_init();

    string str;
    cin >> str;

    TimeDate::public_date date1 {};
    date1 = obj.parsing_date(str);
    cout << date1.days << endl;

    return 0;
}
