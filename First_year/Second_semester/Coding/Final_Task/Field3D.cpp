#include "Field3D.h"
#include <iostream>

Field3D::Field3D() {

    int temp_x = rand();
    int temp_y = rand();
    int temp_z = rand();

    for (int i = 0; i < temp_x; i++) {

        std::vector < std::vector <bool> > temp_vector_y;
        for (int j = 0; j < temp_y; j++) {

            std::vector <bool> temp_vector_z;
            for (int o = 0; o < temp_z; o++) {
                temp_vector_z.push_back(false);
            }
            temp_vector_y.push_back(temp_vector_z);

        }
        field.push_back(temp_vector_y);

    }

}

[[maybe_unused]] Field3D::Field3D(std::initializer_list <int> temp) {

    try {
        if (temp.size() > 3) {
            throw 1;
        }

        for (auto i : temp) {
            if (i <= 0) {
                throw 1;
            }
        }
    }

    catch (...) {
        std::cout << "[DEBUG] ERROR: INCORRECT AXIS NUMBER." << std::endl;
    }

    int axis_array[3] {0};
    int count {0};
    for (auto i : temp) {
        axis_array[count] = i;

        count++;
    }

    int temp_x = axis_array[0];
    int temp_y = axis_array[1];
    int temp_z = axis_array[2];

    for (int i = 0; i < temp_x; i++) {

        std::vector < std::vector <bool> > temp_vector_y;
        for (int j = 0; j < temp_y; j++) {

            std::vector <bool> temp_vector_z;
            for (int o = 0; o < temp_z; o++) {
                temp_vector_z.push_back(false);
            }
            temp_vector_y.push_back(temp_vector_z);

        }
        field.push_back(temp_vector_y);

    }

}

[[maybe_unused]] Field3D::Field3D(const Field3D &temp) {
    field = temp.field;
}

[[maybe_unused]] Field3D::Field3D(Field3D &&temp) {
    field = temp.field;
    temp.field.clear();
}

Field3D::~Field3D() {
    field.clear();
}