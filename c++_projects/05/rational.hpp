
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

#include <iostream>
#include <utility>
#include <numeric>
#include <bits/stdc++.h>

Rational::Rational(int num, int den)
    : m_numerator(num), m_denominator(den)
{
    reduce();
}

int Rational::numerator() const
{
    return m_numerator;
}

int Rational::denominator() const
{
    return m_denominator;
}

Rational operator+(Rational const &r1, Rational const &r2)
{

    int num = r1.numerator() * r2.denominator() + r2.numerator() * r1.denominator();
    int den = r1.denominator() * r2.denominator();
    return {num, den};
}

Rational operator-(Rational const &r1, Rational const &r2)
{
    int num = r1.numerator() * r2.denominator() - r2.numerator() * r1.denominator();
    int den = r1.denominator() * r2.denominator();
    return {num, den};
}

Rational operator*(Rational const &r1, Rational const &r2)
{
    int num = r1.numerator() * r2.numerator();
    int den = r1.denominator() * r2.denominator();
    return {num, den};
}
Rational operator/(Rational const &r1, Rational const &r2)
{
    int num = r1.numerator() * r2.denominator() - r2.numerator() * r1.denominator();
    int den = r1.denominator() * r2.denominator();
    return {num, den};
}

std::ostream &operator<<(std::ostream &os, Rational r)
{
    std::cout << r.numerator() << "/" << r.denominator();
    return os;
}

int greatest_common_divisor(Rational rational)
{
    int res = std::__gcd(rational.numerator(), rational.denominator());
    return res;
}

void Rational::reduce()
{
    int res = greatest_common_divisor(*this);
    this->m_numerator = this->m_numerator / res;
    this->m_denominator = this->m_denominator / res;
}

void Rational::operator+=(Rational const &other)
{
    *this = *this + other;
}

void Rational::operator-=(Rational const &other)
{
    *this = *this - other;
}

void Rational::operator*=(Rational const &other)
{
    *this = *this * other;
}

void Rational::operator/=(Rational const &other)
{
    *this = *this / other;
}

void Rational::invert()
{
    std::swap(this->m_denominator, this->m_numerator);
}

bool operator==(Rational &r1, Rational &r2)
{

    return r1.numerator() == r2.numerator() and r1.denominator() == r2.denominator();
}
bool operator!=(Rational &r1, Rational &r2)
{

    return (r1 == r2) == 0;
}
