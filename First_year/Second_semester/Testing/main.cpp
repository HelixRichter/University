#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    const char *char_s = s.c_str();
    char *normal_s = (char *)char_s;

    cout << strlen(normal_s) << endl;


    for (int i = 0; i < 6; i++) {
        if (normal_s[i] == '\0') {
            normal_s[strlen(normal_s) + 1] = '\0';
            normal_s[strlen(normal_s)] = 'k';
        }
    }

    cout << normal_s << endl;
    cout << strlen(normal_s) << endl;



    for (int i = 0; i < strlen(normal_s) + 1; i++) {
        if (normal_s[i] == '\0') {
            cout << i;
        }
    }

    return 0;
}
