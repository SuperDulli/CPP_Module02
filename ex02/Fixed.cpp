#include <cmath> // roundf
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void): m_value(0) {
	// std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int const value) {
	// std::cout << "Int Constructor called" << std::endl;
	m_value = value;
	m_value <<= Fixed::nbOfFractionalBits;
}

Fixed::Fixed(float const value) {
	// std::cout << "Float Constructor called" << std::endl;
	this->m_value = roundf(value * (1 << Fixed::nbOfFractionalBits));
}

Fixed::Fixed(Fixed const& other) {
	// std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const& other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->m_value = other.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const& other) const {
	return m_value > other.getRawBits();
}

bool	Fixed::operator<(Fixed const& other) const {
	return m_value < other.getRawBits();
}

bool	Fixed::operator>=(Fixed const& other) const {
	return m_value >= other.getRawBits();
}

bool	Fixed::operator<=(Fixed const& other) const {
	return m_value <= other.getRawBits();
}

bool	Fixed::operator==(Fixed const& other) const {
	return m_value == other.getRawBits();
}

bool	Fixed::operator!=(Fixed const& other) const {
	return m_value != other.getRawBits();
}

Fixed	Fixed::operator+(Fixed const& other) const {
	Fixed	result;

	result.setRawBits(m_value + other.getRawBits());

	return result;
}

Fixed	Fixed::operator-(Fixed const& other) const {
	Fixed	result;

	result.setRawBits(m_value - other.getRawBits());

	return result;
}

Fixed	Fixed::operator*(Fixed const& other) const {
	return Fixed(toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(Fixed const& other) const {
	return Fixed(toFloat() / other.toFloat());
}

// prefix increment
Fixed&	Fixed::operator++(void) {
	this->m_value += 1;
	return *this;
}

// prefix decrement
Fixed&	Fixed::operator--(void) {
	this->m_value -= 1;
	return *this;
}

// postfix increment
Fixed	Fixed::operator++(int) {
	Fixed	result(*this);	// copy object
	++(*this);				// increment the original
	return result;			// return copy (unmodified)
}

// postfix decrement
Fixed	Fixed::operator--(int) {
	Fixed	result(*this);	// copy object
	--(*this);				// decrement the original
	return result;			// return copy (unmodified)
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
	return m_value / (1 << Fixed::nbOfFractionalBits);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2) {
	return (f1 < f2) ? f1 : f2;
}

Fixed const&	Fixed::min(Fixed const& f1, Fixed const& f2) {
	std::cout << "const min called" << std::endl;
	return (f1 < f2) ? f1 : f2;
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2) {
	return (f1 > f2) ? f1 : f2;
}

Fixed const&	Fixed::max(Fixed const& f1, Fixed const& f2) {
	std::cout << "const max called" << std::endl;
	return (f1 > f2) ? f1 : f2;
}

int const	Fixed::nbOfFractionalBits = 8;

std::ostream&	operator<<(std::ostream& os, Fixed const& fixed) {
	os << fixed.toFloat();
	return os;
}
