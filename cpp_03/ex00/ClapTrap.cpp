#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "unknown";
    hitPoint = 10;
    energyPoint = 10;
    attackDamage = 0;
    std::cout << "ClapTrap default constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    hitPoint = 10;
    energyPoint = 10;
    attackDamage = 0;
    std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if(hitPoint > 0 && energyPoint > 0)
    {
        std::cout << "ClapTrap attack " << target << " causes " << attackDamage << std::endl;
        energyPoint--;
    }
    else 
        std::cout << "ClapTrap he can't attack" <<std::endl;
    
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(hitPoint > 0)
    {
         std::cout << "ClapTrap take damage  of " <<amount << std::endl;
         if(amount > hitPoint)
            hitPoint= 0;
        else
            hitPoint -= amount; 
    }

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(hitPoint > 0 && energyPoint > 0)
    {
        std::cout<<"be repaired " << amount <<std::endl;
        hitPoint +=amount;
        energyPoint--;
    }
    else
        std::cout << " he can't be repaired" <<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructed" << std::endl;
}