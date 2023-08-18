#include "Cat.hpp"

Cat::Cat()
{
	cout << "Cat default constructor called" << endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	cout << "Cat default destructor called" << endl;
	delete this->brain;
}

Cat::Cat(Cat &copy)
{
	cout << "Copy constructor called" << endl;
	*this = copy;
}

Cat &Cat::operator = (const Cat &copy)
{
	cout << "Copy assignment operator called" << endl;
	(void)copy;
	return (*this);
}

void Cat::makeSound() const
{
	cout << "intense meowing noises..." << endl;
}

WrongCat::WrongCat()
{
	cout << "WrongCat default constructor called" << endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	cout << "WrongCat default destructor called" << endl;
}

void WrongCat::makeSound() const
{
	cout << "intense meowing noises..." << endl;
}