#include "BitcoinExchange.hpp"




BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this  = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if(this != &other)
        data_base = other.data_base;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}


void BitcoinExchange::file_traitement(const std::string &filename)
{
    std::ifstream file("data.csv");
    if(!file.is_open())
    {
        throw std::runtime_error("ERROR :  COULD NOT OPEN DATABASE (data.csv).");
    }
    std::string line;
    while(std::getline(file , line))
    {
        size_t virgule = line.find(',');
        if(virgule != std::string::npos)
        {
            std::string date  = line.substr(0,virgule);
            std::string reste = line.substr(virgule + 1);
            float value = std::strtod(reste.c_str(),NULL);
            this->data_base[date] = value;
        }
    }
    file.close();
    
}