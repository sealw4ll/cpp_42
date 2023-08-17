#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed &fixed);
		Fixed &operator = (const Fixed &fixed);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int raw;
		const static int fbits = 8;
};

#endif