#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat created\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    this->type = other.type;
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
