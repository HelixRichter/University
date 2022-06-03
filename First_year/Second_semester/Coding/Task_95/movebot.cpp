#include "movebot.h"
#include <iostream>


bot::bot() noexcept
        : y_position {0}, x_position {0}, orientation {'N'}, steps {0} {}

[[maybe_unused]] bot::bot(int x, int y, char orientation_temp)
        : x_position {0}, y_position {0}, orientation {orientation_temp}, steps {0} {}

[[maybe_unused]] bot::bot(const bot &tmp) = default;

[[maybe_unused]] bot::bot(bot &&tmp) noexcept = default;

[[maybe_unused]] int bot::get_x_position() const {
    return x_position;
}

[[maybe_unused]] int bot::get_y_position() const {
    return y_position;
}

[[maybe_unused]] int bot::get_orientation() const {
    return (int) orientation;
}

[[maybe_unused]] int bot::get_steps() const {
    return (int) steps;
}

[[maybe_unused]] void bot::set_x_position(int temp) {
    x_position = temp;
}

[[maybe_unused]] void bot::set_y_position(int temp) {
    y_position = temp;
}

[[maybe_unused]] void bot::set_orientation(char temp) {
    orientation = temp;
}

[[maybe_unused]] void bot::set_steps(char temp) {
    steps = temp;
}

void bot::move() {

    if (orientation == 'N') {
        y_position++;
    } else if (orientation == 'E') {
        x_position++;
    } else if (orientation == 'S') {
        y_position--;
    } else {
        x_position--;
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

    if (orientation == 'N') {
        orientation = 'E';
    } else if (orientation == 'E') {
        orientation = 'S';
    } else if (orientation == 'S') {
        orientation = 'W';
    } else if (orientation == 'W') {
        orientation = 'N';
    }

//    std::cout << "[DEBUG] [RIGHT] POSITION: " << x_position << ", " << y_position << ", " << orientation << std::endl
//              << "[DEBUG] STEPS: " << static_cast <int> (steps) << std::endl << std::endl;

}


void bot::left() {

    if (orientation == 'N') {
        orientation = 'W';
    } else if (orientation == 'E') {
        orientation = 'N';
    } else if (orientation == 'S') {
        orientation = 'E';
    } else if (orientation == 'W') {
        orientation = 'S';
    }

//    std::cout << "[DEBUG] [LEFT] POSITION: " << x_position << ", " << y_position << ", " << orientation << std::endl
//              << "[DEBUG] STEPS: " << static_cast <int> (steps) << std::endl << std::endl;

}