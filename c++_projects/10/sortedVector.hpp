#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
class SortedVector
{
    std::vector<T> m_data;
    bool sorted;

public:
    SortedVector()
        : sorted(false) {}

    void add(T const &value)
    {
        m_data.push_back(value);
        sorted = false;
    }
    T operator[](T const &index) const
    {
        if (!sorted)
        {
            const_cast<SortedVector *>(this)->sort();
        }

        std::cout << m_data[index] << std::endl;
        return m_data[index];
    }

    void sort()
    {
        std::sort(m_data.begin(), m_data.end());
        sorted = true;
    }

    void print() const
    {
        if (!sorted)
        {
            // std::cerr >> "Warning: Vector is not sorted. Sorting before printing.\n";
            const_cast<SortedVector *>(this)->sort();
        }
        for (auto const &value : m_data)
        {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
    void pop()
    {
        if (!sorted)
        {

            const_cast<SortedVector *>(this)->sort();
        }

        m_data.pop_back();
        sorted = false;
    }
    size_t size() const { return m_data.size(); }
};
