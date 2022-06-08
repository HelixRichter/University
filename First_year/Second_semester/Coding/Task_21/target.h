#ifndef TASK_21_TARGET_H
#define TASK_21_TARGET_H

#include <vector>

class target {

private:
    std::vector <int> circle;

    int aim();
    int aim(int x_position, int y_position);

public:
    target();
    target(std::initializer_list <int> temp);
    target(const target &);
    target (target &&);
    ~target();

    void shot();
    void shot(int x_position, int y_position);

};


#endif
