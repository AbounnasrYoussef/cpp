#include "ClapTrap.hpp"
#include "ScavTrap.hpp"





int main()
{
    ScavTrap a("Youssef");
    ScavTrap b("Enemy");

    a.attack("Enemy");
    b.takeDamage(20);

    b.attack("Youssef");
    a.takeDamage(15);

    a.guardGate(); 

    return 0;
}
