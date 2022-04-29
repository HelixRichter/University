#include "fraction.h"
#include <string>
#include <algorithm>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "NullDereference"

using namespace std;

fraction::fraction() noexcept {
    numerator = new int;
    denominator = new int;
}

[[maybe_unused]] fraction::fraction(int num, int denom) {
    numerator = new int;
    denominator = new int;

    *(this->numerator) = num;
    *(this->denominator) = denom;

    simplify();
}

[[maybe_unused]] fraction::fraction(const fraction & tmp) {
    numerator = new int;
    denominator = new int;

    *(this->numerator) = *(tmp.numerator);
    *(this->denominator) = *(tmp.denominator);
}

[[maybe_unused]] fraction::fraction(fraction &&tmp) noexcept {
    numerator = new int;
    denominator = new int;

    *(this->numerator) = *(tmp.numerator);
    *(this->denominator) = *(tmp.denominator);

    delete tmp.numerator;
    delete tmp.denominator;
}

fraction & fraction::operator = (const fraction &tmp) {
    if (this == &tmp) {
        return *this;
    }

    delete this->numerator;
    delete this->denominator;

    this->numerator = new int;
    this->denominator = new int;

    *(this->numerator) = *(tmp.numerator);
    *(this->denominator) = *(tmp.denominator);

    return *this;
}

fraction & fraction::operator += (const fraction &tmp) {
    if (*(this->denominator) == *(tmp.denominator)) {
        *(this->numerator) = *(this->numerator) + *(tmp.numerator);

        return *this;
    }

    *(this->numerator) = (*(this->numerator) * *(tmp.denominator)) +
                         (*(tmp.numerator) * *(this->denominator));
    *(this->denominator) = *(this->denominator) * *(tmp.denominator);

    simplify();

    return *this;
}

fraction & fraction::operator += (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) + *(upgraded_tmp.numerator);

    simplify();

    return *this;
}

fraction & fraction::operator -= (const fraction &tmp) {
    if (*(this->denominator) == *(tmp.denominator)) {
        *(this->numerator) = *(this->numerator) - *(tmp.numerator);

        return *this;
    }

    *(this->numerator) = (*(this->numerator) * *(tmp.denominator)) -
                         (*(tmp.numerator) * *(this->denominator));
    *(this->denominator) = *(this->denominator) * *(tmp.denominator);

    simplify();

    return *this;
}

fraction & fraction::operator -= (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) - *(upgraded_tmp.numerator);

    simplify();

    return *this;
}

fraction & fraction::operator *= (const fraction &tmp) {
    *(this->numerator) = *(this->numerator) * *(tmp.numerator);
    *(this->denominator) = *(this->denominator) * *(tmp.denominator);

    return *this;
}

fraction & fraction::operator *= (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) * *(upgraded_tmp.numerator);
    *(this->denominator) = *(this->denominator) * *(upgraded_tmp.denominator);

    return *this;
}

fraction & fraction::operator /= (const fraction &tmp) {
    *(this->numerator) = *(this->numerator) * *(tmp.denominator);
    *(this->denominator) = *(this->denominator) * *(tmp.numerator);

    return *this;
}

fraction & fraction::operator /= (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) * *(upgraded_tmp.denominator);
    *(this->denominator) = *(this->denominator) * *(upgraded_tmp.numerator);

    return *this;
}

fraction & fraction::operator + (const fraction &tmp) {
    if (*(this->denominator) == *(tmp.denominator)) {
        *(this->numerator) = *(this->numerator) + *(tmp.numerator);

        return *this;
    }

    *(this->numerator) = (*(this->numerator) * *(tmp.denominator)) +
                         (*(tmp.numerator) * *(this->denominator));
    *(this->denominator) = *(this->denominator) * *(tmp.denominator);

    return *this;
}

fraction & fraction::operator + (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) + *(upgraded_tmp.numerator);

    return *this;
}

fraction & fraction::operator ++ () {
    *(this->numerator) = *(this->numerator) + *(this->denominator);

    return *this;
}

fraction fraction::operator ++ (int) {
    fraction tmp = *this;
    ++*this;

    return tmp;
}

fraction & fraction::operator - (const fraction &tmp) {
    if (*(this->denominator) == *(tmp.denominator)) {
        *(this->numerator) = *(this->numerator) - *(tmp.numerator);

        return *this;
    }

    *(this->numerator) = (*(this->numerator) * *(tmp.denominator)) -
                         (*(tmp.numerator) * *(this->denominator));
    *(this->denominator) = *(this->denominator) * *(tmp.denominator);

    return *this;
}

fraction & fraction::operator - (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) - *(upgraded_tmp.numerator);

    return *this;
}

fraction & fraction::operator -- () {
    *(this->numerator) = *(this->numerator) - *(this->denominator);

    return *this;
}

fraction fraction::operator -- (int) {
    fraction tmp = *this;
    --*this;

    return tmp;
}

fraction & fraction::operator * (const fraction &tmp) {
    *(this->numerator) = *(this->numerator) * *(tmp.numerator);
    *(this->denominator) = *(this->denominator) * *(tmp.denominator);

    return *this;
}

fraction & fraction::operator * (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) * *(upgraded_tmp.numerator);
    *(this->denominator) = *(this->denominator) * *(upgraded_tmp.denominator);

    return *this;
}

fraction & fraction::operator / (const fraction &tmp) {
    *(this->numerator) = *(this->numerator) * *(tmp.denominator);
    *(this->denominator) = *(this->denominator) * *(tmp.numerator);

    return *this;
}

