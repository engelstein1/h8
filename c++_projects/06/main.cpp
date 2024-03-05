#include "polynomial.hpp"
#include <vector>

int main()
{
    Polynomial<int> p1(13);
    p1[2] = 1;
    p1[3] = 2;
    p1[4] = -31;
    p1[5] = 2;
    p1[13] = 4;
    p1.print();
    Polynomial<int> p2(12);
    p2[2] = 51;
    p2[3] = 12;
    p2[4] = 31;
    Polynomial<int> p3 = p2 + p1;
    p2 += p1;
    p3.print();
    p2.print();

    // Polynomial<int> p2{14};
    // Polynomial<int> res = p1 + p2;
    // int num = p1[7];
    // std::cout << num << "\n";
    return 0;
}