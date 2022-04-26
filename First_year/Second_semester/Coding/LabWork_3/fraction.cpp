#include "fraction.h"

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

ostream & operator << (ostream & out, const fraction & tmp) {
    return out << tmp.get_numerator() << '/' << tmp.get_denominator() << endl;
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

#pragma clang diagnostic pop