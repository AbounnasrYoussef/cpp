#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    name = "Default";
    HitPoint = 100;
    EnergyPoint = 100;
    AttackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string &name) :ClapTrap(name)
{
    HitPoint = 100;
    EnergyPoint = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destructor called\n";
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " requests a positive high five!\n";
}
