#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "[Cat] Default constructor\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "[Cat] Copy constructor\n";
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
        this->type = other.type;

    std::cout << "[Cat] Copy assignment\n";
    return *this;
}

Cat::~Cat()
{
    std::cout << "[Cat] Destructor\n";
}

void Cat::makeSound() const
{
    std::cout << "Meowww...\n";
}
