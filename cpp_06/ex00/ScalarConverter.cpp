#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <cstdlib>



ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    (void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void)src;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static void printChar(double value)
{
    if (std::isnan(value) || std::isinf(value))
        std::cout << "char: impossible" << std::endl;
    else if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
    if (std::isnan(value) || std::isinf(value))
        std::cout << "int: impossible" << std::endl;
    else if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value) && value > 0)
        std::cout << "float: +inff" << std::endl;
    else if (std::isinf(value) && value < 0)
        std::cout << "float: -inff" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
                  << "float: " << static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value)
{
    
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value) && value > 0)
        std::cout << "double: +inf" << std::endl;
    else if (std::isinf(value) && value < 0)
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
                  << "double: " << value << std::endl;
}

static eType detectType(std::string const &s)
{
    if ( s.length() == 1 && !isdigit(s[0] ))
        return UNKNOWN;
    size_t i = 0;
    if (s[0] == '-' || s[0] == '+')
        i = 1;
    if (i == s.length())
        return UNKNOWN;
    while (i < s.length())
    {
        if (!std::isdigit(s[i]) &&  (s[i] == 'f' && i != s.length()-1))
            return UNKNOWN;
        i++;
    }
    if (s == "-inff" || s == "+inff" || s == "nanf" )
        return SCIENTIFIQUE;

    if (s == "-inf" || s == "+inf" || s == "nan" || s == "inf" )
        return SCIENTIFIQUE;

    if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
        return CHAR;

    if (s[s.length() - 1] == 'f' && s.find('.') != std::string::npos)
        return FLOAT;

    if (s.find('.') != std::string::npos)
        return DOUBLE;

    
    return INT;
}

int compt(std::string const &s , char c)
{
    int compt = 0;
    for (size_t i = 0; i < s.size() ; i++)
    {
        if (s[i] == c)
            compt++;
            
    }
    return compt;
}

void ScalarConverter::convert(std::string const &s)
{

    if (s.empty() )
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }

    eType type = detectType(s);
    double value = 0.0;
    if (type == CHAR)
        value = static_cast<char>(s[1]);
    else if (type == UNKNOWN ||  (type == FLOAT &&  compt(s,'.') !=  1) || (type == DOUBLE &&  compt(s,'.') !=  1))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }
    else
    {
        char *end;
        if (type == INT)
        {
            long long nb = std::strtoll(s.c_str(), &end, 10);
            if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float:  "<<  static_cast<float>(nb) <<std::endl;
                std::cout << "double: " <<  static_cast<double>(nb) <<std::endl;
                return ;
            }
            value = static_cast<int>(nb);
        }
        else if (type == FLOAT )
            value = static_cast<float>(std::strtof(s.c_str(), &end));
        else if (type == DOUBLE)
            value = std::strtod(s.c_str(), &end);
    }
    if(type == SCIENTIFIQUE)
    {
        char *end;
        value = std::strtod(s.c_str(), &end);
    }
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}