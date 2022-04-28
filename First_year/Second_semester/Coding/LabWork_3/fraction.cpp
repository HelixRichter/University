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

fraction & fraction::operator += (const fraction &tmp) {
    if (*(this->denominator) == *(tmp.denominator)) {
        *(this->numerator) = *(this->numerator) + *(tmp.numerator);

        return *this;
    }

    *(this->numerator) = (*(this->numerator) * *(tmp.denominator)) +
                         (*(tmp.numerator) * *(this->denominator));
    *(this->denominator) = *(this->denominator) * *(tmp.denominator);

    return *this;
}

fraction & fraction::operator += (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) + *(upgraded_tmp.numerator);

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

    return *this;
}

fraction & fraction::operator -= (int tmp) {
    fraction upgraded_tmp;
    *(upgraded_tmp.denominator) = *(this->denominator);
    *(upgraded_tmp.numerator) = *(upgraded_tmp.denominator) * tmp;

    *(this->numerator) = *(this->numerator) - *(upgraded_tmp.numerator);

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