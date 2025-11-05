#include "Fixed.hpp"




Fixed::Fixed()
{
    this-> value = 0;
    std::cout << "Default constructor called" << std::endl;
}





Fixed::Fixed(const Fixed &other)
{
    this->value = other.value;
    std::cout << "Copy constructor called" << std::endl;
}



Fixed::Fixed(const int a)
{
    std::cout<<"int constructor called" << std::endl;
    value = a << fractional_bit;
}


Fixed::Fixed(const float b)
{
    std::cout<<"float constructor called" <<std::endl;
    value = roundf(b* (1 << fractional_bit));

}


Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->value = other.value;
    }
    return *this;

}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}



void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}


float Fixed::toFloat(void) const
{
    return (float)value / (1 << fractional_bit);
}

int Fixed::toInt(void) const
{
    return value >> fractional_bit;
}


std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}