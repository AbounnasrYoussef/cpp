#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("unknown"), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (hitPoint > 0 && energyPoint > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoint--;
    }
    else
        std::cout << "ClapTrap he can't attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoint <= 0)
    {
        std::cout << "ClapTrap " << name << " is already destroyed" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << name << " takes " << amount 
              << " points of damage!" << std::endl;

    if (amount >= hitPoint)
    {
        hitPoint = 0;
        std::cout << "ClapTrap " << name << " has been destroyed" << std::endl;
    }
    else
    {
        hitPoint -= amount;
        std::cout << "ClapTrap " << name << " now has " 
                  << hitPoint << " hit points left" << std::endl;
    }
}


void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoint > 0 && energyPoint > 0)
    {
        std::cout << "ClapTrap " << name << " repairs itself for "
                  << amount << " hit points!" << std::endl;
        hitPoint += amount;
        energyPoint--;
    }
    else
        std::cout << "ClapTrap " << name << " can't be repaired!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructed" << std::endl;
}