#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "[Dog] Default constructor\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    this->brain = new Brain(*other.brain);
    std::cout << "[Dog] Copy constructor\n";
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;

        delete this->brain;                 // éviter fuite mémoire
        this->brain = new Brain(*other.brain); // deep copy
    }
    std::cout << "[Dog] Copy assignment\n";
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "[Dog] Destructor\n";
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!\n";
}
