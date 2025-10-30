#ifndef HUMANB_HPP
    #define HUMANB_HPP


#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
    Weapon *weapon;
	std::string name;
public:
    HumanB();

    HumanB(std::string name);
    void setWeapon(Weapon &wepon);

    void attack();


    ~HumanB();
};










#endif
