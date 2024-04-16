#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	static const int fractional_bits = 8;
	int value;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed &operator=(const Fixed &fixed);
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	float toInt() const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &value);

#endif
