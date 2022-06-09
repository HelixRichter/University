#ifndef TASK_21_TARGET_H
#define TASK_21_TARGET_H

#include <vector>

class target {

private:
    std::vector <int> circle;

    [[maybe_unused]] int aim();
    [[maybe_unused]] int aim(int x_position, int y_position);

public:
    target();
    [[maybe_unused]] target(std::initializer_list <int> temp);

    [[maybe_unused]] target(const target &);

    [[maybe_unused]] target (target &&);
    ~target();

    [[maybe_unused]] void shot();
    [[maybe_unused]] void shot(int x_position, int y_position);

};


#endif
