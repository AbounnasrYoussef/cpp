#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Testing ClapTrap ===\n";
    ClapTrap c("Clappy");
    c.attack("Target1");
    c.takeDamage(5);
    c.beRepaired(3);

    std::cout << "\n=== Testing ScavTrap ===\n";
    ScavTrap s("Scavy");
    s.attack("Target2");
    s.takeDamage(20);
    s.beRepaired(10);
    s.guardGate();

    std::cout << "\n=== Testing FragTrap ===\n";
    FragTrap f("Fraggy");
    f.attack("Target3");
    f.takeDamage(30);
    f.beRepaired(15);
    f.highFivesGuys();

    return 0;
}
