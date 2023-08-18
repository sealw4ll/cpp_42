#include "Dog.hpp"

Dog::Dog()
{
	cout << "Dog default constructor called" << endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	cout << "Dog default destructor called" << endl;
	delete this->brain;
}

Dog::Dog(Dog &copy)
{
	cout << "Copy constructor called" << endl;
	*this = copy;
}

Dog &Dog::operator = (const Dog &copy)
{
	cout << "Copy assignment operator called" << endl;
	(void)copy;
	return (*this);
}

void Dog::makeSound() const
{
	cout << "intense barking noises..." << endl;
}