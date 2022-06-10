#ifndef FINAL_TASK_FIELD3D_H
#define FINAL_TASK_FIELD3D_H

#include <vector>
#include <ostream>

class Field3D {

private:
    std::vector < std::vector < std::vector <int> > > field;

public:
    Field3D();
    [[maybe_unused]] Field3D(std::initializer_list <int>);
    [[maybe_unused]] Field3D(const Field3D &);
    [[maybe_unused]] Field3D(Field3D &&);
    ~Field3D();

    friend Field3D & operator + (const Field3D &first_temp, const Field3D &second_temp);
    friend Field3D & operator - (const Field3D &first_temp, const Field3D &second_temp);
    friend Field3D & operator * (const Field3D &first_temp, const Field3D &second_temp);
    friend Field3D & operator / (const Field3D &first_temp, const Field3D &second_temp);
    friend Field3D & operator % (const Field3D &first_temp, const Field3D &second_temp);

    Field3D & operator = (const Field3D &temp);
    Field3D & operator += (const Field3D &temp);
    Field3D & operator -= (const Field3D &temp);
    Field3D & operator *= (const Field3D &temp);
    Field3D & operator /= (const Field3D &temp);
    Field3D & operator %= (const Field3D &temp);

    friend bool operator == (const Field3D &first_temp, const Field3D &second_temp);
    friend bool operator >= (const Field3D &first_temp, const Field3D &second_temp);
    friend bool operator <= (const Field3D &first_temp, const Field3D &second_temp);
    friend bool operator > (const Field3D &first_temp, const Field3D &second_temp);
    friend bool operator < (const Field3D &first_temp, const Field3D &second_temp);

    friend std::ostream & operator << (std::ostream &out, const Field3D &temp);

    Field3D & external_copying(Field3D &first_temp, Field3D &second_temp);

};


#endif
