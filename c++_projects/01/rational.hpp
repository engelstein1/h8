
#include <iostream>
class Rational
{

    int m_numerator;
    int m_denominator;
    int common_divedor(Rational num);
public:
    Rational(int numerator, int denominator);

    int numerator() const;
    int denominator() const;

    void print();
    void operator+=(Rational const &other);
    void operator-=(Rational const &other);
    void operator*=(Rational const &other);
    void operator/=(Rational const &other);
    void reduce();
    void invert();
    Rational compare();
};
Rational operator+(Rational  const &r1, Rational const &r2);
Rational operator-(Rational  const &r1, Rational const &r2);
Rational operator*(Rational  const &r1, Rational const &r2);
Rational operator/(Rational  const &r1, Rational const &r2);
bool operator==(Rational  &r1, Rational &r2);
bool operator!=(Rational &r1, Rational &r2);

int greatest_common_divisor(Rational rational);

std::ostream &operator<<(std::ostream& os, Rational r);
