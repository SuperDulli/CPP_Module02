#include <iostream>
#include <string>
#include <iomanip>
#include "Fixed.hpp"

void	printTableRow(Fixed const& f1, Fixed const& f2);

int main(void)
{
	{
		std::cout << "--- Test from subject ---" << std::endl;
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
		std::cout << "--- Arthmetic operators ---" << std::endl;
		Fixed const	a(9.66f);
		Fixed const	b(3);
		Fixed const	c(10);
		Fixed const	d(42.4f);
		Fixed const	e(1);
		Fixed const	f(1234.5678f);
		Fixed const	n(-1);

		std::cout << "Addition:" << std::endl;
		std::cout << a << " + " << b << " = " << a + b << std::endl;
		std::cout << c << " + " << d << " = " << c + d << std::endl;
		std::cout << e << " + " << f << " = " << e + f << std::endl;
		std::cout << f << " + " << d << " = " << f + d << std::endl;
		std::cout << std::string(80, '-') << std::endl;

		std::cout << "Subtraction:" << std::endl;
		std::cout << a << " - " << b << " = " << a - b << std::endl;
		std::cout << c << " - " << d << " = " << c - d << std::endl;
		std::cout << e << " - " << f << " = " << e - f << std::endl;
		std::cout << f << " - " << d << " = " << f - d << std::endl;
		std::cout << std::string(80, '-') << std::endl;

		std::cout << "Multiplication:" << std::endl;
		std::cout << a << " * " << n << " = " << a * n << std::endl;
		std::cout << n << " * " << n << " = " << n * n << std::endl;
		std::cout << a << " * " << b << " = " << a * b << std::endl;
		std::cout << b << " * " << a << " = " << b * a << std::endl;
		std::cout << c << " * " << d << " = " << c * d << std::endl;
		std::cout << e << " * " << f << " = " << e * f << std::endl;
		std::cout << f << " * " << d << " = " << f * d << std::endl;
		std::cout << std::string(80, '-') << std::endl;

		std::cout << "Division:" << std::endl;
		std::cout << a << " / " << n << " = " << a / n << std::endl;
		std::cout << n << " / " << a << " = " << n / a << std::endl;
		std::cout << a << " / " << b << " = " << a / b << std::endl;
		std::cout << c << " / " << d << " = " << c / d << std::endl;
		std::cout << d << " / " << c << " = " << d / c << std::endl;
		std::cout << e << " / " << f << " = " << e / f << std::endl;
		std::cout << f << " / " << d << " = " << f / d << std::endl;
		std::cout << std::string(80, '-') << std::endl;
	}
	{
		std::cout << "--- Comparison operators ---" << std::endl;
		Fixed const	z(0);
		Fixed const	a(1);
		Fixed const	b(0.1f);
		Fixed const	c(1);
		Fixed const	d(-0.1f);

		std::cout
		<< std::setw(10) << "lhs" << "|"
		<< std::setw(10) << "rhs" << "||"
		<< std::setw(4) << ">" << "|"
		<< std::setw(4) << "<" << "|"
		<< std::setw(4) << ">=" << "|"
		<< std::setw(4) << "<=" << "|"
		<< std::setw(4) << "==" << "|"
		<< std::setw(4) << "!=" << std::endl;
		printTableRow(z, a);
		printTableRow(a, z);
		printTableRow(a, b);
		printTableRow(b, a);
		printTableRow(c, b);
		printTableRow(b, d);
		printTableRow(b, b);
		std::cout << std::string(80, '-') << std::endl;
	}
	{
		std::cout << "--- increment & decrement operators ---" << std::endl;
		Fixed	z(0);
		Fixed	a(1);
		Fixed	b(a);

		std::cout << "increment:" << std::endl;

		b = Fixed(1);
		std::cout
		<< "b=" << b << " a=" << a
		<< " (b++ > a) ? " << (b++ > a)
		<< " b=" << b << " a=" << a
		<< std::endl;
		
		b = Fixed(1);
		std::cout
		<< "b=" << b << " a=" << a
		<< " (++b > a) ? " << (++b > a)
		<< " b=" << b << " a=" << a
		<< std::endl;

		std::cout << std::string(80, '-') << std::endl;

		std::cout << "decrement:" << std::endl;

		b = Fixed(1);
		std::cout
		<< "b=" << b << " a=" << a
		<< " (b-- > a) ? " << (b-- > a)
		<< " b=" << b << " a=" << a
		<< std::endl;
		
		b = Fixed(1);
		std::cout
		<< "b=" << b << " a=" << a
		<< " (--b > a) ? " << (--b > a)
		<< " b=" << b << " a=" << a
		<< std::endl;

		std::cout << std::string(80, '-') << std::endl;
	}
	{
		std::cout << "--- min & max non-member functions ---" << std::endl;
		Fixed		result;
		
		Fixed		z(0);
		Fixed		a(42);
		Fixed		b(-42.42f);
		Fixed		c(42);
		Fixed		d(-42.42f);

		Fixed const	z_const(0);
		Fixed const	a_const(42);
		Fixed const	b_const(-42.42f);
		Fixed const	c_const(42);
		Fixed const	d_const(-42.42f);

		std::cout << "min:" << std::endl;
		std::cout << "min(" << z << "," << a << ") = " << Fixed::min(z, a) << std::endl;
		std::cout << "min(" << a << "," << b << ") = " << Fixed::min(a, b) << std::endl;
		std::cout << "min with one const parameter:" << std::endl;
		std::cout << "min(" << a_const << "," << b << ") = " << Fixed::min(a_const, b) << std::endl;
		std::cout << "min(" << a << "," << b_const << ") = " << Fixed::min(a, b_const) << std::endl;
		std::cout << "min with two const parameters:" << std::endl;
		std::cout << "min(" << a_const << "," << b_const << ") = " << Fixed::min(a_const, b_const) << std::endl;
		std::cout << std::string(80, '-') << std::endl;

		std::cout << "max:" << std::endl;
		std::cout << "max(" << z << "," << a << ") = " << Fixed::max(z, a) << std::endl;
		std::cout << "max(" << a << "," << b << ") = " << Fixed::max(a, b) << std::endl;
		std::cout << "max with one const parameter:" << std::endl;
		std::cout << "max(" << a_const << "," << b << ") = " << Fixed::max(a_const, b) << std::endl;
		std::cout << "max(" << a << "," << b_const << ") = " << Fixed::max(a, b_const) << std::endl;
		std::cout << "max with two const parameters:" << std::endl;
		std::cout << "max(" << a_const << "," << b_const << ") = " << Fixed::max(a_const, b_const) << std::endl;
		std::cout << std::string(80, '-') << std::endl;

		std::cout << "Try to manipulate the return value:" << std::endl;
		result = Fixed::min(a,b);
		result.setRawBits(1);
		std::cout << result << std::endl;

		result = Fixed::max(a,b);
		result.setRawBits(1);
		std::cout << result << std::endl;

		Fixed const	result_const = Fixed::min(a,b_const);
		// result_const.setRawBits(1); // not allowed on const objects
		std::cout << result_const << std::endl;

		Fixed const	result_const2 = Fixed::max(a,b_const);
		// result_const2.setRawBits(1); // not allowed on const objects
		std::cout << result_const2 << std::endl;

		std::cout << std::string(80, '-') << std::endl;
	}
	std::cout << "--- End of tests ---" << std::endl;
	return 0;
}

void	printTableRow(Fixed const& f1, Fixed const& f2) {
	std::cout
	<< std::setw(10) << f1 << "|" << std::setw(10) << f2 << "||"
	<< std::setw(4) << (f1 > f2) << "|"
	<< std::setw(4) << (f1 < f2) << "|"
	<< std::setw(4) << (f1 >= f2) << "|"
	<< std::setw(4) << (f1 <= f2) << "|"
	<< std::setw(4) << (f1 == f2) << "|"
	<< std::setw(4) << (f1 != f2)
	<< std::endl;
}
