#include "polynomial.h"
#include <iostream>
#include <math.h>

polynomial::polynomial() {
    Polynomial.push_back(0);
}

[[maybe_unused]] polynomial::polynomial(int *expression_start, const int *expression_end) {
    for (int *i {expression_start}; i != expression_end; i++) {
        Polynomial.push_back(*(i));
    }
}

[[maybe_unused]] polynomial::polynomial(float *expression_start, const float *expression_end) {
    for (float *i {expression_start}; i != expression_end; i++) {
        Polynomial.push_back(*(i));
    }
}

[[maybe_unused]] polynomial::polynomial(double *expression_start, const double *expression_end) {
    for (double *i {expression_start}; i != expression_end; i++) {
        Polynomial.push_back(*(i));
    }
}

[[maybe_unused]] polynomial::polynomial(const std::initializer_list <double> &expression) {
    for (double element : expression) {
        Polynomial.push_back(element);
    }
}

[[maybe_unused]] polynomial::polynomial(const polynomial &expression_temp) {
    Polynomial = expression_temp.Polynomial;
}

[[maybe_unused]] polynomial::polynomial(polynomial &&expression_temp) noexcept {
    Polynomial = expression_temp.Polynomial;
}

polynomial::~polynomial() {
    Polynomial.clear();
}


double & polynomial::operator [] (int index) {
    if (index > -1) {
        if (index < Polynomial.size()) {
            return Polynomial.at(index);
        } else {

            for (int i = Polynomial.size(); i < index; i++) {
                Polynomial.push_back(0);
            }

            return Polynomial.at(index);

        }
    } else {
        return Polynomial.at(index);
    }
}

double polynomial::operator [] (int index) const{
    return Polynomial[index];
}

[[maybe_unused]] double polynomial::at(int index) const {
    return Polynomial.at(index);
}

polynomial & polynomial::operator = (const polynomial &expression_temp) = default;

bool operator == (const polynomial &expression_temp_1, const polynomial &expression_temp_2) {
    if (expression_temp_1.Polynomial.size() == expression_temp_2.Polynomial.size()) {

        for (int i = 0; i < expression_temp_1.Polynomial.size(); i++) {
            if (expression_temp_1.Polynomial.at(i) != expression_temp_2.Polynomial.at(i)) {
                return false;
            }
        }

        return true;

    } else {
        return false;
    }
}

bool operator != (const polynomial &expression_temp_1, const polynomial &expression_temp_2) {
    return !(expression_temp_1 == expression_temp_2);
}

polynomial & polynomial::operator += (const polynomial &expression_temp) {
    *this = *this + expression_temp;

    return *this;
}

polynomial & polynomial::operator -= (const polynomial &expression_temp) {
    *this = *this - expression_temp;

    return *this;
}

polynomial & polynomial::operator *= (const polynomial &expression_temp) {
    *this = *this * expression_temp;

    return *this;
}

polynomial & polynomial::operator /= (const polynomial &expression_temp) {
    *this = *this / expression_temp;

    return *this;
}

polynomial & polynomial::operator %= (const polynomial &expression_temp) {
    *this = *this % expression_temp;

    return *this;
}

polynomial operator + (const polynomial &expression_temp_1, const polynomial &expression_temp_2) {
    polynomial result;

    if (expression_temp_1.Polynomial.size() == expression_temp_2.Polynomial.size()) {

        result = expression_temp_1;

        for (int i = 0; i < expression_temp_1.Polynomial.size(); i++) {
//            std::cout << "[DEBUG] WORK WITH " << expression_temp_1.Polynomial.at(i) << " AND "
//                      << expression_temp_2.Polynomial.at(i) << ". ARRAY SIZE: " << result.Polynomial.size() << std::endl;
            result.Polynomial.at(i) = expression_temp_1.Polynomial.at(i) + expression_temp_2.Polynomial.at(i);
        }

//        std::cout << "[DEBUG] FINAL RESULT SIZE: " << result.Polynomial.size() << std::endl;

    } else if (expression_temp_1.Polynomial.size() > expression_temp_2.Polynomial.size()) {

        size_t temp_2_size = expression_temp_2.Polynomial.size();
        result = expression_temp_1;

        for (int i = 0; i < temp_2_size; i++) {
            std::cout << "[DEBUG] WORK WITH " << expression_temp_1.Polynomial.at(i) << " AND "
                      << expression_temp_2.Polynomial.at(i) << ". ARRAY SIZE: " << result.Polynomial.size() << std::endl;
            result.Polynomial.at(i) = expression_temp_1.Polynomial.at(i) + expression_temp_2.Polynomial.at(i);
        }

    } else {

        size_t temp_1_size = expression_temp_1.Polynomial.size();
        result = expression_temp_2;

        for (int i = 0; i < temp_1_size; i++) {
            result.Polynomial.at(i) = result.Polynomial.at(i) + expression_temp_1.Polynomial.at(i);
        }

    }

//    std::cout << "[DEBUG] RESULT SIZE: " << result.Polynomial.size() << std::endl;
    return result;
}

