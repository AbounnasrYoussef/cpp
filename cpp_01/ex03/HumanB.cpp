#include "HumanB.hpp"


HumanB::HumanB(){
	weapon = NULL;
}


HumanB::HumanB(std::string name)
{
	this->name = name;
	weapon = NULL;
}
HumanB::~HumanB()
{

}

void HumanB::attack()
{
	if(weapon != NULL)
	{
		std::cout<< name << " attacks with their " <<  weapon->getType() << std::endl;
	}
	else 
	{
		std::cout<<  " attacks with their hands" << std::endl;
	}
}


void HumanB::setWeapon(Weapon &wepon)
{
	weapon = &wepon;
}

