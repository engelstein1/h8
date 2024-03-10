#include <memory>
#include <iostream>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T m_data;
        std::unique_ptr<Node> next;

        Node(T const &data) : m_data(data), next(nullptr){};
    };
    std::unique_ptr<Node> m_head;

public:
    LinkedList() : m_head(nullptr){};
    LinkedList(const LinkedList &other);
    ~LinkedList() = default;

    void prepend(const T &data);
   

    void removeHead();

    T getHeadData();

    void printl() const;

    bool isEmpty() const;
};

template <typename T>
void LinkedList<T>::printl() const
{
    if (isEmpty())
    {
        std::cout << "List is empty" << std::endl;
    }
    auto current = m_head.get();
    std::cout << "[";
    if (current != nullptr)
    {
        std::cout << current->m_data;
        current = current->next.get();
    }
    while (current != nullptr)
    {
        std::cout << "," << current->m_data;
        current = current->next.get();
    }
    std::cout << "]";
    std::cout << std::endl;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return m_head == nullptr;
};

template <typename T>
void LinkedList<T>::prepend(const T &m_data)
{
    auto newNode = std::make_unique<Node>(m_data);
    newNode->next = std::move(m_head);
    m_head = std::move(newNode);
};

template <typename T>
void LinkedList<T>::removeHead()
{
    if (m_head != nullptr)
    {
        m_head = std::move(m_head->next);
    }
};

template <typename T>
T LinkedList<T>::getHeadData()
{
    return m_head->m_data;
};

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &other)
{
    // #option without the class method#


    // if(other.m_head)
    // {
    //     auto current = other.m_head.get();
    //     auto newNode = std::make_unique<Node>(current->m_data);
    //     m_head = std::move(newNode);
    //     current = current->next.get();
    //     while (current!= nullptr)
    //     {
    //         auto newNode = std::make_unique<Node>(current->m_data);
    //         newNode->next = std::move(m_head);
    //         m_head = std::move(newNode);
    //         current = current->next.get();
    //     }
    // }

    
    // #option with the class method#


    // auto current = other.m_head.get();
    // while(current!= nullptr)
    // {
    //     prepend(current->m_data);
    //     current = current->next.get();
        
    // }
    
        if (other.m_head) {
            // Copy the first node
            m_head = std::make_unique<Node>(other.m_head->m_data);

            // Copy the remaining nodes
            Node* current = m_head.get();
            Node* otherCurrent = other.m_head->next.get();
            while (otherCurrent) {
                current->next = std::make_unique<Node>(otherCurrent->m_data);
                current = current->next.get();
                otherCurrent = otherCurrent->next.get();
            }
        }
    }