polynomial operator - (const polynomial &expression_temp_1, const polynomial &expression_temp_2) {
    polynomial result;

    if (expression_temp_1.Polynomial.size() == expression_temp_2.Polynomial.size()) {

        result = expression_temp_1;

        for (int i = 0; i < expression_temp_1.Polynomial.size(); i++) {
            result.Polynomial.at(i) = expression_temp_1.Polynomial.at(i) - expression_temp_2.Polynomial.at(i);
        }

    } else if (expression_temp_1.Polynomial.size() > expression_temp_2.Polynomial.size()) {

        result = expression_temp_1;
        polynomial changed_temp_2 = expression_temp_2;
        changed_temp_2.Polynomial.resize(result.Polynomial.size(), 0);

//        std::cout << "[DEBUG] RESULT SIZE: " << result.Polynomial.size() << std::endl;

        for (int i = 0; i < result.Polynomial.size(); i++) {
            result.Polynomial.at(i) -= changed_temp_2.Polynomial.at(i);
        }

    } else {

        result = expression_temp_1;

//        std::cout << "[DEBUG] ARRAY BEFORE: " << result << std::endl;
        result.Polynomial.resize(expression_temp_2.Polynomial.size(), 0);
//        std::cout << "[DEBUG] ARRAY AFTER: " << result << std::endl;

//        std::cout << result.Polynomial.size() << std::endl;

        for (int i = 0; i < result.Polynomial.size(); i++) {
//            std::cout << "[DEBUG] WORK WITH " << result.Polynomial.at(i) << " AND "
//                      << expression_temp_2.Polynomial.at(i) << ". INDEX: " << i << std::endl;
            result.Polynomial.at(i) -= expression_temp_2.Polynomial.at(i);
        }

    }

    return result;
}

polynomial & polynomial::operator - () const {
    static polynomial static_negative_result;
    static_negative_result.Polynomial = Polynomial;

    for (double & i : static_negative_result.Polynomial) {
        i *= -1;
    }

    return static_negative_result;
}

polynomial & polynomial::operator + () const {
    static polynomial static_positive_result;
    static_positive_result.Polynomial = Polynomial;

    return static_positive_result;
}

polynomial operator * (const polynomial &expression_temp_1, const polynomial &expression_temp_2) {
    polynomial result;

    if (expression_temp_1.Polynomial.size() == expression_temp_2.Polynomial.size()) {

        result = expression_temp_1;

        for (int i = 0; i < expression_temp_1.Polynomial.size(); i++) {
            result.Polynomial.at(i) = expression_temp_1.Polynomial.at(i) * expression_temp_2.Polynomial.at(i);
        }

    } else if (expression_temp_1.Polynomial.size() > expression_temp_2.Polynomial.size()) {

        result = expression_temp_1;
        polynomial changed_temp_2 = expression_temp_2;

        changed_temp_2.Polynomial.resize(result.Polynomial.size(), 0);

        for (int i = 0; i < result.Polynomial.size(); i++) {
            result.Polynomial.at(i) = result.Polynomial.at(i) * changed_temp_2.Polynomial.at(i);
        }

    } else {

        result = expression_temp_1;
        result.Polynomial.resize(expression_temp_2.Polynomial.size(), 0);

        for (int i = 0; i < expression_temp_2.Polynomial.size(); i++) {
            result.Polynomial.at(i) *= expression_temp_2.Polynomial.at(i);
        }

    }

    return result;
}

