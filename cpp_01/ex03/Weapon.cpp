#include "Weapon.hpp"



std::string&  Weapon::getType()
 {
        return type;
};

std::string Weapon::setType(std::string NewType)
{
        type = NewType;
        return NewType;
};