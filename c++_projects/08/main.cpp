#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cassert>

template <typename Container>
int compute(Container &container, int n)
{
    auto add = [](int a, int b)
    { return a + b; };
    auto mult = [n](int a, int b)
    {
        if (a > n && b > n)
        {
            return a * b;
        }
        return 0;
    };
    return transform_reduce(begin(container), --end(container), ++begin(container), 0, add, mult);
}

void test()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 8, 1, 8};
    int some = compute(v, 3);
    assert(some == 98);
    std::cout << some << std::endl;
}

int main()
{
    test();

    return 0;
}