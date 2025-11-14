#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
    name = "Default";
    HitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string &name)
{
    this->name = name;
    HitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap name constructor called\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode.\n";
}
