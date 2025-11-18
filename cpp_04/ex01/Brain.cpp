#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[Brain] Default constructor\n";
}

Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "[Brain] Copy constructor\n";
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    std::cout << "[Brain] Copy assignment\n";
    return *this;
}

Brain::~Brain()
{
    std::cout << "[Brain] Destructor\n";
}

void Brain::setIdea(int index, const std::string &str)
{
    if (index >= 0 && index < 100)
        ideas[index] = str;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}
