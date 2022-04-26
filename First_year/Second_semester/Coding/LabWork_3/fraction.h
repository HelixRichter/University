#ifndef LABWORK_3_FRACTION_H
#define LABWORK_3_FRACTION_H


#include <ostream>
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

    fraction & operator = (const fraction &);

    ~fraction();

    [[nodiscard]] int get_numerator() const;
    [[nodiscard]] int get_denominator() const;
};


#endif