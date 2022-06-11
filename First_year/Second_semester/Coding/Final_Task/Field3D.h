#ifndef FINAL_TASK_FIELD3D_H
#define FINAL_TASK_FIELD3D_H

#include <iostream>

class Field3D {

private:
    struct position {
        int x;
        int y;
        int z;
    };

    position vector {};

public:
    Field3D();
    [[maybe_unused]] Field3D(std::initializer_list <int>);
    [[maybe_unused]] Field3D(const Field3D &);
    [[maybe_unused]] Field3D(Field3D &&);
    ~Field3D();

    friend Field3D operator + (const Field3D &first_temp, const Field3D &second_temp);
    friend Field3D operator - (const Field3D &first_temp, const Field3D &second_temp);

    [[maybe_unused]] Field3D vector_product(const Field3D &temp) const;
    [[maybe_unused]] int distance(const Field3D &temp) const;

    [[maybe_unused]] int vector_value() const;
    [[maybe_unused]] void normalization();

    friend int operator * (const Field3D &first_temp, const Field3D &second_temp);

    friend int operator * (const Field3D &first_temp, const int &second_temp);
    friend int operator / (const Field3D &first_temp, const int &second_temp);

    Field3D & operator = (const Field3D &temp);
    Field3D & operator += (const Field3D &temp);
    Field3D & operator -= (const Field3D &temp);

    friend bool operator == (const Field3D &first_temp, const Field3D &second_temp);
    friend bool operator != (const Field3D &first_temp, const Field3D &second_temp);

    friend std::ostream & operator << (std::ostream &out, const Field3D &temp);

};


#endif
