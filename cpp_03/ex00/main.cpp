#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("hamide");
    ClapTrap b;

    a.attack("b");
    b.takeDamage(5);
    b.attack("a");
}