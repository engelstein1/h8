#include "sortedVector.hpp"


int main()
{

    SortedVector<int> sv;
    sv.add(1);
    sv.add(232);
    sv.add(13);
    sv.add(43);
    sv.add(5);
    sv.add(6);
    sv.pop();
    sv.print();
    sv[3];

    
    return 0;
}