fraction & fraction::operator / (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) * *(upgraded_tmp.denominator);
    *(this->denominator) = *(this->denominator) * *(upgraded_tmp.numerator);

    return *this;
}

ostream & operator << (ostream &out, const fraction &tmp) {
    return out << tmp.get_numerator() << '/' << tmp.get_denominator() << endl;
}

istream & operator >> (istream &in, fraction &tmp) {
    char slash = 0;

    in >> *(tmp.numerator) >> slash >> *(tmp.denominator);
    return in;
}

fraction operator "" _fraction(const char *tmp) {
    string local_string_tmp = string(tmp);
    string local_numerator;
    string local_denominator;

    bool slash_status = false;
    for (int i = 0; i < local_string_tmp.length(); i++) {
        if (local_string_tmp[i] == '/') {
            slash_status = true;
        } else if (isdigit(local_string_tmp[i])) {
            if (!slash_status) {
                local_numerator += local_string_tmp[i];
            } else {
                local_denominator += local_string_tmp[i];
            }
        }
    }

    fraction result;
    *(result.numerator) = stoi(local_numerator);
    *(result.denominator) = stoi(local_denominator);

    return result;
}

bool operator == (const fraction &tmp1, const fraction &tmp2) {
    return (tmp1.numerator == tmp2.numerator &&
            tmp1.denominator == tmp2.denominator);
}

bool operator != (const fraction &tmp1, const fraction &tmp2) {
    return !(tmp1.numerator == tmp2.numerator &&
            tmp1.denominator == tmp2.denominator);
}

bool operator > (const fraction &tmp1, const fraction &tmp2) {
    return (tmp1.numerator > tmp2.numerator &&
            tmp1.denominator > tmp2.denominator);
}

bool operator >= (const fraction &tmp1, const fraction &tmp2) {
    return (tmp1.numerator >= tmp2.numerator &&
            tmp1.denominator >= tmp2.denominator);
}

bool operator < (const fraction &tmp1, const fraction &tmp2) {
    return (tmp1.numerator < tmp2.numerator &&
            tmp1.denominator < tmp2.denominator);
}

bool operator <= (const fraction &tmp1, const fraction &tmp2) {
    return (tmp1.numerator <= tmp2.numerator &&
            tmp1.denominator <= tmp2.denominator);
}

fraction::operator float() const {
    float local_numerator = (float) *(this->numerator);
    float local_denominator = (float) *(this->denominator);

    return (local_numerator / local_denominator);
}

fraction::operator double() const {
    double local_numerator = (double) *(this->numerator);
    double local_denominator = (double) *(this->denominator);

    return (local_numerator / local_denominator);
}

fraction::operator string() const {
    string local_numerator = to_string(*(this->numerator));
    string local_denominator = to_string(*(this->denominator));

    return (local_numerator + "/" + local_denominator);
}

fraction::~fraction() {
    delete numerator;
    delete denominator;
}

int fraction::get_numerator() const {
    return *(this->numerator);
}

int fraction::get_denominator() const {
    return *(this->denominator);
}

void fraction::simplify() {
//    cout << "[DEBUG] STARTED SIMPLIFYING: " << *(this->numerator) << '/' << *(this->denominator) << endl;

    if (*(this->numerator) / *(this->denominator) != 0 and !(*(this->numerator) % *(this->denominator))) {
//        cout << "[DEBUG] NUMERATOR CAN BE DIVIDED BY DENOMINATOR: " << *(this->numerator) << endl;
        *(this->numerator) /= *(this->denominator);
        *(this->denominator) = 1;
    } else if (*(this->denominator) / *(this->numerator) != 0 and !(*(this->denominator) % *(this->numerator))) {
//        cout << "[DEBUG] DENOMINATOR CAN BE DIVIDED BY NUMERATOR: " << *(this->numerator) << endl;
        *(this->denominator) /= *(this->numerator);
        *(this->numerator) = 1;
    } else {
//        cout << "[DEBUG] I NEED TO FIND LOCAL DIVIDER FOR NUMERATOR AND DENOMINATOR: " << *(this->numerator) << '/' << *(this->denominator) << endl;
        int dividers[4] = {2, 3, 5, 7};

        for (int divider : dividers) {
            if (!(*(this->numerator) % divider) and !(*(this->denominator) % divider)) {
//                cout << "[DEBUG] I FOUND IT: " << divider << endl;
                *(this->numerator) /= divider;
                *(this->denominator) /= divider;

//                cout << "[DEBUG] FRACTION AFTER DIVIDING BY " << divider << " IS: " << *(this->numerator) << '/' << *(this->denominator) << endl;

                simplify();
            }
        }
    }
}

[[maybe_unused]] void fraction::simplify(const fraction &tmp) {
    if (*(tmp.numerator) / *(tmp.denominator) != 0) {
        if (!(*(tmp.numerator) % *(tmp.denominator))) {
            *(tmp.numerator) /= *(tmp.denominator);
            *(tmp.denominator) = 1;
        }
    } else if (*(tmp.denominator) / *(tmp.numerator) != 0) {
        if (!(*(tmp.denominator) % *(tmp.numerator))) {
            *(tmp.denominator) /= *(tmp.numerator);
            *(tmp.numerator) = 1;
        }
    } else {
        int dividers[4] = {2, 3, 5, 7};

        for (int divider : dividers) {
            if (!(*(tmp.numerator) % divider) and !(*(tmp.denominator) % divider)) {
                *(tmp.numerator) /= divider;
                *(tmp.denominator) /= divider;

                simplify();
            }
        }
    }
}

#pragma clang diagnostic pop