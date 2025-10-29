#include "Zombie.hpp"


void randomChump( std::string name )
{
    Zombie zombie(name); // hada creation local f stack
    zombie.announce();
}