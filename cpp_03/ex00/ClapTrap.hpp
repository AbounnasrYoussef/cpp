#ifndef CLAPTRAP_HPP
    #define CLAPTRAP_HPP

#include <string>
#include <iostream>


class ClapTrap
{
    private:
        std::string name;
        int hitPoint = 10; // representer lina la vie 
        int energyPoint = 10;
        int attackDamage = 0;
    public:
        ClapTrap();

        ClapTrap(std::string name);

        void attack(const std::string& target);

        void takeDamage(unsigned int amount);

        void beRepaired(unsigned int amount);

        ~ClapTrap();
};













#endif