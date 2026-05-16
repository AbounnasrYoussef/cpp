#include "BitcoinExchange.hpp"




BitcoinExchange::BitcoinExchange()
{
    parseDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}
void BitcoinExchange::trim(std::string& str) const {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        str = "";
        return;
    }
    size_t last = str.find_last_not_of(" \t\r\n");
    str = str.substr(first, (last - first + 1));
}

bool BitcoinExchange::parseDatabase() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file (data.csv)." << std::endl;
        std::exit(1);
    }
    std::string line;
    std::getline(file, line); 

    while (std::getline(file, line)) {
        size_t comma = line.find(',');
        if (comma != std::string::npos) {
            std::string date = line.substr(0, comma);
            std::string rateStr = line.substr(comma + 1);
            float rate = std::strtod(rateStr.c_str(), NULL);
            _database[date] = rate;
        }
    }
    file.close();
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2008 || month < 1 || month > 12 || day < 1 || day > 31) return false;

    
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    }
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap && day > 29) return false;
        if (!isLeap && day > 28) return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    char* endptr;
    double val = std::strtod(valueStr.c_str(), &endptr);
    
    if (*endptr != '\0' || valueStr.empty()) return false;
    if (val < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    value = static_cast<float>(val);
    return true;
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); 
    while (std::getline(file, line)) {
        size_t pipe = line.find('|');
        if (pipe == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipe);
        std::string valueStr = line.substr(pipe + 1);
        trim(date); trim(valueStr);

        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valueStr, value)) continue;

       
        std::map<std::string, float>::const_iterator it = _database.upper_bound(date);
        
        if (it != _database.begin()) {
            --it; 
            float rate = it->second;
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        } else {
            std::cout << "Error: no exchange rate available for or before date " << date << std::endl;
        }
    }
    file.close();
}