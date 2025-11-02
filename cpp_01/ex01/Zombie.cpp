#include "Zombie.hpp"


Zombie::Zombie() : name("Unnamed") {
    std::cout << name << " created" << std::endl;
}


Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << name << " created " << std::endl;
}

void Zombie::announce()
{
    std::cout<< name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}




Zombie::~Zombie(){
        std::cout<< name <<" is destroyed"<< std::endl;
};


void Zombie::setName(const std::string &n) {
    name = n;
}
