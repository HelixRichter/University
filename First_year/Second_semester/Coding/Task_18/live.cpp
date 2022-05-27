#include "live.h"
#include <iostream>

using namespace std;

live::live() {

    rows = rand();
    columns = rand();
    generation = 0;

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

    generation = 0;

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


[[maybe_unused]] void live::cycle() {

    cout << "[DEBUG] BIRTH:" << endl;
    birth();
    cout << "--------------" << endl;

    cout << "[DEBUG] DEATH:" << endl;
    death();
    cout << "--------------" << endl;

    cout << "[DEBUG] RESULT" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            universe[i][j].visible = true;
        }
    }

    generation++;

}

[[maybe_unused]] void live::birth() {

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < columns; j++) {

            if ( !universe[i][j].alive ) {

                int *temp = analysis(i, j);
                if ( temp[0] == 3 ) {
                    universe[i][j].alive = true;
                    universe[i][j].visible = false;
                }

            }

        }

    }

}

void live::death() {

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < columns; j++) {

            if (universe[i][j].alive) {

                int *temp = analysis(i, j);
                if (temp[0] == 2 or temp[0] == 3) {
                    continue;
                } else {
                    universe[i][j].alive = false;
                }

            }

        }

    }

}

[[maybe_unused]] int * live::analysis(int row_index, int column_index) {

    /*  Счётчик живых и мёртвых клеток в виде int-массива.
     *  [ЭЛЕМЕНТ ПО ИНДЕКСУ 0] - количество живых клеток вокруг изучаемой;
     *  [ЭЛЕМЕНТ ПО ИНДЕКСУ 1] - количество мёртвых клеток вокруг изучаемой.
     */

    static int count[2] {0, 0};

    if (!row_index && !column_index) {

        if ( universe[row_index + 1][column_index].alive ) {
            if ( universe[row_index + 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index][column_index + 1].alive ) {
            if ( universe[row_index][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index + 1].alive ) {
            if ( universe[row_index + 1][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

    } else if ( !row_index && column_index == (columns - 1) ) {

        if ( universe[row_index][column_index - 1].alive ) {
            if ( universe[row_index][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index].alive ) {
            if ( universe[row_index + 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index - 1].alive ) {
            if ( universe[row_index + 1][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

    } else if ( row_index == (rows - 1) && !column_index ) {

        if ( universe[row_index - 1][column_index].alive ) {
            if ( universe[row_index - 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index][column_index + 1].alive ) {
            if ( universe[row_index][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index - 1][column_index + 1].alive ) {
            if ( universe[row_index - 1][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

    } else if ( row_index == (rows - 1) && column_index == (columns - 1) ) {

        if ( universe[row_index][column_index - 1].alive ) {
            if ( universe[row_index][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index - 1][column_index].alive ) {
            if ( universe[row_index - 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index - 1][column_index - 1].alive ) {
            if ( universe[row_index - 1][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

    } else if ( !row_index ) {

        if ( universe[row_index][column_index - 1].alive ) {
            if ( universe[row_index][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index][column_index + 1].alive ) {
            if ( universe[row_index][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index - 1].alive ) {
            if ( universe[row_index][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index].alive ) {
            if ( universe[row_index + 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index + 1].alive ) {
            if ( universe[row_index + 1][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

    } else if ( !column_index ) {

        if ( universe[row_index - 1][column_index].alive ) {
            if ( universe[row_index - 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index].alive ) {
            if ( universe[row_index + 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if (  universe[row_index][column_index + 1].alive ) {
            if ( universe[row_index][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index - 1][column_index + 1].alive ) {
            if ( universe[row_index - 1][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index + 1].alive ) {
            if ( universe[row_index + 1][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

    } else if ( row_index == (rows - 1) ) {

        if ( universe[row_index][column_index - 1].alive ) {
            if ( universe[row_index][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index][column_index + 1].alive ) {
            if ( universe[row_index][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index - 1][column_index].alive ) {
            if ( universe[row_index - 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index - 1][column_index - 1].alive ) {
            if ( universe[row_index - 1][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index - 1][column_index + 1].alive ) {
            if ( universe[row_index - 1][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

    } else if ( column_index == (columns - 1) ) {

        if ( universe[row_index - 1][column_index].alive ) {
            if ( universe[row_index - 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index].alive ) {
            if ( universe[row_index + 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index - 1][column_index - 1].alive ) {
            if ( universe[row_index - 1][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index][column_index - 1].alive ) {
            if ( universe[row_index][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index - 1].alive ) {
            if ( universe[row_index + 1][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

    } else {

        if ( universe[row_index - 1][column_index - 1].alive ) {
            if ( universe[row_index - 1][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index - 1][column_index].alive ) {
            if ( universe[row_index - 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index - 1][column_index + 1].alive ) {
            if ( universe[row_index - 1][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index][column_index + 1].alive ) {
            if ( universe[row_index][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index + 1].alive ) {
            if ( universe[row_index + 1][column_index + 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index].alive ) {
            if ( universe[row_index + 1][column_index].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index + 1][column_index - 1].alive ) {
            if ( universe[row_index + 1][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

        if ( universe[row_index][column_index - 1].alive ) {
            if ( universe[row_index][column_index - 1].visible ) {
                count[0]++;
            }
        } else {
            count[1]++;
        }

    }

    return count;

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