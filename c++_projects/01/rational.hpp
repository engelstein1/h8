
class Rational
{

    int numerator;
    int denominator;
    int common_divedor(Rational num);
public:
    Rational(int numerator, int denominator);

    void print();
    Rational operator+(Rational other);
    Rational operator-(Rational other);
    Rational operator*(Rational other);
    Rational operator/(Rational other);
    Rational reduce();
    Rational invert();
    Rational compare();
};
