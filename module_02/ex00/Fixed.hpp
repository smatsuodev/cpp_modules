#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	static const int fractional_bits = 8;
	int value;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed &operator=(const Fixed &fixed);
	int getRawBits() const;
	void setRawBits(const int raw);
};

#endif
