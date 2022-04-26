#include "fraction.h"
using namespace std;

fraction::fraction() noexcept {
    numerator = 1;
    denominator = 1;
}

fraction::fraction(const fraction & tmp) {
    this->numerator = tmp.numerator;
    this->denominator = tmp.denominator;
}

fraction::fraction(fraction && tmp) noexcept {
    this->numerator = tmp.numerator;
    this->denominator = tmp.denominator;

    tmp.numerator = 1;
    tmp.denominator = 1;
}

fraction & fraction::operator = (const fraction && tmp) noexcept {
    if (this != &tmp) {
        this->numerator = tmp.numerator;
        this->denominator = tmp.denominator;

        tmp.numerator = 1;
        tmp.denominator = 1;
    }

    return *this;
}

int fraction::get_numerator() const {
    return this->numerator;
}

int fraction::get_denominator() const {
    return this->denominator;
}

ostream & operator << (ostream & out, const fraction & tmp) {
    return out << tmp.get_numerator() << '/' << tmp.get_denominator() << endl;
}