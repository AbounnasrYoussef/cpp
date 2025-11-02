#include "Weapon.hpp"


  Weapon::Weapon(){}

Weapon::Weapon(std::string type) {
        this->type = type;
}

const std::string&  Weapon::getType()
 {
        return type;
};

std::string Weapon::setType(std::string NewType)
{
        type = NewType;
        return NewType;
};

Weapon::~Weapon(){}