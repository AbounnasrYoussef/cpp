#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal created\n";
}

AAnimal::AAnimal(const AAnimal &other)
{
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    this->type = other.type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destroyed\n";
}

std::string AAnimal::getType() const
{
    return this->type;
}
