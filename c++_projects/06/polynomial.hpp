#include <array>
#include <iostream>
#include <vector>

template <typename T>
class Polynomial
{
public:
    Polynomial(size_t degree);
    std::vector<T> get_coef();
    T &operator[](size_t index);
    T operator[](size_t index) const;
    size_t get_degree();
    void print();
    T evaluate(T x);

    Polynomial<T> operator+=(const Polynomial<T> &other);
    Polynomial<T> operator-=(const Polynomial<T> &other);
    Polynomial<T> operator*=(const Polynomial<T> &other);

    Polynomial<T> compose(const Polynomial<T> &other);
    Polynomial<T> derive();
    Polynomial<T> findRoots();

private:
    size_t m_degree;
    std::vector<T> m_coef;
};

template <typename T>
Polynomial<T>::Polynomial(size_t degree)
    : m_degree(degree), m_coef(degree + 1)

{
}

template <typename T>
std::vector<T> Polynomial<T>::get_coef()
{
    return m_coef;
}

template <typename T>
size_t Polynomial<T>::get_degree()
{
    return m_degree;
}

template <typename T>
T &Polynomial<T>::operator[](size_t index)
{
    return m_coef.at(index);
}

template <typename T>
Polynomial<T> Polynomial<T>::operator+=(const Polynomial<T> &other)
{
    size_t max_degree = std::max(m_degree, other.m_degree);

    Polynomial<T> result(max_degree);
    for (size_t i = 0; i <= m_degree; i++)
    {
        result.m_coef[i] = m_coef[i];
    }
    for (size_t i = 0; i <= other.m_degree; i++)
    {
        result.m_coef[i] += other.m_coef[i];
    }
    this->m_coef = result.m_coef;
    this->m_degree = result.m_degree;
    return *this;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator-=(const Polynomial<T> &other)
{
    size_t max_degree = std::max(m_degree, other.m_degree);

    Polynomial<T> result(max_degree);
    for (size_t i = 0; i <= m_degree; i++)
    {
        result.m_coef[i] = m_coef[i];
    }
    for (size_t i = 0; i <= other.m_degree; i++)
    {
        result.m_coef[i] -= other.m_coef[i];
    }

    this->m_coef = result.m_coef;
    this->m_degree = result.m_degree;
    return *this;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator*=(const Polynomial<T> &other)
{
    size_t max_degree = std::max(m_degree, other.m_degree);
    size_t min_degree = std::min(m_degree, other.m_degree);

    Polynomial<T> result(max_degree);
    for (size_t i = 0; i <= m_degree; i--)
    {
        for (size_t j = 0; j <= other.m_degree; j++)
        {
            result.m_coef[i + j] += m_coef[i] * other.m_coef[j];
        }
    }

    this->m_coef = result.m_coef;
    this->m_degree = result.m_degree;
    return *this;
}

template <typename T>
void Polynomial<T>::print()
{

    for (int i = static_cast<int>(m_degree); i >= 0; i--)
    {
        if (m_coef[i] != 0)
        {

            if (m_coef[i] > 0 and i != static_cast<int>(m_degree))
            {
                std::cout << "+";
            }

            std::cout << m_coef[i] << "x^" << i;
        }
        continue;
    }
    std::cout << std::endl;
}

template <typename T>
T Polynomial<T>::evaluate(T x)
{
    T result = 0;
    for (size_t i = 0; i <= m_degree; i++)
    {
        result += m_coef[i] * pow(x, i);
    }
    return result;
}

template <typename T, typename S>
Polynomial<T> operator+(const Polynomial<T> &a, const Polynomial<S> &b)
{
    Polynomial<T> result = a;
    return result += b;
}

template <typename T, typename S>
Polynomial<T> operator-(const Polynomial<T> &a, const Polynomial<S> &b)
{
    Polynomial<T> result = a;
    return result -= b;
}

template <typename T, typename S>
Polynomial<T> operator*(const Polynomial<T> &a, const Polynomial<S> &b)
{
    Polynomial<T> result = a;
    return result *= b;
}