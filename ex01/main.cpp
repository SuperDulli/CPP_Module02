#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed a_neg;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	Fixed const e(-42);
	Fixed const f(-42.42f);
	Fixed const g((float) 1 / 3);
	Fixed const h(2.0f / 3.0f);
	Fixed const pi(103993.0f / 33102); // 3.14159653...
	Fixed const pi2(3.14159653f);

	a = Fixed(1234.4321f);
	a_neg = Fixed(-1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "-a is " << a_neg << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << "g is " << g << std::endl;
	std::cout << "h is " << h << std::endl;
	std::cout << "pi is " << pi << std::endl;
	std::cout << "pi2 is " << pi2 << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "-a is " << a_neg.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << "f is " << f.toInt() << " as integer" << std::endl;
	std::cout << "g is " << g.toInt() << " as integer" << std::endl;
	std::cout << "h is " << h.toInt() << " as integer" << std::endl;

	return 0;
}
