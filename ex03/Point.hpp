#ifndef POINT_H
#define POINT_H

#include <ostream>
#include "Fixed.hpp"

class Point {

	public:

		Point(void);
		Point(float const x, float const y);
		Point(Fixed const& x, Fixed const& y);
		Point(Point const& other);
		~Point(void);

		Point&	operator=(Point const& other);

		bool	operator==(Point const& other) const;
		bool	operator!=(Point const& other) const;

		Fixed const& getX(void) const;
		Fixed const& getY(void) const;


	private:

		Fixed const	m_x;
		Fixed const	m_y;

};

std::ostream&	operator<<(std::ostream& os, Point const& point);

Point vector(Point const& start, Point const& end);

Fixed crossProduct(Point const& vector1, Point const& vector2);

#endif
