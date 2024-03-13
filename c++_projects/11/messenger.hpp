#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>


class Messenger
{
protected:
    std::string m_message;

public:
    Messenger(std::string& m_message);
    virtual void encryption() = 0;
    virtual void send() ;
};


Messenger::Messenger( std::string& data)
    : m_message(data) {}

template <typename T>
class Rotation : public Messenger
{
public:
    Rotation(std::string& data,const T& rotation);
    void encryption();
    void send();
protected:
    int m_rotation;
};

template<typename T>
Rotation<T>::Rotation(std::string& data,const T& rotation)
    : Messenger(data)
    , m_rotation(rotation) {}



class ROT13 : public Rotation<int>
{
public:
    ROT13(std::string m_message,const int& rotation);
    void encryption() override;
    void send() override;
protected:
    int m_rotation;    
};


ROT13::ROT13(std::string data,const int& rotation)
    : Rotation(data,rotation) 
    ,m_rotation(rotation){
        std::cout << "hiii create rot 13" << std::endl;
    }


void ROT13::encryption()
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


void ROT13::send()
{
    std::cout << "Sending   ROT13 encryption message:" << this->m_message << std::endl;
}


class Atbash : public Messenger
{
public:
    Atbash(std::string m_message);
    void encryption() override;
    void send() override;
};


Atbash::Atbash(std::string message)
    : Messenger(message) {}


void Atbash::encryption()
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


void Atbash::send()
{
    std::cout << "Sending   Atbash encryption message:" << this->m_message << std::endl;
}

class UpperCase : public Messenger
{
public:
    UpperCase(std::string m_message);
    void encryption() override;
    void send() override;
};


UpperCase::UpperCase(std::string message)
    : Messenger(message) {}


void UpperCase::encryption()
{
    std::transform(this->m_message.begin(), this->m_message.end(),
                   this->m_message.begin(),
                   toupper);
}


void UpperCase::send()
{
    std::cout << "Sending   UpperCase encryption message:" << this->m_message << std::endl;
}
class Vigenere : public Rotation<std::string>
{

public:
    Vigenere(std::string m_message,const std::string &key);
    void encryption() override;
    void send() override;
protected:
    std::string m_key;
};



//  Vigenere::Vigenere(std::string text, const std::string &key)
//     : Messenger(text)
//     , m_key(key)
// {}
// {
//     std::transform(
//         text.begin(), text.end(), text.begin(),
//         [key](char c) -> char
//         {
//             if (!std::isalpha(c))
//                 return c;

//             char const pivot = std::isupper(c) ? 'A' : 'a';
//             return char((c - pivot + key.at((c - pivot) % key.size())) % 26 + pivot);
//         });

//     std::cout << "Transformed text: " << text << std::endl;
// }
