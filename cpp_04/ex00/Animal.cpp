#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "[Animal] Default constructor\n";
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "[Animal] Copy constructor\n";
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "[Animal] Copy assignment\n";
    return *this;
}

Animal::~Animal()
{
    std::cout << "[Animal] Destructor\n";
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "[Animal] makes a mysterious sound...\n";
}
