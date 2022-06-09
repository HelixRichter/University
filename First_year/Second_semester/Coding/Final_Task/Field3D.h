#ifndef FINAL_TASK_FIELD3D_H
#define FINAL_TASK_FIELD3D_H

#include <vector>

class Field3D {

private:
    std::vector < std::vector < std::vector <bool> > > field;

public:
    Field3D();
    [[maybe_unused]] Field3D(std::initializer_list <int>);
    [[maybe_unused]] Field3D(const Field3D &);
    [[maybe_unused]] Field3D(Field3D &&);
    ~Field3D();

};


#endif
