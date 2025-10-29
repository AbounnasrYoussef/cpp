#include "Zombie.hpp"





int main()
{
    Zombie* z = newZombie("zooom");
    z->announce();
    delete z;
    randomChump("Bar");
    return 0;
}