polynomial operator / (const polynomial &expression_temp_1, const polynomial &expression_temp_2) {
    polynomial result;

    if (expression_temp_1.Polynomial.size() == expression_temp_2.Polynomial.size()) {

        result = expression_temp_1;

        for (int i = 0; i < result.Polynomial.size(); i++) {
            result.Polynomial.at(i) /= expression_temp_2.Polynomial.at(i);
        }

    } else if (expression_temp_1.Polynomial.size() > expression_temp_2.Polynomial.size()) {

        result = expression_temp_1;
        polynomial changed_temp_2 = expression_temp_2;
        changed_temp_2.Polynomial.resize(result.Polynomial.size(), 0);

        for (int i = 0; i < result.Polynomial.size(); i++) {
            if (changed_temp_2.Polynomial.at(i) != 0) {
                result.Polynomial.at(i) /= expression_temp_2.Polynomial.at(i);
            }
        }

    } else {

        result = expression_temp_1;
        result.Polynomial.resize(expression_temp_2.Polynomial.size(), 0);

        for (int i = 0; i < result.Polynomial.size(); i++) {
            result.Polynomial.at(i) /= expression_temp_2.Polynomial.at(i);
        }

    }

    return result;
}

polynomial operator % (const polynomial &expression_temp_1, const polynomial &expression_temp_2) {
    polynomial result;

    if (expression_temp_1.Polynomial.size() == expression_temp_2.Polynomial.size()) {

        result = expression_temp_1;

        for (int i = 0; i < expression_temp_1.Polynomial.size(); i++) {
            result.Polynomial.at(i) = fmod(expression_temp_1.Polynomial.at(i), expression_temp_2.Polynomial.at(i));
        }

    } else if (expression_temp_1.Polynomial.size() > expression_temp_2.Polynomial.size()) {

        result = expression_temp_1;
        polynomial changed_temp_2 = expression_temp_2;
        changed_temp_2.Polynomial.resize(result.Polynomial.size(), 0);

        for (int i = 0; i < result.Polynomial.size(); i++) {
            result.Polynomial.at(i) = fmod(result.Polynomial.at(i), changed_temp_2.Polynomial.at(i));
        }

    } else {

        result = expression_temp_1;
        result.Polynomial.resize(expression_temp_2.Polynomial.size(), 0);

        for (int i = 0; i < result.Polynomial.size(); i++) {
            result.Polynomial.at(i) = fmod(result.Polynomial.at(i), expression_temp_2.Polynomial.at(i));
        }

    }

    return result;
}

[[maybe_unused]] double polynomial::polynomial_solution(double x) const {
    double result {};

    for (int i = 0; i < Polynomial.size(); i++) {
        result += Polynomial.at(i) * pow(x, i);
    }

    return result;
}

std::ostream & operator << (std::ostream &out, const polynomial &expression_temp) {
    std::string string_expression = (std::string) expression_temp;

    return out << string_expression;
}

polynomial::operator std::string() const {
    std::string string_expression;
    std::string string_number;
    bool number_null = true;

    for(int i = Polynomial.size() - 1; i >= 0; i--) {

        string_number = std::to_string(abs(Polynomial[i]));
        if (string_number[string_number.size() - 1] == '0') {

            for (size_t j = string_number.size() - 1; string_number[j] == '0'; j--) {
                string_number.erase(j, 1);
            }

            if (string_number[string_number.size() - 1] == '.')
                string_number.erase(string_number.size()-1, 1);

        }

        if (string_number != "0") {

            if ((Polynomial[i] > 0) && (!number_null)) {
                string_expression.append(" + ");
            }

            if (Polynomial[i] < 0) {
                string_expression.append(" - ");
            }

            string_expression.append(string_number);
            if(i != 0) {
                if (i == 1) {
                    string_expression.append("x");
                } else {
                    string_expression.append("x^");
                    string_expression.append(std::to_string(i));
                }
            }

            number_null = false;

        }

    }

    if (number_null) {
        string_expression.append("0 = 0");
    }

    else {
        string_expression.append(" = 0");
    }

    return string_expression;
}