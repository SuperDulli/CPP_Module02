#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {

	if (point == a || point == b || point == c) {
		return false;
	}

	Point const	ab = Point::vector(a, b);
	Point const	bc = Point::vector(b, c);
	Point const	ca = Point::vector(c, a);

	Point const	ap = Point::vector(a, point);
	Point const	bp = Point::vector(b, point);
	Point const	cp = Point::vector(c, point);

	Fixed const abXap = Point::crossProduct(ab, ap);
	Fixed const bcXbp = Point::crossProduct(bc, bp);
	Fixed const caXcp = Point::crossProduct(ca, cp);

	if ((abXap < 0 && bcXbp < 0 && caXcp < 0)
		|| (abXap > 0 && bcXbp > 0 && caXcp > 0)) {
			return true;
	}
	return false;
}
