#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "[Cat] Default constructor\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    this->brain = new Brain(*other.brain);
    std::cout << "[Cat] Copy constructor\n";
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->type = other.type;

        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    std::cout << "[Cat] Copy assignment\n";
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "[Cat] Destructor\n";
}

void Cat::makeSound() const
{
    std::cout << "Meow...\n";
}
