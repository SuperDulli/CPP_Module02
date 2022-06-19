#include <iostream>
#include "Point.hpp"

Point::Point(void): m_x(0), m_y(0) {}

Point::Point(float const x, float const y)
	: m_x(x), m_y(y) {}

Point::Point(Fixed const& x, Fixed const& y)
	: m_x(x.toFloat()), m_y(y.toFloat()) {}

Point::Point(Point const& other)
	: m_x(other.getX()), m_y(other.getY()) {}

Point::~Point(void) {}

Point&	Point::operator=(Point const& other) {
	*this = other;
	return *this;
}

bool	Point::operator==(Point const& other) const {
	return (m_x == other.getX() && m_y == other.getY()) ? true : false;
}

bool	Point::operator!=(Point const& other) const {
	return (m_x != other.getX() || m_y != other.getY()) ? true : false;
}

Fixed const&	Point::getX(void) const { return m_x; }

Fixed const&	Point::getY(void) const { return m_y; }

std::ostream&	operator<<(std::ostream& os, Point const& point) {
	os << "Point(" << point.getX() << ", " << point.getY() << ")";
	return os;
}

Point	Point::vector(Point const& start, Point const& end) {
	return Point(end.getX() - start.getX(), end.getY() - start.getY());
}

Fixed	Point::crossProduct(Point const& vector1, Point const& vector2) {
	return Fixed((vector1.getX() * vector2.getY()) - (vector2.getX() * vector1.getY()));
}
