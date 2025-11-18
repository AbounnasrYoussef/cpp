#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain created\n";
}

Brain::Brain(const Brain &other)
{
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed\n";
}
