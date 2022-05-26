#include "live.h"
#include <iostream>

using namespace std;

live::live() {

    rows = rand();
    columns = rand();

    for (int i = 0; i < rows; i++) {

        std::vector <entity> temp;
        for (int j = 0; j < columns; j++) {

            right.alive = rand() % 2;
            right.visible = true;
            temp.push_back(right);

        }

        universe.push_back(temp);

    }

}

[[maybe_unused]] live::live(int rows_temp, int columns_temp) : rows {rows_temp}, columns {columns_temp} {

    for (int i = 0; i < rows; i++) {

        std::vector <entity> temp;
        for (int j = 0; j < columns; j++) {

            right.alive = rand() % 2;
            right.visible = true;
            temp.push_back(right);

        }

        universe.push_back(temp);

    }

}

[[maybe_unused]] live::live(const live &temp) = default;

[[maybe_unused]] live::live(live &&) = default;


void live::birth() {

//    for (int i = 0; i < rows; i++) {
//
//        for (int j = 0; j < columns; j++) {
//
//            if ()
//
//        }
//
//    }

}

int * live::circulation() {

    int result[2];
    int current_row = 0;
    int current_column = 0;

    for (int i = 0; i < rows; i++) {

        if (!current_row) {

            for (int j = 0; j < columns; j++) {

                if (!current_column) {

                    if (!universe[i][j].alive) {

                        if (universe[i][j + 1].alive && universe[i + 1][j].alive && universe[i + 1][j + 1].alive) {

                            universe[i][j].alive = true;
                            universe[i][j].visible = false;

                        }

                    }

                } else if (current_column != (columns - 1)) {

                    if (!universe[i][j].alive) {

                        if (universe[i][j + 1].alive && universe[i + 1][j].alive && universe[i + 1][j + 1].alive) {

                            universe[i][j].alive = true;
                            universe[i][j].visible = false;

                        }

                    }

                }

                current_column++;

            }

        }

        current_row++;

    }

}

std::ostream & operator << (std::ostream &out, const live &temporary_out) {

    for (int i = 0; i < temporary_out.rows; i++) {

        for (int j = 0; j < temporary_out.columns; j++) {

            if (!temporary_out.universe[i][j].alive) {
                std::cout << ".\t";
            } else {
                std::cout << "*\t";
            }

        }

        std::cout << std::endl;

    }

    return out;

}