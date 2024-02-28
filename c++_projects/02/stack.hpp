#include <iostream>
class Stack
{
    int *m_top;
    int m_capacity;
    int *m_elements;
public:
    Stack(int capacity=10);
    bool push(int value);
    int pop();
    int elements()const;

};
std::ostream &operator<<(std::ostream &os, const Stack &stack);
int peek(Stack &stack );
bool isEmpty(Stack &stack);
bool isFull(Stack &stack);



