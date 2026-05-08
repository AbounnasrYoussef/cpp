#ifndef  BITCOINEXCHANGE__HPP
#define  BITCOINEXCHANGE__HPP


#include <map>
#include <string>
#include <iostream>


class BitcoinExchange
{
    private:
        std::map<std::string, double> data_base;


    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();


        void file_traitement(const std::string &filename);



};

#endif