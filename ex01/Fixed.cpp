#include <cmath> // roundf
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void): m_value(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int const value) {
	std::cout << "Int Constructor called" << std::endl;
	m_value = value;
	m_value <<= Fixed::nbOfFractionalBits;
}

Fixed::Fixed(float const value) {
	std::cout << "Float Constructor called" << std::endl;
	m_value = roundf(value);
	float	frac = value - m_value;
	m_value <<= Fixed::nbOfFractionalBits;

	for (int i = 0; i < Fixed::nbOfFractionalBits; i++) {
		frac *= 2;
		if (frac > 1.0f) {
			m_value += 1 << (Fixed::nbOfFractionalBits - i - 1);
			frac -= 1.0f;
		}
	}

}

Fixed::Fixed(Fixed const& other) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->m_value = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return m_value;
};

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->m_value = raw;
}

float	Fixed::toFloat(void) const {
	float	f = 0;

	for (int i = 0; i < Fixed::nbOfFractionalBits; i++)
	{
		if (m_value & (1 << i)) {
			f += pow2(Fixed::nbOfFractionalBits - i);
		}
	}
	f += m_value >> Fixed::nbOfFractionalBits;
	return f;
}

int	Fixed::toInt(void) const {
	return m_value >> Fixed::nbOfFractionalBits;
}

float	Fixed::pow2(int power) const {
	int	const	base = 2;
	bool const	negative = power >= 0 ? true : false;
	int			value = base;

	if (!power) {
		return 1.0;
	}
	for (int i = 0; i < power; i++) {
		value *= base;
	}

	return negative ? 1 / (float) value : (float) value;
}

int const	Fixed::nbOfFractionalBits = 8;

std::ostream&	operator<<(std::ostream& os, Fixed const& fixed) {
	os << fixed.toFloat();
	return os;
}
