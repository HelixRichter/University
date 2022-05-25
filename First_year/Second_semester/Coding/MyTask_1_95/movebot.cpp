#include "movebot.h"
#include <iostream>


bot::bot() noexcept
        : y_position {0}, x_position {0}, orientation {'N'}, steps {0} {}

bot::bot(int x, int y, char orientation_temp)
        : x_position {0}, y_position {0}, orientation {orientation_temp}, steps {0} {}

bot::bot(const bot &tmp) = default;

bot::bot(bot &&tmp) noexcept = default;


void bot::move() {

    switch (orientation) {

        case 'N':
            y_position++;
            break;
        case 'E':
            x_position++;
            break;
        case 'S':
            y_position--;
            break;
        case 'W':
            x_position--;
            break;

    }

    steps++;

    if (x_position == 0 && y_position == 0) {

        std::cout << "Bot has reached the starting point." << std::endl
                  << "It walked " << static_cast <int> (steps) << " steps." << std::endl;

    }

//    std::cout << "[DEBUG] [MOVE] POSITION: " << x_position << ", " << y_position << ", " << orientation << std::endl
//              << "[DEBUG] STEPS: " << static_cast <int> (steps) << std::endl << std::endl;

}


void bot::right() {

    switch (orientation) {

        case 'N':
            orientation = 'E';
            break;
        case 'E':
            orientation = 'S';
            break;
        case 'S':
            orientation = 'W';
            break;
        case 'W':
            orientation = 'N';
            break;

    }

//    std::cout << "[DEBUG] [RIGHT] POSITION: " << x_position << ", " << y_position << ", " << orientation << std::endl
//              << "[DEBUG] STEPS: " << static_cast <int> (steps) << std::endl << std::endl;

}


void bot::left() {

    switch (orientation) {

        case 'N':
            orientation = 'W';
            break;
        case 'E':
            orientation = 'N';
            break;
        case 'S':
            orientation = 'E';
            break;
        case 'W':
            orientation = 'S';
            break;

    }

//    std::cout << "[DEBUG] [LEFT] POSITION: " << x_position << ", " << y_position << ", " << orientation << std::endl
//              << "[DEBUG] STEPS: " << static_cast <int> (steps) << std::endl << std::endl;

}