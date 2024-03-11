#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

template <typename T>
class Messenger
{
protected:
    T m_message;

public:
    Messenger(T m_message);
    virtual void encryption() = 0;
    virtual void send() = 0;
};

template <typename T>
Messenger<T>::Messenger(T data)
    : m_message(data) {}

template <typename T>
class ROT13 : public Messenger<T>
{
public:
    ROT13(T m_message);
    void encryption() override;
    void send() override;
};

template <typename T>
ROT13<T>::ROT13(T message)
    : Messenger<T>(message) {}

template <typename T>
void ROT13<T>::encryption()
{
    std::transform(
        begin(this->m_message), end(this->m_message), begin(this->m_message),
        [](char c) -> char
        {
            if (not std::isalpha(c))
                return c;

            char const pivot = std::isupper(c) ? 'A' : 'a';
            return char((c - pivot + 13) % 26 + pivot);
        });
}

template <typename T>
void ROT13<T>::send()
{
    std::cout << "Sending   ROT13 encryption message:" << this->m_message << std::endl;
}

template <typename T>
class Atbash : public Messenger<T>
{
public:
    Atbash(T m_message);
    void encryption() override;
    void send() override;
};

template <typename T>
Atbash<T>::Atbash(T message)
    : Messenger<T>(message) {}

template <typename T>
void Atbash<T>::encryption()
{
    std::transform(
        this->m_message.begin(), this->m_message.end(), this->m_message.begin(),
        [](char c) -> char
        {
            if (!std::isalpha(c))
            {
                return c; 
            }
            char pivot = std::isupper(c) ? 'A' : 'a';
            return char('Z' - (std::toupper(c) - pivot)); 
        });
}

template <typename T>
void Atbash<T>::send()
{
    std::cout << "Sending   Atbash encryption message:" << this->m_message << std::endl;
}

template <typename T>
class UpperCase : public Messenger<T>
{
public:
    UpperCase(T m_message);
    void encryption() override;
    void send() override;
};

template <typename T>
UpperCase<T>::UpperCase(T message)
    : Messenger<T>(message) {}

template <typename T>
void UpperCase<T>::encryption()
{
    std::transform(this->m_message.begin(), this->m_message.end(),
                   this->m_message.begin(),
                   toupper);
}

template <typename T>
void UpperCase<T>::send()
{
    std::cout << "Sending   UpperCase encryption message:" << this->m_message << std::endl;
}