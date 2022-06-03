#ifndef TASK_18_LIVE_H
#define TASK_18_LIVE_H

#include <vector>
#include <ostream>

class live {

private:
    struct entity {
        bool alive;
        bool visible;
    };

    entity right {};
    int rows {}, columns {}, generation {};
    std::vector < std::vector <entity> > universe;


    [[maybe_unused]] void birth();
    [[maybe_unused]] void death();
    [[maybe_unused]] int analysis(int row_index, int column_index);

public:
    live();

    [[maybe_unused]] live(int rows, int columns);
    [[maybe_unused]] live(const live &temp);
    [[maybe_unused]] live(live &&);

    ~live();


    [[maybe_unused]] void cycle();

    [[maybe_unused]] int get_rows();
    [[maybe_unused]] int get_columns();
    [[maybe_unused]] int get_generation();
    [[maybe_unused]] std::vector < std::vector <entity> > get_universe();

    [[maybe_unused]] void set_rows(int temp);
    [[maybe_unused]] void set_columns(int temp);
    [[maybe_unused]] void set_universe( std::vector < std::vector <entity> > temp );

    friend std::ostream & operator << (std::ostream &out, const live &temporary_out);

};


#endif