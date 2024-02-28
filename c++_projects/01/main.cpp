
#include "rational.hpp"

#include <iostream>

Rational r1(2, 4);
void test_plus()
{
    Rational r1(1, 1);
    Rational r2(1, 2);

    Rational r3 = r1 + r2;
    std::cout << r3 << '\n';
}

void test_minus()
{
    Rational r1(1, 1);
    Rational r2(1, 2);

    Rational r3 = r1 - r2;
    std::cout << r3 << '\n';
}

void test_plus_equale()
{
    Rational r1(1, 1);
    Rational r2(1, 2);

    r1 += r2;
    std::cout << r1 << '\n';
}

void test_reduce()
{
    Rational r1(8, 4);

    r1.reduce();
    std::cout << r1 << '\n';
}
void test_invert()
{
    Rational r1(8, 4);

    r1.invert();
    std::cout << r1 << '\n';
}
bool compare()
{
    Rational r1(4, 8);
    Rational r2(1, 4);

    bool res = r1 == r2;
    std::cout << res << '\n';
    return res;
}
int main()
{
    test_minus();
    test_plus_equale();
    test_reduce();
    test_invert();
    compare();

    std::cout << "n1:" << r1 << std::endl;
    return 0;
}