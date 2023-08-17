
#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(3.01f);
	cout << "--------------------------------------------" << endl;
	cout << "increment overload test" << endl;
	cout << "initial value: " << a << endl;
	cout << "pre-increment value: "<< ++a << endl;
	cout << "post-increment: " << a++ << endl;
	cout << "current value: "<< a << endl;
	cout << "pre-decrement value: "<< --a << endl;
	cout << "post-decrement: " << a-- << endl;
	cout << "current value: "<< a << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Arithmetic overload test" << endl;
	cout << "b: " << b << " | c: " << c << endl;
	cout << "b + c = " << b + c << endl;
	cout << "b - c = " << b - c << endl;
	cout << "b * c = " << b * c << endl;
	cout << "b / c = " << b / c << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Comparison test" << endl;
	cout << "b > c is " << (b > c) << endl;
	cout << "b < c is " << (b < c) << endl;
	cout << "b == c is " << (b == c) << endl;
	cout << "b != c is " << (b != c) << endl;
	cout << "--------------------------------------------" << endl;
	cout << "min max test" << endl;
	cout << "max value: "<< Fixed::max( b, c ) << endl;
	cout << "min value: "<< Fixed::min( b, c ) << endl;
	cout << "--------------------------------------------" << endl;
	return 0;
}