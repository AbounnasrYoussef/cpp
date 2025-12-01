#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Brain b;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    b.setIdea(99, "Coder le CPP04");
    std::cout << "Idea 0: " << b.getIdea(0) << std::endl;
    delete j;
    delete i;
    return 0;
}
