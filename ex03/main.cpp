#include <iostream>
#include <string>
#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	printTest(Point const a, Point const b, Point const c, Point const point) {
	bool				result = bsp(a, b, c, point);
	std::string	const	resultStr = (result) ? "inside" : "outside";

	if (result) {
		std::cout << "\x1B[32m"; // GREEN
	} else {
		std::cout << "\x1B[31m"; // RED
	}

	std::cout
	<< point << " is " << resultStr
	<< " of Triangle(" << a << ", " << b << ", " << c << ")."
	<< std::endl;
	std::cout << "\033[0m"; // RESET
}

int main(void)
{
	{
		std::cout << "Test negative examples:" << std::endl;

		Point const a(0.0f, 0.0f);
		Point const b(0.0f, 3.0f);
		Point const c(4.0f, 3.0f);
		Point const p(100.0f, 200.0f);

		printTest(a, b, c, p);
		printTest(a, c, b, p);
		printTest(b, a, c, p);
		printTest(b, c, a, p);
		printTest(c, a, b, p);
		printTest(c, b, a, p);

		Point const a2(0.1f, 0.2f);
		Point const b2(-22.0f, 3.1f);
		Point const c2(4.0f, 3.0f);

		printTest(a2, b2, c2, a2);
		printTest(a2, b2, c2, b2);
		printTest(a2, b2, c2, c2);

		Point const a3(0.0f, 0.0f);
		Point const b3(0.0f, 3.0f);
		Point const c3(3.0f, 3.0f);
		Point const pAB(0.0f, 2.0f);
		Point const pBC(3.0f, 2.0f);
		Point const pCA(1.5f, 1.5f);

		printTest(a3, b3, c3, pAB);
		printTest(a3, b3, c3, pBC);
		printTest(a3, b3, c3, pCA);

		std::cout << std::string(80, '-') << std::endl;
	}
	{
		std::cout << "Test positive examples:" << std::endl;

		Point const a(0.0f, 0.0f);
		Point const b(0.0f, 3.0f);
		Point const c(4.0f, 3.0f);
		Point const p(1.0f, 2.0f);

		printTest(a, b, c, p);
		printTest(a, c, b, p);
		printTest(b, a, c, p);
		printTest(b, c, a, p);
		printTest(c, a, b, p);
		printTest(c, b, a, p);

		Point const a2(-1234.4321f, -42.0f);
		Point const b2(500.2f, -5.0f);
		Point const c2(4.2f, 6.9f);
		Point const p2(0.1f, 0.0f);

		printTest(a2, b2, c2, p2);

		std::cout << std::string(80, '-') << std::endl;
	}
	return 0;
}
