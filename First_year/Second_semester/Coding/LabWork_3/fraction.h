#ifndef LABWORK_3_FRACTION_H
#define LABWORK_3_FRACTION_H


#include <iostream>
using namespace std;

class fraction {
private:
    int *numerator {};
    int *denominator {};

public:
    fraction() noexcept;
    [[maybe_unused]] fraction(int, int);
    [[maybe_unused]] fraction(const fraction &);
    [[maybe_unused]] fraction(fraction &&) noexcept;

    ~fraction();

    [[maybe_unused]] fraction & operator = (const fraction &);

    [[maybe_unused]] fraction & operator += (const fraction &);
    [[maybe_unused]] fraction & operator += (int);

    [[maybe_unused]] fraction & operator -= (const fraction &);
    [[maybe_unused]] fraction & operator -= (int);

    [[maybe_unused]] fraction & operator *= (const fraction &);
    [[maybe_unused]] fraction & operator *= (int);

    [[maybe_unused]] fraction & operator /= (const fraction &);
    [[maybe_unused]] fraction & operator /= (int);

    [[maybe_unused]] fraction & operator ++ ();
    [[maybe_unused]] fraction & operator + (const fraction &);
    [[maybe_unused]] fraction & operator + (int);
    [[maybe_unused]] fraction operator ++ (int);

    [[maybe_unused]] fraction & operator -- ();
    [[maybe_unused]] fraction & operator - (const fraction &);
    [[maybe_unused]] fraction & operator - (int);
    [[maybe_unused]] fraction operator -- (int);

    [[maybe_unused]] fraction & operator * (const fraction &);
    [[maybe_unused]] fraction & operator * (int);

    [[maybe_unused]] fraction & operator / (const fraction &);
    [[maybe_unused]] fraction & operator / (int);

    friend ostream & operator << (ostream &, const fraction &);
    friend istream & operator >> (istream &, fraction &);

    friend bool operator == (const fraction &, const fraction &);
    friend bool operator != (const fraction &, const fraction &);

    friend bool operator > (const fraction &, const fraction &);
    friend bool operator >= (const fraction &, const fraction &);

    friend bool operator < (const fraction &, const fraction &);
    friend bool operator <= (const fraction &, const fraction &);

    [[nodiscard]] int get_numerator() const;
    [[nodiscard]] int get_denominator() const;
};


#endif