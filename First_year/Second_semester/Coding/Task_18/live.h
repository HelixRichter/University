#ifndef TASK_18_LIVE_H
#define TASK_18_LIVE_H

#include <vector>
#include <ostream>

class live {

private:
    bool alive;
    int rows, columns;
    std::vector < std::vector <bool> > universe;

public:
    live();

    [[maybe_unused]] live(int rows, int columns);

    [[maybe_unused]] live(const live &temp);

    [[maybe_unused]] live(live &&);





    friend std::ostream & operator << (std::ostream &out, const live &temporary_out);

};


#endif
