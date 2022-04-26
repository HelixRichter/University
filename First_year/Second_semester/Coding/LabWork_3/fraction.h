#ifndef LABWORK_3_FRACTION_H
#define LABWORK_3_FRACTION_H

#include <ostream>

class fraction {
private:
    int numerator;
    int denominator;

public:
    fraction() noexcept;
    fraction(const fraction &);
    fraction(fraction &&) noexcept;

    [[nodiscard]] int get_numerator() const;
    [[nodiscard]] int get_denominator() const;
};


#endif