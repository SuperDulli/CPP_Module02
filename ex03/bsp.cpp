#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {

	if (point == a || point == b || point == c) {
		return false;
	}

	Point const	ab = vector(a, b);
	Point const	bc = vector(b, c);
	Point const	ca = vector(c, a);

	Point const	ap = vector(a, point);
	Point const	bp = vector(b, point);
	Point const	cp = vector(c, point);

	Fixed const abXap = crossProduct(ab, ap);
	Fixed const bcXbp = crossProduct(bc, bp);
	Fixed const caXcp = crossProduct(ca, cp);

	if ((abXap < 0 && bcXbp < 0 && caXcp < 0)
		|| (abXap > 0 && bcXbp > 0 && caXcp > 0)) {
			return true;
	}
	return false;
}
