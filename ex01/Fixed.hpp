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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

	private:

		static int const	nbOfFractionalBits;

		int					m_value;

};

std::ostream&	operator<<(std::ostream& os, Fixed const& fixed);

#endif
