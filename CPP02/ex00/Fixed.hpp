#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed &operator=(const Fixed &fixed);
		Fixed(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);	
};

#endif
