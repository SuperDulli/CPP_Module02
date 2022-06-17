#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void): m_value(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
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

const int	Fixed::nbOfFractionalBits = 8;