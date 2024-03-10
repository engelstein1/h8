#include "linkedList.hpp"
#include <iostream>

int main()
{
    LinkedList<int> list;
    LinkedList<int> l;
    l.prepend(10);
    l.prepend(20);
    l.prepend(30);
    l.prepend(40);
    // l.printl();
    list.printl();
    l.removeHead();
    l.printl();
    auto res = l.getHeadData();
    LinkedList<int> list2 = l;
    list2.printl();
    

    std::cout << res << std::endl;
    
    return 0;
}