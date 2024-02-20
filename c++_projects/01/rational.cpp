#include <iostream>
#include <utility>
#include "rational.hpp"



Rational::Rational(int num, int den)
: numerator(num), denominator(den)
{}
void Rational::print(){std::cout << "gfgfg";}
Rational Rational::operator+(Rational other){numerator * other.denominator + denominator * other.numerator,other.denominator * denominator;}
Rational Rational::operator-(Rational other){numerator * other.denominator - denominator * other.numerator,other.denominator * denominator;}
Rational Rational::operator*(Rational other){numerator * other.numerator ,other.denominator * denominator;}
Rational Rational::operator/(Rational other){numerator * other.denominator ,other.numerator * denominator;}

int Rational::common_divedor(Rational num){}

Rational Rational::reduce(Rational num){
    int ans = co
}