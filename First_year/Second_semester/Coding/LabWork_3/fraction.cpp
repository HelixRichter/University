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

    //delete this->numerator;
    //delete this->denominator;

    //this->numerator = new int;
    //this->denominator = new int;

    *(this->numerator) = *(tmp.numerator);
    *(this->denominator) = *(tmp.denominator);

    return *this;
}

const fraction & fraction::operator += (const fraction &tmp) {
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

const fraction & fraction::operator += (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) + *(upgraded_tmp.numerator);

    simplify();

    return *this;
}

const fraction & fraction::operator -= (const fraction &tmp) {
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

const fraction & fraction::operator -= (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) - *(upgraded_tmp.numerator);

    simplify();

    return *this;
}

const fraction & fraction::operator *= (const fraction &tmp) {
    *(this->numerator) = *(this->numerator) * *(tmp.numerator);
    *(this->denominator) = *(this->denominator) * *(tmp.denominator);

    simplify();

    return *this;
}

const fraction & fraction::operator *= (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) * *(upgraded_tmp.numerator);
    *(this->denominator) = *(this->denominator) * *(upgraded_tmp.denominator);

    simplify();

    return *this;
}

const fraction & fraction::operator /= (const fraction &tmp) {
    *(this->numerator) = *(this->numerator) * *(tmp.denominator);
    *(this->denominator) = *(this->denominator) * *(tmp.numerator);

    simplify();

    return *this;
}

const fraction & fraction::operator /= (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) * *(upgraded_tmp.denominator);
    *(this->denominator) = *(this->denominator) * *(upgraded_tmp.numerator);

    simplify();

    return *this;
}

const fraction & fraction::operator + (const fraction &tmp) {
    *(this->numerator) = (*(this->numerator) * *(tmp.denominator)) +
                         (*(tmp.numerator) * *(this->denominator));
    *(this->denominator) = *(this->denominator) * *(tmp.denominator);

    simplify();

    return *this;
}

const fraction & fraction::operator + (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) + *(upgraded_tmp.numerator);
    simplify();

    return *this;
}

const fraction & fraction::operator ++ () {
    *(this->numerator) = *(this->numerator) + *(this->denominator);
    simplify();

    return *this;
}

const fraction fraction::operator ++ (int) {
    fraction tmp = *this;
    ++*this;

    simplify();

    return tmp;
}

const fraction & fraction::operator - (const fraction &tmp) {
    if (*(this->denominator) == *(tmp.denominator)) {
        *(this->numerator) = *(this->numerator) - *(tmp.numerator);

        simplify();

        return *this;
    }

    *(this->numerator) = (*(this->numerator) * *(tmp.denominator)) -
                         (*(tmp.numerator) * *(this->denominator));
    *(this->denominator) = *(this->denominator) * *(tmp.denominator);

    simplify();

    return *this;
}

const fraction & fraction::operator - (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) - *(upgraded_tmp.numerator);
    simplify();

    return *this;
}

const fraction & fraction::operator -- () {
    *(this->numerator) = *(this->numerator) - *(this->denominator);
    simplify();

    return *this;
}

const fraction fraction::operator -- (int) {
    fraction tmp = *this;
    --*this;

    simplify();

    return tmp;
}

const fraction & fraction::operator * (const fraction &tmp) {
    *(this->numerator) = *(this->numerator) * *(tmp.numerator);
    *(this->denominator) = *(this->denominator) * *(tmp.denominator);

    simplify();

    return *this;
}

const fraction & fraction::operator * (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) * *(upgraded_tmp.numerator);
    *(this->denominator) = *(this->denominator) * *(upgraded_tmp.denominator);

    simplify();

    return *this;
}

const fraction & fraction::operator / (const fraction &tmp) {
    *(this->numerator) = *(this->numerator) * *(tmp.denominator);
    *(this->denominator) = *(this->denominator) * *(tmp.numerator);

    simplify();

    return *this;
}

const fraction & fraction::operator / (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) * *(upgraded_tmp.denominator);
    *(this->denominator) = *(this->denominator) * *(upgraded_tmp.numerator);

    simplify();

    return *this;
}

ostream & operator << (ostream &out, const fraction &tmp) {
    return out << tmp.get_numerator() << '/' << tmp.get_denominator();
}

istream & operator >> (istream &in, fraction &tmp) {
    char slash = 0;

    in >> *(tmp.numerator) >> slash >> *(tmp.denominator);
    tmp.simplify();
    return in;
}

fraction operator "" _fraction(const char *tmp) {
    string local_string_tmp = string(tmp);
    string local_numerator;
    string local_denominator;

    bool slash_status = false;
    for (char i : local_string_tmp) {
        if (i == '/') {
            slash_status = true;
        } else if (isdigit(i)) {
            if (!slash_status) {
                local_numerator += i;
            } else {
                local_denominator += i;
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
    auto local_numerator = (float) *(this->numerator);
    auto local_denominator = (float) *(this->denominator);

    return (local_numerator / local_denominator);
}

fraction::operator double() const {
    auto local_numerator = (double) *(this->numerator);
    auto local_denominator = (double) *(this->denominator);

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
//    cout << "[DEBUG] I NEED TO FIND LOCAL DIVIDER FOR NUMERATOR AND DENOMINATOR: " << *(this->numerator) << '/' << *(this->denominator) << endl;
    int dividers[4] = {2, 3, 5, 7};

    for (int divider : dividers) {
        if (!(*(this->numerator) % divider) and !(*(this->denominator) % divider)) {
//            cout << "[DEBUG] I FOUND IT: " << divider << endl;
            *(this->numerator) /= divider;
            *(this->denominator) /= divider;

//            cout << "[DEBUG] FRACTION AFTER DIVIDING BY " << divider << " IS: " << *(this->numerator) << '/' << *(this->denominator) << endl;

            simplify();
        }
    }
}

#pragma clang diagnostic pop