#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int                 _value;
	static const int    _fractionalBits = 8;

public:
	
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &other);
	~Fixed();

	
	Fixed &operator=(const Fixed &other);

	
	int     getRawBits(void) const;
	void    setRawBits(int const raw);
	float   toFloat(void) const;
	int     toInt(void) const;

	
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// Incrémentation / Décrémentation
	Fixed &operator++();     // pré-incrément
	Fixed &operator--();     // pré-décrément
	Fixed operator++(int);   // post-incrément
	Fixed operator--(int);   // post-décrément

	// Fonctions min / max
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Surcharge de l’opérateur <<
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
