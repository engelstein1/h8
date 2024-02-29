#include <list>
#include <iostream>
#include "rational.hpp"

template <typename Iter>
void println(Iter first, Iter end)
{
    std::cout << "[";
    while (first != end)
    {
        std::cout << *first;
        ++first;
        if (first != end)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << '\n';
}

template <typename Container>
void println(Container const &container)
{
    println(container.begin(), container.end());
}

template <typename Iter>
double product(Iter first, Iter end)
{
    if (first == end)
    {
        return 0;
    }
    double mult = 1;
    while (first != end)
    {
        mult *= *first;
        ++first;
    }
    std::cout << mult << '\n';
    return mult;
}

template <typename Container>
double product_left(Container const &container)
{
    return product(container.rbegin(), container.rend());
}

template <typename Container>
double product_right(Container const &container)
{
    return product(container.begin(), container.end());
}

template <typename Iter>
Iter find_max(Iter first, Iter end)
{
    if (first == end)
    {
        return end;
    }
    Iter max = first;
    first++;
    while (first != end)
    {
        if (*max < *first)
        {
            max = first;
        }
        ++first;
    }
    std::cout << *max << '\n';
    return max;
}

template <typename Container>
auto find_max(Container const &container)
{
    return *find_max(container.begin(), container.end());
}

template <typename Iter, typename T>
bool my_search(Iter first, Iter end, T x)
{
    if (first == end)
    {
        return false;
    }
    while (first != end)
    {

        if (*first == x)
        {
            return true;
        }
        first++;
    }
    return false;
}


int main()
{
    std::list<Rational> lst = {Rational{4, 5}, Rational{3, 6}, Rational{2, 7}};
    println(lst);
    std::list<double> lt = {1.6, 2, 3.3, 4.4, 5.1, 6, 7.51, 8, 9};
    product_left(lt);
    product_right(lt);
    find_max(lt);
    std::cout << my_search(lt.begin(), lt.end(), 7.51) << "\n";

    return 0;
}