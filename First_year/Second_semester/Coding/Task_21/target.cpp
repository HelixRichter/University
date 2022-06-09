#include "target.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

target::target() {

    int temp_quantity = rand();
    for (int i = 0; i < temp_quantity; i++) {
        circle.push_back(i);
    }

    reverse(circle.begin(), circle.end());

}

[[maybe_unused]] target::target(initializer_list <int> temp) {

    for (auto i : temp) {
        circle.push_back(i);
    }

    reverse(circle.begin(), circle.end());

}

[[maybe_unused]] target::target(const target &temp) = default;

[[maybe_unused]] target::target(target &&temp) = default;

target::~target() {
    circle.clear();
}


[[maybe_unused]] int target::aim() {

    int shot_position = rand();
    for (int i = 0; i < circle.size() - 1; i++) {

        if (shot_position <= circle[0]) {
            return circle.size();
        } else if ( shot_position >= circle[i] and shot_position < circle[i + 1] ) {
            return ( circle.size() - 1 - i );
        } else if ( shot_position > circle[circle.size() - 1] ) {
            return 0;
        }

    }

    return -1;

}

[[maybe_unused]] int target::aim(int x_position, int y_position) {

    int max_position;
    if (x_position > y_position) {
        max_position = x_position;
    } else if (x_position < y_position) {
        max_position = y_position;
    } else {

        int temp = rand() % 2;
        if (temp == 0) {
            max_position = x_position;
        } else {
            max_position = y_position;
        }

    }

    for (int i = 0; i < circle.size() - 1; i++) {

        if (max_position <= circle[0]) {
            return circle.size();
        } else if ( max_position >= circle[i] and max_position < circle[i + 1] ) {
            return ( circle.size() - 1 - i );
        } else if ( max_position > circle[circle.size() - 1] ) {
            return 0;
        }

    }

    return -1;
}

[[maybe_unused]] void target::shot() {

    int result = aim();
    if (result == circle.size()) {
        cout << "Bull's-eye! A hit in the center was recorded.\n"
                "You are awarded " << result << " points.";
    } else if (result != 0) {
        cout << "Excellent! A hit into the ring was recorded.\n"
                "You are awarded " << result << " points.";
    } else {
        cout << "Oh, really? Boy, you need to train more.\n"
                "You couldn't get any points.";
    }

}

[[maybe_unused]] void target::shot(int x_position, int y_position) {

    int result = aim(x_position, y_position);
    if (result == circle.size()) {
        cout << "Bull's-eye! A hit in the center was recorded.\n"
                "You are awarded " << result << " points.";
    } else if (result != 0) {
        cout << "Excellent! A hit into the ring was recorded.\n"
                "You are awarded " << result << " points.";
    } else {
        cout << "Oh, really? Boy, you need to train more.\n"
                "You couldn't get any points.";
    }

}
