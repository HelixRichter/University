#include "movebot.h"
#include <iostream>

using namespace std;

int main() {

    bot Kevin(5, 6, 'E');

    Kevin.move();
    Kevin.move();
    Kevin.move();

    Kevin.left();
    Kevin.left();

    Kevin.move();
    Kevin.move();
    Kevin.move();

}