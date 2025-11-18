#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat created\n";
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
    this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->type = other.type;

        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const
{
    std::cout << "Meowww !\n";
}
