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
	this->m_value = roundf(value * (1 << Fixed::nbOfFractionalBits));
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
	// std::cout << "getRawBits member function called" << std::endl;
	return m_value;
};

void	Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->m_value = raw;
}

float	Fixed::toFloat(void) const {
	return (float) m_value / (1 << Fixed::nbOfFractionalBits);
}

int	Fixed::toInt(void) const {
	return m_value >> Fixed::nbOfFractionalBits;
}

int const	Fixed::nbOfFractionalBits = 8;

std::ostream&	operator<<(std::ostream& os, Fixed const& fixed) {
	os << fixed.toFloat();
	return os;
}
