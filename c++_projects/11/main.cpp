#include "messenger.hpp"

int main()
{   
    ROT13<std::string> message("Hello world");
    message.encryption();
    message.send();
    UpperCase<std::string> M("message");
    M.encryption();
    M.send();
    Atbash<std::string> A("hello abAB");
    A.encryption();
    A.send();
    
    
      

    return 0;
}



