#include "Field3D.h"
#include <iostream>
#include <math.h>

using namespace std;

Field3D::Field3D() {

    vector.x = 0;
    vector.y = 0;
    vector.z = 0;

}

[[maybe_unused]] Field3D::Field3D(initializer_list <int> temp) {

    int temp_arr[3] {0};
    int count {0};
    for (auto i : temp) {
        temp_arr[count] = i;
        count++;
    }

    vector.x = temp_arr[0];
    vector.y = temp_arr[1];
    vector.z = temp_arr[2];

}

[[maybe_unused]] Field3D::Field3D(const Field3D &temp) = default;
[[maybe_unused]] Field3D::Field3D(Field3D &&temp) = default;
[[maybe_unused]] Field3D::~Field3D() = default;


Field3D operator + (const Field3D &first_temp, const Field3D &second_temp) {

    Field3D result;

    result.vector.x = first_temp.vector.x + second_temp.vector.x;
    result.vector.y = first_temp.vector.x + second_temp.vector.y;
    result.vector.z = first_temp.vector.z + second_temp.vector.z;

    return result;

}

Field3D operator - (const Field3D &first_temp, const Field3D &second_temp) {

    Field3D result;

    result.vector.x = first_temp.vector.x - second_temp.vector.x;
    result.vector.y = first_temp.vector.x - second_temp.vector.y;
    result.vector.z = first_temp.vector.z - second_temp.vector.z;

    return result;

}

int operator * (const Field3D &first_temp, const Field3D &second_temp) {

    return (first_temp.vector.x * second_temp.vector.x +
            first_temp.vector.x * second_temp.vector.y +
            first_temp.vector.z * second_temp.vector.z);

}

[[maybe_unused]] Field3D Field3D::vector_product (const Field3D &temp) const {

    Field3D result;

    result.vector.x = vector.y * temp.vector.z -
                      vector.z * temp.vector.y;
    result.vector.y = vector.z * temp.vector.x -
                      vector.x * temp.vector.z;
    result.vector.z = vector.x * temp.vector.y -
                      vector.y * temp.vector.x;

    return result;

}

[[maybe_unused]] int Field3D::distance (const Field3D &temp) const {

    int result_x = vector.x - temp.vector.x;
    int result_y = vector.y - temp.vector.y;
    int result_z = vector.z - temp.vector.z;

    return sqrt(result_x * result_x + result_y * result_y + result_z * result_z);

}

[[maybe_unused]] int Field3D::vector_value () const {
    return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

[[maybe_unused]] void Field3D::normalization() {

    int magnitude = vector_value();
    int inverted_magnitude = 1 / magnitude;

    vector.x *= inverted_magnitude;
    vector.y *= inverted_magnitude;
    vector.z *= inverted_magnitude;

}

int operator * (const Field3D &first_temp, const int &second_temp) {

    return (first_temp.vector.x * second_temp +
            first_temp.vector.x * second_temp +
            first_temp.vector.z * second_temp);

}

int operator / (const Field3D &first_temp, const int &second_temp) {

    return (first_temp.vector.x / second_temp +
            first_temp.vector.x / second_temp +
            first_temp.vector.z / second_temp);

}

Field3D & Field3D::operator = (const Field3D &temp) {

    vector.x = temp.vector.x;
    vector.y = temp.vector.y;
    vector.z = temp.vector.z;

    return *this;

}

Field3D & Field3D::operator += (const Field3D &temp) {
    return  (*this = *this + temp);
}

Field3D & Field3D::operator -= (const Field3D &temp) {
    return (*this = *this - temp);
}

bool operator == (const Field3D &first_temp, const Field3D &second_temp) {

    if (first_temp.vector.x == second_temp.vector.x and
        first_temp.vector.y == second_temp.vector.y and
        first_temp.vector.z == second_temp.vector.z) {

        return true;

    } else {
        return false;
    }

}

bool operator != (const Field3D &first_temp, const Field3D &second_temp) {

    if (first_temp.vector.x == second_temp.vector.x and
        first_temp.vector.y == second_temp.vector.y and
        first_temp.vector.z == second_temp.vector.z) {

        return false;

    } else {
        return true;
    }

}

std::ostream & operator << (std::ostream &out, const Field3D &temp) {
    out << "{" << temp.vector.x << ", " << temp.vector.y << ", " << temp.vector.z << "}";

    return out;
}