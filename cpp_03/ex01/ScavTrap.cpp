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

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    HitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;
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

void ScavTrap::attack(const std::string &target)
{
    if (HitPoint == 0)
    {
        std::cout << "ScavTrap " << name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }

    if (EnergyPoint == 0)
    {
        std::cout << "ScavTrap " << name << " has no energy left to attack!" << std::endl;
        return;
    }

    EnergyPoint--;

    std::cout << "ScavTrap " << name
              << " fiercely attacks " << target
              << ", causing " << AttackDamage
              << " points of damage!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode.\n";
}
