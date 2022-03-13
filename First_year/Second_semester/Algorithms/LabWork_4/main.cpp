#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"

#include <iostream>
#include <cstring>
using namespace std;

class String {

private:
    static const int n = 10;
    char str[n + 1];

public:
    String () {
        str[0] = 0;
    }

    explicit String (char s[]) {
        str[0] = 0;

        int i;
        for (i = 0; s[i] != '\0'; i++) {
            add(s[i]);
        }

        str[i + 1] = '\0';
    }

    void add (char x) {
        str[0]++;
        str[str[0]] = x;
    }

    void display () {
        for (int i = 1; i <= strlen(str); i++) {
            cout << str[i] << " ";
        }

        cout << endl;
    }

    int Strlen() {
        return int(str[0]);
    }

    String separate (int k) {
        String s;
        s.str[1] = '\0';

        int j = 1;
        if (k < n) {
            for (int i = k; i <= Strlen(); i++) {
                s.str[j + 1] = '\0';
                s.str[j] = str[i];

                s.str[0]++;
                j++;
            }

            s.str[j + 1] = '\0';
            str[k] = '\0';

            return s;
        } else {
            cout << "ERROR: separate went wrong!" << endl;

            return s;                                       // s[0] = 0!
        }
    }

    string concat (String s) {

        if (Strlen() + s.Strlen() <= n) {
            int j = 1;

            for (int i = 1; i <= n; i++) {
                if (str[i] == '\0') {

                    str[strlen(str) + 1] = '\0';
                    str[strlen(str)] = s.str[j];

                    j++;
                    str[0]++;
                }
            }

            str[strlen(str) -1 ] = '\0';
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
            if (str[i] == s.str[1]) {
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
        int k = context_search(s1);

        if (!k) {
            cout << "String not found!" << endl;
        }

        int j = 1;
        for (int i = k; i < (k + s2.str[0]); i++) {
            str[i] = s2.str[j];
            j++;
        }

        return str;
    }

};

int main() {
    string s;
    cout << "Enter the string: " << endl;
    getline(cin, s);

    const char *cs = s.c_str();
    if (strlen(cs) > 10) {
        cout << "Too long string";

        return 1;
    }

    char *normal_s = (char *)cs;
    String str(normal_s); // Inputted string

    cout << "Your string: " << " ";
    str.display();

    cout << "---------------------------------------------" << endl;

    cout << "Enter string for concatenation: " << endl;
    getline(cin, s);

    cs = s.c_str();
    if (strlen(cs) > 10) {
        cout << "Too long string";

        return 1;
    }
    normal_s = (char *)cs;
    String conc_s(normal_s); // String for concatenating

    cout << "Your string: " << " ";
    conc_s.display();

    str.concat(conc_s);
    cout << "I just added this string to your str! Here it is:" << endl;
    str.display();

    cout << "---------------------------------------------" << endl;

    String sepr_s; // String for separating
    int symbol;

    cout << "Enter the symbol, from what position you want to separate:" << endl;
    cin >> symbol;

    sepr_s = str.separate(symbol);

    cout << "Here is the separated string:" << endl;
    sepr_s.display();

    cout << "And here is edited main string:" << endl;
    str.display();

    getchar();

    cout << "---------------------------------------------" << endl;

    cout << "Enter string for search in main string: " << endl;
    getline(cin, s);

    cs = s.c_str();
    if (strlen(cs) > 10) {
        cout << "Too long string";

        return 1;
    }
    normal_s = (char *)cs;
    String srch_s(normal_s); // String for concatenating

    cout << "Your string: " << endl;
    srch_s.display();

    int start_of_searchable_string = str.context_search(srch_s);
    cout << "Start of this searchable string in main string is: " << start_of_searchable_string << endl;

    cout << "---------------------------------------------" << endl;

    cout << "Enter string to move to main string instead of searchable: " << endl;
    getline(cin, s);

    cs = s.c_str();
    if (strlen(cs) > 10) {
        cout << "Too long string";

        return 1;
    }
    normal_s = (char *)cs;
    String repl_s(normal_s); // String for concatenating

    cout << "Your string: " << endl;
    repl_s.display();

    string replaced_main_string = str.context_replace(srch_s, repl_s);

    cout << "Here is your edited main string:" << endl;
    str.display();

    return 0;
}