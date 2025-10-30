#ifndef WEAPON_HPP
    #define WEAPON_HPP

#include <string>


class  Weapon
{
private:
    std::string type;
public:
    Weapon() {};

    Weapon(std::string type) {};

    std::string& getType();

    std::string setType(std::string NewType);

};












#endif