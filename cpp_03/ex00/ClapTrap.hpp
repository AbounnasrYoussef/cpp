#ifndef CLAPTRAP_HPP
    #define CLAPTRAP_HPP

#include <string>
#include <iostream>


class ClapTrap
{
    private:
        std::string name;
        unsigned int hitPoint; // ki representer lina la vie 
        unsigned int energyPoint;
        unsigned int attackDamage;
    public:
        ClapTrap();

        ClapTrap(std::string name);

        void attack(const std::string& target);

        void takeDamage(unsigned int amount);

        void beRepaired(unsigned int amount);

        ~ClapTrap();
};













#endif