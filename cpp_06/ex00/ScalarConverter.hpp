#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum eType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    UNKNOWN,
    SCIENTIFIQUE
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &src);
        ~ScalarConverter();

    public:
        static void convert(std::string const &s);
};


#endif
