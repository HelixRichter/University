#include <iostream>
using namespace std;

class SuperClass {
public:
    int a;
    int b;
};

int main() {
    SuperClass test;
    test.a = 2;
    test.b = 3;

    cout << test.a << " " << test.b;

    return 0;
}
