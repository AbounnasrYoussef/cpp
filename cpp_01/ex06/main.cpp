#include "Harl.hpp"



int main(int ac , char **av)
{
    Harl harl;
    if(ac != 2)
        std::cout<< "error input" << std::endl;
    else
    {
        if(!av[1][0] || !av[1])
        {
            std::cout << "ERROR INPUT" << std::endl;
            return 1;
        }
        harl.complain(av[1]);
    }
}

