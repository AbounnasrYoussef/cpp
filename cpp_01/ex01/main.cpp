#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie z(name);
    z.announce();
}

Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}

int main()
{
    Zombie *z = newZombie("Zombie");
    z->announce();
    delete z;
    randomChump("StackZombie");

    int N = 1;
    Zombie *horde = zombieHorde(N, "HordeZombie");

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete[] horde;

    return 0;
}