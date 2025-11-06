#ifndef FIXED_HPP
    #define FIXED_HPP


#include <iostream>
#include <cmath>


class Fixed
{
private:
    int value;
    static const int  fractional_bit = 8;
public:
    Fixed();

    Fixed(const Fixed &other);

    Fixed &operator=(const Fixed &other);

    Fixed(const int a);

    Fixed(const float b);

    int toInt(void) const;


    float toFloat(void) const;




    int getRawBits( void ) const;

    void setRawBits( int const raw );


    ~Fixed();
};



std::ostream &operator<<(std::ostream &os, const Fixed &fixed);















#endif