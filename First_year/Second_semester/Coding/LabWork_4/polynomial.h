#ifndef LABWORK_4_POLYNOMIAL_H
#define LABWORK_4_POLYNOMIAL_H


#include <vector>
#include <ostream>
#include <initializer_list>

class polynomial {
private:
    std::vector <double> Polynomial;

public:
    polynomial();

    /* Конструктор с параметром в виде int-С-массива.
     * [ПРИНИМАЕТ] 1-ый элемент: указатель на начало массива;
     * [ПРИНИМАЕТ] 2-ой элемент: указатель на конец массива.
    */

    [[maybe_unused]] polynomial(int *expression_start, int *expression_end);

    /* Конструктор с параметром в виде float-С-массива.
     * [ПРИНИМАЕТ] 1-ый элемент: указатель на начало массива;
     * [ПРИНИМАЕТ] 2-ой элемент: указатель на конец массива.
    */

    [[maybe_unused]] polynomial(float *expression_start, float *expression_end);

    /* Конструктор с параметром в виде double-С-массива.
     * [ПРИНИМАЕТ] 1-ый элемент: указатель на начало массива;
     * [ПРИНИМАЕТ] 2-ой элемент: указатель на конец массива.
    */

    [[maybe_unused]] polynomial(double *expression_start, double *expression_end);

    // Конструктор с параметром в виде double-массива со списком инициализаторов initializer_list.
    [[maybe_unused]] polynomial(const std::initializer_list <double> & expression);

    // Конструктор копирования значения объекта-многочлена.
    [[maybe_unused]] polynomial(const polynomial &expression_temp);

    // Конструктор перемещения значения объекта-многочлена.
    [[maybe_unused]] polynomial(const polynomial &&expression_temp);

    ~polynomial();


    /* Перегруженный оператор индекса.
     * [ПРИНИМАЕТ]: индекс элемента double-массива;
     * [ВОЗВРАЩАЕТ]: значение элемента double-массива.
    */

    double & operator [] (const int index);

    // Перегруженный оператор получения значения элемента {vector} массива - объекта-многочлена.
    [[maybe_unused]] double at(int index) const;

    /* Перегруженный оператор вывода.
     * [ПРИНИМАЕТ] 1-ый элемент: ссылка на объект {cout};
     * [ПРИНИМАЕТ] 2-ой элемент: ссылка на объект-многочлен.
    */

    friend std::ostream & operator << (std::ostream &out, const polynomial &expression_temp);

    // Перегруженный оператор приведения vector-массива в string.
    operator std::string() const;

    /* Решение многочлена по примеру: 10x^(3) - 5x^(2) + 17x - 21
     * Множитель {x} - значение элемента vector-массива;
     * Степень {x} - индекс элемента vector-массива.
     *
     * [ПРИНИМАЕТ]: значение типа double, которое будет принято за {x}.
     * [ВОЗВРАЩАЕТ]: значение типа double, являющееся ответом выражения.
    */

    [[maybe_unused]] double polynomial_solution(double x) const;

    /* Перегруженный оператор присваивания.
     * [ПРИНИМАЕТ]: объект-многочлен, чьё значение присваивается;
     * [ВОЗВРАЩАЕТ]: объект-многочлен, значение которого меняется.
    */

    polynomial & operator = (const polynomial &expression_temp);

    /* Перегруженный оператор сравнения.
     * [ПРИНИМАЕТ] 1-ый элемент: ссылка на первый объект-многочлен;
     * [ПРИНИМАЕТ] 2-ой элемент: ссылка на второй объект-многочлен;
     * [ВОЗВРАЩАЕТ]: Исход сравнения {ИСТИННО ЛИ?} (1 или 0).
    */

    friend bool operator == (const polynomial &expression_temp_1, const polynomial &expression_temp_2);

    /* Перегруженный оператор сравнения.
     * [ПРИНИМАЕТ] 1-ый элемент: ссылка на первый объект-многочлен;
     * [ПРИНИМАЕТ] 2-ой элемент: ссылка на второй объект-многочлен;
     * [ВОЗВРАЩАЕТ]: Исход сравнения {ЛОЖНО ЛИ?} (1 или 0).
    */

