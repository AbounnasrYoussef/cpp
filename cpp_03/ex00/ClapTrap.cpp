#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{

}

ClapTrap::ClapTrap(std::string name)
{
    std::cout<<"ClapTrap " << name << " constructed" <<std::endl; 

}

void ClapTrap::attack(const std::string& target)
{

}


void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{


}


ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name <<  " destructed" <<std::endl;
}