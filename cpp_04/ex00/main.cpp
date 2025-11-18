#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* a = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();

    std::cout << "\n-- Testing sounds --\n";
    a->makeSound();
    d->makeSound();
    c->makeSound();

    std::cout << "\n-- Deleting objects --\n";
    delete a;
    delete d;
    delete c;

    return 0;
}