    friend bool operator != (const polynomial &expression_temp_1, const polynomial &expression_temp_2);

    /* Перегруженный оператор прибавления значения объекта {POLYNOMIAL} справа к значению объекта {POLYNOMIAL} слева.
     * [ПРИНИМАЕТ]: объект, чьё значение прибавляется;
     * [ВОЗВРАЩАЕТ]: объект, чьё значение изменяется.
    */

    polynomial & operator += (const polynomial &expression_temp);

    /* Перегруженный оператор отнимания значения объекта {POLYNOMIAL} справа к значению объекта {POLYNOMIAL} слева.
     * [ПРИНИМАЕТ]: объект, чьё значение отнимается;
     * [ВОЗВРАЩАЕТ]: объект, чьё значение изменяется.
    */

    polynomial & operator -= (const polynomial &expression_temp);

    /* Перегруженный оператор умножения значения объекта {POLYNOMIAL} справа на значение объекта {POLYNOMIAL} слева.
     * [ПРИНИМАЕТ]: объект, чьё значение - множитель;
     * [ВОЗВРАЩАЕТ]: объект, чьё значение изменяется.
    */

    polynomial & operator *= (const polynomial &expression_temp);

    /* Перегруженный оператор деления значения объекта {POLYNOMIAL} справа на значение объекта {POLYNOMIAL} слева.
     * [ПРИНИМАЕТ]: объект, чьё значение - делитель;
     * [ВОЗВРАЩАЕТ]: объект, чьё значение изменяется.
    */

    polynomial & operator /= (const polynomial &expression_temp);

    /* Перегруженный оператор остатка от деления у значения объекта {POLYNOMIAL} справа на значение объекта {POLYNOMIAL} слева.
     * [ПРИНИМАЕТ]: объект, чьё значение - делитель;
     * [ВОЗВРАЩАЕТ]: объект, чьё значение изменяется.
    */

    polynomial & operator %= (const polynomial &expression_temp);

    // Перегруженный оператор унарного минуса для объекта-многочлена.
    polynomial & operator - ();


    // Перегруженный оператор унарного плюса для объекта-многочлена.
    polynomial & operator + () const;

    /* Перегруженный оператор сложения.
     * [ПРИНИМАЕТ]: первый объект-многочлен;
     * [ПРИНИМАЕТ]: второй объект-многочлен;
     * [ВОЗВРАЩАЕТ]: объект-результат операции.
    */

    friend polynomial operator + (const polynomial &expression_temp_1, const polynomial &expression_temp_2);

    /* Перегруженный оператор вычитания.
     * [ПРИНИМАЕТ]: первый объект-многочлен;
     * [ПРИНИМАЕТ]: второй объект-многочлен;
     * [ВОЗВРАЩАЕТ]: объект-результат операции.
    */

    friend polynomial operator - (const polynomial &expression_temp_1, const polynomial &expression_temp_2);

    /* Перегруженный оператор умножения.
     * [ПРИНИМАЕТ]: первый объект-многочлен;
     * [ПРИНИМАЕТ]: второй объект-многочлен;
     * [ВОЗВРАЩАЕТ]: объект-результат операции.
    */

    friend polynomial operator * (const polynomial &expression_temp_1, const polynomial &expression_temp_2);

    /* Перегруженный оператор деления.
     * [ПРИНИМАЕТ]: первый объект-многочлен;
     * [ПРИНИМАЕТ]: второй объект-многочлен;
     * [ВОЗВРАЩАЕТ]: объект-результат операции.
    */

    friend polynomial operator / (const polynomial &expression_temp_1, const polynomial &expression_temp_2);

    /* Перегруженный оператор остатка от деления.
     * [ПРИНИМАЕТ]: первый объект-многочлен;
     * [ПРИНИМАЕТ]: второй объект-многочлен;
     * [ВОЗВРАЩАЕТ]: объект-результат операции.
    */

    friend polynomial operator % (const polynomial &expression_temp_1, const polynomial &expression_temp_2);

};


#endif