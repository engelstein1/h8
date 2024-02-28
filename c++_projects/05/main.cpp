#include <list>
#include <iostream>
#include "rational.hpp"



template <typename Iter>
void println(Iter first, Iter end)
{
    std::cout << "[";
    while (first != end) {
        std::cout << *first ;
        ++first;
        if(first!= end) {
            std::cout << ", ";
    }}
    std::cout << "]" <<'\n';
}

template <typename Container>
void println(Container const& container)
{
    println(container.begin(), container.end());
}

int main()
{
    std::list<Rational> lst = { Rational{4,5},Rational{3,6},Rational{2,7}};
    println(lst);

    return 0;
}