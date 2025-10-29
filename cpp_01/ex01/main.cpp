#include "Zombie.hpp"


void randomChump(std::string name) {
    Zombie z(name);    // créé sur la stack
    z.announce();      // annonce immédiatement
    // destructeur appelé automatiquement à la fin de la fonction
}

Zombie* newZombie(std::string name) {
    return new Zombie(name); // créé sur le heap, doit être delete plus tard
}



int main()
{
    Zombie* z = newZombie("Zombie");
    z->announce();
    delete z;
    randomChump("StackZombie"); // destruction automatique

    int N = 1;
    Zombie* horde = zombieHorde(N, "HordeZombie");

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete[] horde; // libération mémoire du tableau

    return 0;
}