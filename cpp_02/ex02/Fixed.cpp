#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{

}

Fixed::Fixed(const int n)
{
	value = n << fractionalBits;
}

Fixed::Fixed(const float n)
{
	value = roundf(n * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed()
{

}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		value = other.value;
	return *this;
}

int Fixed::getRawBits(void) const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)value / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return value >> fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const
{
	return value > other.value;
}

bool Fixed::operator<(const Fixed &other) const 
{ 
	return value < other.value; 
}

bool Fixed::operator>=(const Fixed &other) const 
{ 
	return value >= other.value; 
}

bool Fixed::operator<=(const Fixed &other) const 
{ 
	return value <= other.value; 
}

bool Fixed::operator==(const Fixed &other) const 
{ 
	return value == other.value; 
}

bool Fixed::operator!=(const Fixed &other) const 
{ 
	return value != other.value; 
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.value == 0)
	{
		std::cerr << "Erreur : division par zéro !" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	value++;
	return *this;
}

Fixed &Fixed::operator--()
{
	value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	value++;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	value--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
