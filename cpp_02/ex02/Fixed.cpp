#include "Fixed.hpp"


//return ((double)input / (double)(1 << FIXED_POINT_FRACTIONAL_BITS));

// constructor
Fixed::Fixed()
{
	this->raw = 0;
	// cout << "Default constructor called" << endl;
}

//destructor
Fixed::~Fixed()
{
	// cout << "Destructor called" << endl;
}

//overload constructor
Fixed::Fixed(const int num)
{
	this->raw = num << this->fbits;
	// cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float num)
{
	this->raw = round(num * (1 << this->fbits));;
	// cout << "Float constructor called" << endl;
}

// copy constructor
Fixed::Fixed(const Fixed &copy)
{
	// cout << "Copy constructor called" << endl;
	// this->raw = copy.getRawBits();
	*this = copy;
}

// copy assignment operator
Fixed &Fixed::operator = (const Fixed &copy)
{
	// cout << "Copy assignment operator called" << endl;
	this->raw = copy.getRawBits();
	return (*this);
}


//raw bit getter
int Fixed::getRawBits(void) const
{
	return this->raw;
}

//raw bit setter
void Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

//fixed to int
int Fixed::toInt(void) const
{
	return (this->raw >> this->fbits);
}

//fixed to float
float Fixed::toFloat(void) const
{
	return ((double)this->raw / (double)(1 << this->fbits));
}

//output stream overload
std::ostream &operator<<(std::ostream &os, Fixed const &obj)
{
  return os << obj.toFloat();
}

//increment overloads
Fixed Fixed::operator ++ (int)
{
	Fixed obj(*this);
	++this->raw;
	return obj;
}

Fixed Fixed::operator ++ ()
{
	++this->raw;
	return *this;
}

Fixed Fixed::operator -- (int)
{
	Fixed obj(*this);
	--this->raw;
	return obj;
}

Fixed Fixed::operator -- ()
{
	--this->raw;
	return *this;
}

//Arithmetic overloads
float Fixed::operator + (const Fixed &obj) const
{
	return this->toFloat() + obj.toFloat();
}

float Fixed::operator - (const Fixed &obj) const
{
	return this->toFloat() - obj.toFloat();
}

float Fixed::operator * (const Fixed &obj) const
{
	return this->toFloat() * obj.toFloat();
}

float Fixed::operator / (const Fixed &obj) const
{
	return this->toFloat() / obj.toFloat();
}

//comparison operators
bool Fixed::operator < (const Fixed &obj) const
{
	return this->toFloat() < obj.toFloat();
}

bool Fixed::operator <= (const Fixed &obj) const
{
	return this->toFloat() <= obj.toFloat();
}

bool Fixed::operator > (const Fixed &obj) const
{
	return this->toFloat() > obj.toFloat();
}

bool Fixed::operator >= (const Fixed &obj) const
{
	return this->toFloat() >= obj.toFloat();
}

bool Fixed::operator == (const Fixed &obj) const
{
	return this->toFloat() == obj.toFloat();
}

bool Fixed::operator != (const Fixed &obj) const
{
	return this->toFloat() != obj.toFloat();
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return first;
	return second;
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
		return first;
	return second;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first > second)
		return first;
	return second;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first < second)
		return first;
	return second;
}
