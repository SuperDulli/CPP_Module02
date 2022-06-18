#ifndef FIXED_H
#define FIXED_H

#include <ostream>

class Fixed {

	public:

		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const& other);
		~Fixed(void);

		Fixed&	operator=(Fixed const& other);

		bool	operator>(Fixed const& other) const;
		bool	operator<(Fixed const& other) const;
		bool	operator>=(Fixed const& other) const;
		bool	operator<=(Fixed const& other) const;
		bool	operator==(Fixed const& other) const;
		bool	operator!=(Fixed const& other) const;

		Fixed	operator+(Fixed const& other) const;
		Fixed	operator-(Fixed const& other) const;
		Fixed	operator*(Fixed const& other) const;
		Fixed	operator/(Fixed const& other) const;

		// Prefix
		Fixed&	operator++(void);
		Fixed&	operator--(void);

		// Postfix
		Fixed	operator++(int);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&	min(Fixed& f1, Fixed& f2);
		static Fixed&	min(Fixed const& f1, Fixed const& f2);

		static Fixed&	max(Fixed& f1, Fixed& f2);
		static Fixed&	max(Fixed const& f1, Fixed const& f2);

	private:

		static int const	nbOfFractionalBits;

		int					m_value;

};

std::ostream&	operator<<(std::ostream& os, Fixed const& fixed);

#endif
