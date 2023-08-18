#include "Animal.hpp"

Animal::Animal()
{
	cout << "Animal default constructor called" << endl;
	this->type = "ditto";
}

Animal::~Animal()
{
	cout << "Animal default destructor called" << endl;
}

Animal::Animal(Animal &copy)
{
	cout << "Copy constructor called" << endl;
	*this = copy;
}

Animal &Animal::operator = (const Animal &copy)
{
	cout << "Copy assignment operator called" << endl;
	(void)copy;
	return (*this);
}

string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	cout << "inaudible ditto noises...." << endl;
}

WrongAnimal::WrongAnimal()
{
	cout << "WrongAnimal default constructor called" << endl;
	this->type = "ditto";
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal default destructor called" << endl;
}

string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	cout << "inaudible ditto noises...." << endl;
}