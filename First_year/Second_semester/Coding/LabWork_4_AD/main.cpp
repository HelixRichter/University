#include "library.cpp"
using namespace std;

int main() {
    cout << boolalpha;
    float my_float_polynomial[4] = {10, -5, 17, -21};
    double my_double_polynomial[3] = {5, 0, 1};
    int my_int_polynomial[2] = {-12, 6};

    // double my_double_number = 4;
    // float my_float_number = 6;
    // int my_int_number = 8;

    Polynomial my_Polynomial1(my_float_polynomial, 4);
    Polynomial my_Polynomial2(my_double_polynomial, 3);
    Polynomial my_Polynomial3(my_int_polynomial, 2);

    // Polynomial my_Polynomial1(my_double_number);
    // Polynomial my_Polynomial2(my_float_number);
    // Polynomial my_Polynomial3(my_int_number);

    const initializer_list<double> list = {4, -2, 3, 55};
    Polynomial my_Polynomial4(list);
    Polynomial my_Polynomial5;
    my_Polynomial2.find_polynomial(2);

    cout << my_Polynomial4[10] << std::endl;
    cout << "Polynomial1: " << my_Polynomial1 << endl;
    cout << "Polynomial2: " << my_Polynomial2 << endl;
    cout << "Polynomial3: " << my_Polynomial3 << endl;
    cout << "Polynomial4: " << my_Polynomial4 << endl;
    cout << "Polynomial5: " << my_Polynomial5 << endl;
    cout << "+: " << my_Polynomial2 + my_Polynomial1 << endl;
    cout << "- : " << my_Polynomial2 - my_Polynomial1 << endl;
    cout << "- : " << -my_Polynomial2 << endl;
    cout << "* : " << my_Polynomial2 * my_Polynomial1 << endl;
    cout << "/ : " << my_Polynomial1 / my_Polynomial2 << endl;
    cout << "% : " << my_Polynomial1 % my_Polynomial2 << endl;

    cout << "/ : " << my_Polynomial2 / my_Polynomial1 << endl;
    cout << "% : " << my_Polynomial2 % my_Polynomial1 << endl;

    const Polynomial my_Polynomial6({ 1,0,5,9,2 });
    const Polynomial my_Polynomial7({ 1,0,5,9,2 });

    cout << "== : " << (my_Polynomial6 == my_Polynomial7) << endl;
    cout << "!= : " << (my_Polynomial6 != my_Polynomial7) << endl;

    my_Polynomial1 += my_Polynomial2;
    cout << "Polynomial1: " << my_Polynomial1 << endl;
    cout << (string)my_Polynomial1;

    return 0;
}