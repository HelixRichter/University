#include <iostream>
using namespace std;

class SuperClass {
public:
    int a;
    int b;
};

int main() {
    SuperClass test {};
    test.a = 1;
    test.b = 2;

    cout << "A = " << test.a << ", B = " << test.b;

    return 0;
}
