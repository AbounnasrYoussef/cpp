#include "functions.hpp"
#include <iostream>

int main()
{
    Base* p = generate();

    std::cout << "identify(pointer)  : ";
    identify(p);

    std::cout << "identify(reference): ";
    identify(*p);

    delete p;
    return 0;
}