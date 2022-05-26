#include "live.h"
#include <iostream>


live::live() {

    rows = rand();
    columns = rand();

    for (int i = 0; i < rows; i++) {

        std::vector <bool> temp;
        for (int j = 0; j < columns; j++) {

            alive = rand() % 2;
            temp.push_back(alive);

        }

        universe.push_back(temp);

    }

}

[[maybe_unused]] live::live(int rows_temp, int columns_temp) : rows {rows_temp}, columns {columns_temp} {

    for (int i = 0; i < rows; i++) {

        std::vector <bool> temp;
        for (int j = 0; j < columns; j++) {

            alive = rand() % 2;
            temp.push_back(alive);

        }

        universe.push_back(temp);

    }

}

[[maybe_unused]] live::live(const live &temp) = default;

[[maybe_unused]] live::live(live &&) = default;


std::ostream & operator << (std::ostream &out, const live &temporary_out) {

    for (int i = 0; i < temporary_out.rows; i++) {

        for (int j = 0; j < temporary_out.columns; j++) {

            if (!temporary_out.universe[i][j]) {
                std::cout << ".";
            } else {
                std::cout << "*";
            }

        }

        std::cout << std::endl;

    }

    return out;

}