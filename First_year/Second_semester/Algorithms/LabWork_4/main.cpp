#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"

#include <iostream>
using namespace std;

class String {

private:
    static const int n = 10;
    char str[n + 1];

public:
    String () {
        str[0] = 0;
    }

    explicit String (char s[]) {                            // string?
        str[0] = 0;

        int i = 0;
        for (i; s[i] != '\0'; i++) {
            add(s[i]);
        }

        str[i] = '\0';
    }

    void add (char x) {
        str[0]++;
        str[str[0]] = x;
    }

    void display () {
        for (int i = 1; i < int(str[0]); i++) {
            cout << str[i] << " ";
        }

        cout << endl;
    }

    int strlen() {
        return int(str[0]);
    }

    String separate (int k) {
        String s;
        bool status = false;
        int j = 1;

        if (k < n) {
            for (int i = k; i < this -> strlen(); i++) {    // this?
                s.str[j] = this -> str[i];                  // this?
                s.str[0]++;
                j++;

                if (!status) {                              // need test for IF
                    this -> str[i] = '\0';                  // this?
                    status = true;
                }
            }

            s.str[j] = '\0';
            return s;
        } else {
            cout << "ERROR: separate went wrong!" << endl;
            return s;                                       // s[0] = 0!
        }
    }

    string concat (String s) {
        if (this -> strlen() + s.strlen() <= n) {
            int j = 1;
            for (int i = 1; i <= n; i++) {
                if (str[i] == '\0') {
                    str[i] = s.str[j];
                    j++;
                }
            }

            return str;
        } else {
            string err = "-1";

            cout << "ERROR: concatenation went wrong!" << endl;
            return err;
        }
    }

    int context_search (String s) {
        bool status = false;

        for (int i = 1; (i < n) && (str[i] != '\0'); i++) {
            if (this -> str[i] == s.str[1]) {               // this?
                int z = i, j = 1;

                while (j <= s.str[0]) {
                    if (this -> str[z] == s.str[j]) {
                        status = true;
                        z++;
                        j++;
                    } else {
                        status = false;
                    }
                }
            }

            if (status) {
                return i;
            }
        }

        return 0;
    }

    string context_replace (String s1, String s2) {
        int k = this -> context_search(s1);              // this?

        if (k == 0) {                                      // !k?
            cout << "String not found!" << endl;
        }

        int j = 1;
        for (int i = k; i < (k + s2.str[0]); i++) {
            this -> str[i] = s2.str[j];                   // this?
            j++;
        }

        return this -> str;                               // this?
    }

};

int main() {
    char s[8], s1, s2;                                  // string?

    cout << "Enter the string" << endl;
    for (auto & i : s) {
        cin >> i;
    }

//    for (auto i : s) {
//        cout << i << " ";
//    }

    String str(s), str1, str2;
//    str.display();
    str.strlen();

    return 0;
}