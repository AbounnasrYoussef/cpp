#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{


    if (ac != 2)
    {
        std::cerr << "Error: wrong number of arguments." << std::endl;
        return 1;
    }
    
    BitcoinExchange obj;
    obj.file_traitement(av[1]);
    



}