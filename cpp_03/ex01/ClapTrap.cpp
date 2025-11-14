#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("unknown"), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
    std::cout << "ClapTrap default constructed" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name)
    : name(name), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
    std::cout << "ClapTrap constructor called\n";
}


void ClapTrap::attack(const std::string &target)
{
    if (HitPoint > 0 && EnergyPoint > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoint--;
    }
    else
        std::cout << "ClapTrap he can't attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoint <= 0)
    {
        std::cout << "ClapTrap " << name << " is already destroyed" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << name << " takes " << amount 
              << " points of damage!" << std::endl;

    if (amount >= HitPoint)
    {
        HitPoint = 0;
        std::cout << "ClapTrap " << name << " has been destroyed" << std::endl;
    }
    else
    {
        HitPoint -= amount;
        std::cout << "ClapTrap " << name << " now has " 
                  << HitPoint << " hit points left" << std::endl;
    }
}


void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoint > 0 && EnergyPoint > 0)
    {
        std::cout << "ClapTrap " << name << " repairs itself for "
                  << amount << " hit points!" << std::endl;
        HitPoint += amount;
        EnergyPoint--;
    }
    else
        std::cout << "ClapTrap " << name << " can't be repaired!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructed" << std::endl;
}