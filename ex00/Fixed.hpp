#ifndef FIXED_H
#define FIXED_H

class Fixed {

	public:

		Fixed(void);
		Fixed(Fixed const& other);
		~Fixed(void);

		Fixed&	operator=(Fixed const& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		static int const	nbOfFractionalBits;

		int					m_value;
};

#endif