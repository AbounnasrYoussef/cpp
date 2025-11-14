#ifndef CLAPTRAP_HPP
    #define CLAPTRAP_HPP

#include <string>
#include <iostream>



// class ClapTrap
// {
//     private:
//         std::string name;
//         unsigned int HitPoint;
//         unsigned int EnergyPoint;
//         unsigned int AttackDamage;
//     public:
//         ClapTrap();

//         ClapTrap(std::string name);

//         void attack(const std::string& target);

//         void takeDamage(unsigned int amount);

//         void beRepaired(unsigned int amount);

//         ~ClapTrap();
// };






class ClapTrap {
protected:    // au lieu de private
    std::string name;
    unsigned int HitPoint;
    unsigned int EnergyPoint;
    unsigned int AttackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};







#endif