#include <iostream>
using namespace std;

class SuperClass {
public:
    SuperClass() = default;

    int a;
    int b;

    void print() const {
        cout << "A = " << a << ", " << "B = " << b << endl;
    }
};

int main() {
    SuperClass test {};
    test.a = 2;
    test.b = 3;

    test.print();

    return 0;
}
