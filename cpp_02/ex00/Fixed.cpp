#include "Fixed.hpp"


// constructor
Fixed::Fixed()
{
	this->raw = 0;
	cout << "Default constructor called" << endl;
}

//destructor
Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

// copy constructor
Fixed::Fixed(Fixed &copy)
{
	cout << "Copy constructor called" << endl;
	// this->raw = copy.getRawBits();
	*this = copy;
}

// copy assignment operator
Fixed &Fixed::operator = (const Fixed &copy)
{
	cout << "Copy assignment operator called" << endl;
	this->raw = copy.getRawBits();
	return (*this);
}


//raw bit getter
int Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return this->raw;
}

//raw bit setter
void Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	this->raw = raw;
}
