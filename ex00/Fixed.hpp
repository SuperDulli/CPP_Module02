#ifndef FIXED_H
#define FIXED_H

class Fixed {

	public:

		Fixed(void);
		Fixed(const Fixed& other);
		~Fixed(void);

		Fixed&	operator=(const Fixed& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		static const int	nbOfFractionalBits;

		int					m_value;
};

#endif