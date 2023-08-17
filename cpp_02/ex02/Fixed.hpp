#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Fixed
{
	public:
		//constructors
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &fixed);
		Fixed &operator = (const Fixed &fixed);
		~Fixed();
		//conversion functions
		float toFloat(void) const;
		int toInt(void) const;
		//getter and setter functions
		int getRawBits(void) const;
		void setRawBits(int const raw);
		//increment operators
		Fixed operator ++ (int);
		Fixed operator ++ ();
		//decrement operators
		Fixed operator -- (int);
		Fixed operator -- ();
		//comparison operators
		bool operator < (const Fixed &obj) const;
		bool operator <= (const Fixed &obj) const;
		bool operator > (const Fixed &obj) const;
		bool operator >= (const Fixed &obj) const;
		bool operator == (const Fixed &obj) const;
		bool operator != (const Fixed &obj) const;
		//arithmtic operators
		float operator + (const Fixed &obj) const;
		float operator - (const Fixed &obj) const;
		float operator * (const Fixed &obj) const;
		float operator / (const Fixed &obj) const;
		//min max thing
		static Fixed &max(Fixed &first, Fixed &second);
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(const Fixed &first, const Fixed &second);
		static const Fixed &max(const Fixed &first, const Fixed &second);

	private:
		int raw;
		const static int fbits = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &obj);

#endif