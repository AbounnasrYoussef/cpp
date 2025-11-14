#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
    name = "Default";
    HitPoint = 100;
    EnergyPoint = 100;
    AttackDamage = 30;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    HitPoint = 100;
    EnergyPoint = 100;
    AttackDamage = 30;
    std::cout << "ScavTrap name constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap copy assignment called\n";

    if (this != &other)
        ClapTrap::operator=(other);

    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode.\n";
}
