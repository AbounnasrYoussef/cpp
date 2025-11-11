#include "ClapTrap.hpp"







int main()
{
    ClapTrap a("hello");
    ClapTrap b;
    a.attack("b");
    b.takeDamage(5);
    b.attack("a");


}