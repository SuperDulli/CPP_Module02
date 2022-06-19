#include <iostream>
#include <string>
#include "Fixed.hpp"

int main(void)
{
	{
		Fixed		a;
		Fixed const	b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;

		std::cout << std::string(80, '-') << std::endl;
	}
	{
		Fixed const	a(Fixed(9.66f) / Fixed(3));
		Fixed const	b(Fixed(10) - Fixed(42.4f));
		Fixed const	c(Fixed(1) + Fixed(1234.5678f));

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		std::cout << (Fixed(1) <= Fixed(0.1f)) << std::endl;
		std::cout << (Fixed(0.1f) <= Fixed(1)) << std::endl;
		std::cout << (Fixed(1) <= Fixed(1.0f)) << std::endl;
		std::cout << std::string(80, '-') << std::endl;

		std::cout << (Fixed(1) >= Fixed(0.1f)) << std::endl;
		std::cout << (Fixed(0.1f) >= Fixed(1)) << std::endl;
		std::cout << (Fixed(1) >= Fixed(1.0f)) << std::endl;
		std::cout << std::string(80, '-') << std::endl;

		std::cout << (Fixed(1) == Fixed(0.1f)) << std::endl;
		std::cout << (Fixed(1.0f) == Fixed(1)) << std::endl;
		std::cout << (Fixed(1) == Fixed(1)) << std::endl;
		std::cout << std::string(80, '-') << std::endl;

		std::cout << (Fixed(1) != Fixed(0.1f)) << std::endl;
		std::cout << (Fixed(1.0f) != Fixed(1)) << std::endl;
		std::cout << (Fixed(1) != Fixed(1)) << std::endl;
		std::cout << std::string(80, '-') << std::endl;
	}
	{
		Fixed	d;
		Fixed	e;

		std::cout << Fixed::max(--d, e) << std::endl;
		Fixed::max(--d, e).setRawBits(0b101010 << 8);
		std::cout << d << std::endl;
		std::cout << e << std::endl;
	}
	return 0;
}
