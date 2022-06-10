#include "Field3D.h"
#include <iostream>
using namespace std;

Field3D::Field3D() {

    int temp_x = rand();
    int temp_y = rand();
    int temp_z = rand();

    for (int i = 0; i < temp_x; i++) {

        std::vector < std::vector <int> > temp_vector_y;
        for (int j = 0; j < temp_y; j++) {

            std::vector <int> temp_vector_z;
            for (int o = 0; o < temp_z; o++) {
                temp_vector_z.push_back(0);
            }
            temp_vector_y.push_back(temp_vector_z);

        }
        field.push_back(temp_vector_y);

    }

}

[[maybe_unused]] Field3D::Field3D(std::initializer_list <int> temp) {

    try {
        if (temp.size() != 3) {
            throw 1;
        }

        for (auto i : temp) {
            if (i <= 0) {
                throw 1;
            }
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

            std::vector < std::vector <int> > temp_vector_y;
            for (int j = 0; j < temp_y; j++) {

                std::vector <int> temp_vector_z;
                for (int o = 0; o < temp_z; o++) {
                    temp_vector_z.push_back(0);
                }
                temp_vector_y.push_back(temp_vector_z);

            }
            field.push_back(temp_vector_y);

        }

    }

    catch (...) {
        std::cout << "[DEVELOPER] ERROR: INCORRECT AXIS NUMBER." << std::endl;
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

Field3D & operator + (const Field3D &first_temp, const Field3D &second_temp) {

    Field3D result {1, 1, 1};


    return result;

}

Field3D & Field3D::external_copying(Field3D &first_temp, Field3D &second_temp) {

    try {

        if (first_temp.field.size() == second_temp.field.size()) {
            if (first_temp.field[0].size() == second_temp.field[0].size()) {
                if (first_temp.field[0][0].size() == second_temp.field[0][0].size()) {
                    throw 1;
                } else if (first_temp.field[0][0].size() > second_temp.field[0][0].size()) {

                    int difference = first_temp.field[0][0].size() - second_temp.field[0][0].size();
                    for (int i = 0; i < first_temp.field.size(); i++) {
                        for (int j = 0; j < first_temp.field[i].size(); j++) {
                            for (int p = 0; p < difference; p++) {
                                second_temp.field[i][j].push_back(0);
                            }
                        }
                    }

                } else if (first_temp.field[0][0].size() < second_temp.field[0][0].size()) {

                    int difference = second_temp.field[0][0].size() - first_temp.field[0][0].size();


                }
            }
        }

    }

    catch(...) {
        cout << "[DEVELOPER] ERROR: NOTHING TO DO." << endl;
    }

}

ostream & operator << (ostream &out, const Field3D &temp) {

    try {
        if (temp.field.empty() or
            temp.field[0].empty() or
            temp.field[0][0].empty()) {
            throw 1;
        }

        for (int i = 0; i < temp.field.size(); i++) {
//        cout << endl << "[DEBUG] I = " << i << endl;

//        cout << "[DEBUG] J SIZE = " << temp.field.size() << endl;
            for (int j = 0; j < temp.field[i].size(); j++) {
//            cout << endl << "[DEBUG] J = " << j << endl;

                cout << "[";
                for (int o = 0; o < temp.field[i][j].size(); o++) {
//                cout << endl << "[DEBUG] O = " << o << endl;
                    cout << temp.field[i][j][o];

                    if (o != temp.field[i][j].size() - 1) {
                        cout << ", ";
                    }
                }
                cout << "] ";

            }

            cout << endl;

        }

        return out;
    }

    catch (...) {
        cout << "[DEVELOPER] ERROR: FIELD TO PRINT ISN'T EXIST." << endl;
        return out;
    }

}