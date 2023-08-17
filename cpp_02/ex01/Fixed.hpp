#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &fixed);
		Fixed &operator = (const Fixed &fixed);
		~Fixed();
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int raw;
		const static int fbits = 8;
};

std::ostream &operator << (std::ostream &os, Fixed const &obj);
#endif