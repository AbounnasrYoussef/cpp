#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog created\n";
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
    this->brain = new Brain(*other.brain);
    std::cout << "Dog copied\n";
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;

        delete this->brain;
        this->brain = new Brain(*other.brain); 
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destroyed\n";
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!\n";
}
