#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat created\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    *this = other;
    std::cout << "copy constructor Worng Cat" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    this->type = other.type;
    std::cout << "operator Worng Cat" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed\n";
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat meows ???\n";
}
